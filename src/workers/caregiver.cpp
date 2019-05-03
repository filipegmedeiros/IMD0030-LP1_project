/*!
 *	@file	caregiver.cpp
 *	@brief	Implementação do header da classe Caregiver
 *	@author	Filipe Medeiros
 *	@date	02/05/2019
 *	@since	02/05/2019
 */

//! Includes and Usings

#include <caregiver.h>

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

//!Construtor

/*! @details	O construtor padrão é iniciado com valores defaults */

Caregiver::Caregiver()
	: Worker(0, "Unemployed", "", "000.000.000-00", 0, "A", '\0', "")

{
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
 */

Caregiver::Caregiver(int id, string function,
					 string name, string cpf, short int age,
					 string bloodType, char factorRh, string Specialty)

	: Worker(this->id, this->function, this->name, this->cpf, this->age, this->bloodType,
			 this->factorRh, this->Specialty)

{
}

//!Destrutor
Caregiver::~Caregiver()
{
}

ostream &operator<<(ostream &os, Caregiver &Person)
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