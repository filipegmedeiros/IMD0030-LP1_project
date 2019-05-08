/*!
 *	@file	worker.cpp
 *	@brief	Implementação do header da classe worker
 *	@author	Filipe Medeiros
 *	@date	02/05/2019
 *	@since	28/04/2019
 */

//! Includes and Usings

#include <worker.h>

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

//!Construtor

/*!	@details	O construtor padrão é iniciado com valores defaults */
Worker::Worker()
    : id(0),
      function("Unemployed"),
      name(""),
      cpf("000.000.000-00"),
      age(0),
      bloodType(""),
      factorRh('\0')

{
}

/*!
 *	@details	Este construtor recebe argumentos e atributi a classe Worker.
 *
 *	@param	id			Identificador do funcionário.
 *	@param	function	Função do funcionário.
 *	@param	name		Nome do funcionário.
 *	@param	cpf			CPF do funcionário.
 *	@param	age			Idade do funcionário.
 *	@param	bloodType	Tipo sanguíneo do funcionário.
 *	@param	factorRh	Fator RH do funcionário.
 *	@param	Specialty	Especialidade do funcionário. 
 */
Worker::Worker(int id, string function,
               string name, string cpf, short int age,
               string bloodType, char factorRh, string specialty)

    : id(id),
      function(function),
      name(name),
      cpf(cpf),
      age(age),
      bloodType(bloodType),
      factorRh(factorRh),
      specialty(specialty)

{
}

//! Destrutor

/*!	@details	Destrutor padrão da classe Worker*/
Worker::~Worker()
{
}

//! Metodos Getters

/*!	@return	Identificador do funcionário */
int Worker::getId()
{
    return id;
}

/*!	@return	a função do funcionário */
string Worker::getFunction()
{
    return function;
}

/*!	@return	Nome do funcionário */
string Worker::getName()
{
    return name;
}

/*!	@return	Nome do funcionário */
string Worker::getCpf()
{
    return cpf;
}

/*!	@return	a idade funcionário */
short int Worker::getAge()
{
    return age;
}

/*!	@return	o tipo do sangue do funcionário */
string Worker::getBloodType()
{
    return bloodType;
}

/*!	@return	o favor Rh do funcionário */
char Worker::getFactorRh()
{
    return factorRh;
}

/*!	@return	Especialidade do funcionário */
string Worker::getSpecialty()
{
    return specialty;
}

//! Metodos Setters

/*!	@param	id		Identificador do funcionário */
void Worker::setId(const int id)
{
    this->id = id;
}

/*!	@param	function	Função do funcionário. */
void Worker::setFunction(const string function)
{
    this->function = function;
}

/*!	@param	name	Nome do funcionário. */
void Worker::setName(const string name)
{
    this->name = name;
}

/*!	@param	cpf		CPF do funcionário. */
void Worker::setCpf(const string cpf)
{
    this->cpf = cpf;
}

/*!	@param	age		Idade do funcionário. */
void Worker::setAge(const short int age)
{
    this->age = age;
}

/*!	@param	bloodType	Tipo sanguíneo do funcionário. */
void Worker::setBloodType(const string bloodType)
{
    this->bloodType = bloodType;
}

/*!	@param	factorRh	Fator RH do funcionário. */
void Worker::setFactorRh(const char factorRh)
{
    this->factorRh = factorRh;
}

/*!	@param	Specialty	Especialidade do funcionário. */
void Worker::setSpecialty(const string Specialty)
{
    this->specialty = Specialty;
}

/*!
 * @details	Função Print para fazer evitar o problema da sobrecarga não ser herdavel.
 * dessa forma, conseguimos passar um stream de saida com as informações bases para a filha.
 * @param 	os Output stream
 */
void Worker::print(ostream &os)
{
    os << "Identificador do funcionário: " << this->id << endl;
    os << "Função: " << this->function << endl;
    os << "Nome do funcionário: " << this->name << endl;
    os << "CPF do funcionário: " << this->cpf << endl;
    os << "Idade do funcionário: " << this->age << endl;
    os << "Tipo Sanguíneo: " << this->bloodType << endl;
    os << "Fator RH: " << this->factorRh << endl;
    os << "Especialidade: " << this->specialty << endl;
}

/*!
 * @details	Sobrecarga do operador de impressão <<
 * @param 	os Output stream
 * @param   Person Classe Veterinary
 */
ostream &operator<<(ostream &os, Worker &Person)
{
    Person.print(os);
    return os;
}