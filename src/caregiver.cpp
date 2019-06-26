/*!
 *	@file	caregiver.cpp
 *	@brief	Implementação do header da classe Caregiver
 *	@author	Filipe Medeiros
 *	@date	02/05/2019
 *	@since	02/05/2019
 */

//! Includes and Usings

#include "caregiver.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

//!Construtor

/*! @details	O construtor padrão é iniciado com valores defaults */
Caregiver::Caregiver()
    : Worker()

{
  this->securityLevel = 0;
  this->specialty = "Caregiver";
}

/*!
 *	@details	Este construtor recebe argumentos e atributi a classe Caregiver.
 *
 *	@param	id			Identificador do funcionário.
 *	@param	function	Função do funcionário.
 *	@param	name		Nome do funcionário.
 *	@param	cpf			CPF do funcionário.
 *	@param	age			Idade do funcionário.
 *	@param	bloodType	Tipo sanguíneo do funcionário.
 *	@param	factorRh	Fator RH do funcionário.
 *	@param	Specialty	Especialidade do funcionário. 
 *	@param	securityLevel	????????????????
 */
Caregiver::Caregiver(int id, string function,
                     string name, string cpf, short int age,
                     string bloodType, char factorRh, string Specialty, int securityLevel)

    : Worker(id, function, name, cpf, age, bloodType,
             factorRh, Specialty),
      securityLevel(securityLevel)

{
}

//!Destrutor

/*!	@details	Destrutor padrão da classe Caregiver*/
Caregiver::~Caregiver()
{
}

//! Metodos Getters

/*!	@return	securityLevel */
int Caregiver::getSecurityLevel()
{
  return securityLevel;
}

//! Metodos Setters

/*!	@param	securityLevel	securityLevel */
void Caregiver::setSecurityLevel(int securityLevel)
{
  this->securityLevel = securityLevel;
}

void Caregiver::print()
{
  cout << securityLevel;
}
/*!
 * @details	Sobrecarga do operador de impressão >>
 * @param 	is input stream
 * @param   Person Classe Caregiver
 */
std::istream &operator>>(std::istream &is, Caregiver &Person)
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
  Person.securityLevel = atoi(buff.c_str());
  return is;
}

void Caregiver::print(ostream &os) const
{
  os << this->id << ";"
     << this->function << ";"
     << this->name << ";"
     << this->cpf << ";"
     << this->age << ";"
     << this->bloodType << ";"
     << this->factorRh << ";"
     << this->specialty << ";"
     << this->securityLevel << ";" << endl;
}

/*!
 * @details	Sobrecarga do operador de impressão <<
 * @param 	os Output stream
 * @param   Person Classe Veterinary
 */
ostream &operator<<(ostream &os, Caregiver &Person)
{
  Person.print(os);
  return os;
}