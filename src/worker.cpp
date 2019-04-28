/*!
 * @file	worker.cpp
 * @brief	 Implementação do header da classe Worker
 * @author	Filipe Medeiros
 * @date 28/04/2019
 */

#include <worker.h>

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

//!Construtores

/*! @details O construtor padrão é iniciado com valores defaults */

Worker::Worker()
    : id(0),
      function("Unemployed"),
      name(""),
      cpf("000.000.000-00"),
      age(0),
      bloodType("A"),
      factorRh('\0')

{
}

/*!
 * @details Este construtor recebe argumentos e atributi a classe Worker.
 *    @param id Identificador do funcionário.
 *    @param function Função do funcionário.
 *    @param name Nome do funcionário.
 *    @param cpf CPF do funcionário.
 *    @param age Idade do funcionário.
 *    @param bloodType Tipo sanguíneo do funcionário.
 *    @param factorRh Fator RH do funcionário.
 *    @param Specialty Especialidade do funcionário. 
 */

Worker::Worker(int id, string function,
               string name, string cpf, short int age,
               string bloodType, char factorRh, string Specialty)

    : id(this->id),
      function(this->function),
      name(this->name),
      cpf(this->cpf),
      age(this->age),
      bloodType(this->bloodType),
      factorRh(this->factorRh),
      Specialty(this->Specialty)

{
}

/*! @details	Construtor padrão da classe  Veterinary*/
Veterinary::Veterinary()
{
}

/*! @details	Construtor padrão da classe Caregiver*/
Caregiver::Caregiver()
{
}

//! Destrutores

/*! @details	Destrutor padrão da classe Worker*/
Worker::~Worker()
{
}

/*! @details	Destrutor padrão da classe Veterinary*/
Veterinary::~Veterinary()
{
}

/*! @details	Destrutor padrão da classe Caregiver*/
Caregiver::~Caregiver()
{
}

//! Metodos Getters

/*! @return Identificador do funcionário */
int Worker::getId()
{
    return id;
}

/*! @return a função do funcionário */
string Worker::getFunction()
{
    return function;
}

/*! @return Nome do funcionário */
string Worker::getName()
{
    return name;
}

/*! @return Nome do funcionário */
string Worker::getCpf()
{
    return cpf;
}

/*! @return a idade funcionário */
short int Worker::getAge()
{
    return age;
}

/*! @return o tipo do sangue do funcionário */
string Worker::getBloodType()
{
    return bloodType;
}

/*! @return o favor Rh do funcionário */
char Worker::getFactorRh()
{
    return factorRh;
}

/*! @return Especialidade do funcionário */
string Worker::getSpecialty()
{
    return Specialty;
}

//! Metodos Setters

/*! @param id Identificador do funcionário */
void Worker::setId(const int id)
{
    this->id = id;
}

/*!  @param function Função do funcionário. */
void Worker::setFunction(const string function)
{
    this->function = function;
}

/*!  @param name Nome do funcionário. */
void Worker::setName(const string name)
{
    this->name = name;
}

/*!  @param cpf CPF do funcionário. */
void Worker::setCpf(const string cpf)
{
    this->cpf = cpf;
}

/*!  @param age Idade do funcionário. */
void Worker::setAge(const short int age)
{
    this->age = age;
}

/*!  @param bloodType Tipo sanguíneo do funcionário. */
void Worker::setBloodType(const string bloodType)
{
    this->bloodType = bloodType;
}

/*!  @param factorRh Fator RH do funcionário. */
void Worker::setFactorRh(const char factorRh)
{
    this->factorRh = factorRh;
}

/*!  @param Specialty Especialidade do funcionário. */
void Worker::setSpecialty(const string Specialty)
{
    this->Specialty = Specialty;
}

/*!
 * @details	Sobrecarga do operador de impressão (<<)
 * @param 	os Output stream
 * @param 	Person  Objeto da classe Worker 
 */
ostream &operator<<(ostream &os, Worker &Person)
{

    os << "Identificador do funcionário: " << Person.id << endl;
    os << "Função: " << Person.function << endl;
    os << "Nome do funcionário: " << Person.name << endl;
    os << "CPF do funcionário: " << Person.cpf << endl;
    os << "Idade do funcionário: " << Person.age << endl;
    os << "Tipo Sanguíneo: " << Person.bloodType << endl;
    os << "Fator RH: " << Person.factorRh << endl;
    os << "Especialidade: " << Person.Specialty << endl;
    cout << endl;

    return os;
}