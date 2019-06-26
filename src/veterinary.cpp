/*!
 *	@file		veterinary.cpp
 *	@brief	Implementação do header da classe Veterinary
 *	@author	Filipe Medeiros
 *	@date		02/05/2019
 *	@since	02/05/2019
 */

//! Includes and Usings

#include "veterinary.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

//!Construtor

/*! @details O construtor padrão é iniciado com valores defaults */
Veterinary::Veterinary()
    : Worker()

{
  this->crmv = "crmv";
  this->specialty = "Veterinary";
}

/*!
 *	@details	Este construtor recebe argumentos e atributi a classe Veterinary.
 *
 *	@param	id			Identificador do funcionário.
 *	@param	function	Função do funcionário.
 *	@param	name		Nome do funcionário.
 *	@param	cpf			CPF do funcionário.
 *	@param	age			Idade do funcionário.
 *	@param	bloodType	Tipo sanguíneo do funcionário.
 *	@param	factorRh	Fator RH do funcionário.
 *	@param	specialty	Especialidade do funcionário. 
 *  @param  crmv      Número de Identificação CRMV.
 */
Veterinary::Veterinary(int id, string function,
                       string name, string cpf, short int age,
                       string bloodType, char factorRh, string specialty, string crmv)

    : Worker(id, function, name, cpf, age, bloodType,
             factorRh, specialty),
      crmv(crmv)

{
}

//!Destrutor

/*!	@details	Destrutor padrão da classe Veterinary*/
Veterinary::~Veterinary()
{
}

//! Metodos Getters

/*!	@return	Identificador do CRMV */
string Veterinary::getCrmv()
{
  return crmv;
}

//! Metodos Setters

/*!	@param	crmv		 Número de Identificação CRMV */
void Veterinary::setCrmv(string crmv)
{
  this->crmv = crmv;
}

void Veterinary::print()
{
  cout << crmv;
}

/*!
 * @details	Sobrecarga do operador de impressão >>
 * @param 	is input stream
 * @param   Person Classe Veterinary
 */

std::istream &operator>>(std::istream &is, Veterinary &Person)
{
  string buff;
  getline(is, buff, ';');
  Person.id = atoi(buff.c_str());
  getline(is, buff, ';');
  Person.function = buff;
  getline(is, buff, ';');
  Person.name = buff;
  getline(is, buff, ';');
  Person.cpf = buff;
  getline(is, buff, ';');
  Person.age = atoi(buff.c_str());
  getline(is, buff, ';');
  Person.bloodType = buff;
  getline(is, buff, ';');
  Person.factorRh = buff[0];
  getline(is, buff);
  Person.specialty = buff;
  getline(is, buff);
  return is;
}

void Veterinary::print(ostream &os) const
{
  os << this->id << ";"
     << this->function << ";"
     << this->name << ";"
     << this->cpf << ";"
     << this->age << ";"
     << this->bloodType << ";"
     << this->factorRh << ";"
     << this->specialty << ";"
     << this->crmv << ";" << endl;
}

/*!
 * @details	Sobrecarga do operador de impressão <<
 * @param 	os Output stream
 * @param   Person Classe Veterinary
 */
ostream &operator<<(ostream &os, Veterinary &Person)
{
  Person.print(os);
  return os;
}