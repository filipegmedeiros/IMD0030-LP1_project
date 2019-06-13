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
 * @details	Sobrecarga do operador de impressão <<
 * @param 	os Output stream
 * @param   Person Classe Caregiver
 */

ostream &operator<<(ostream &os, Caregiver &care)
{
  care.print(os);
  return os;
}