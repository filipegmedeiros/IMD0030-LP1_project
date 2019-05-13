/*!
 *	@file	reptile.cpp
 *	@brief	Implementação do corpo da classe Reptile
 *	@author	Sara Santana
 *	@date	13/05/2019
 *	@since	13/05/2019
 */

#include "reptile.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

//!Construtor

/*!
 *	@details	Este construtor recebe argumentos e atributi a classe Animal.
 *
 *	@param	id				Identificador do animal.
 *	@param	animalClass		Classe do animal.
 *	@param 	scientificName	Nome científico do animal.
 *	@param	sex				Sexo do animal.
 *	@param	size			Tamanho do animal.
 *	@param	diet			Dieta do animal.
 *	@param	baptismalName	Nome do animal.
 *	@param	Veterinary		Veterinário do animal.
 *	@param	Caregiver		Tratador do animal.
 *  @param  isItPoisonous   Venonoso ou não.
 *  @param  poisonType      Tipo do veneno.
 */
Reptile::Reptile(int id, string animalClass, string scientificName,
           char sex, double size, string diet, string baptismalName,
           Veterinary *veterinary, Caregiver *caregiver, bool isItPoisonous, string poisonType)

    : Animal(id, animalClass, scientificName, sex, size,
             diet, baptismalName, veterinary, caregiver),
      isItPoisonous(isItPoisonous),
      poisonType(poisonType)
{
}

//! Destrutor

/*!	@details	Destrutor padrão da classe Worker*/
Reptile::~Reptile()
{
}

//! Metodos Getters

/*!	@return	isItPoisonous */
bool Reptile::getIsItPoisonous()
{
    return isItPoisonous;
}

/*!	@return PoisonType */
string Reptile::getPoisonType()
{
    return poisonType;
}

//! Metodos Setters

/*!	@param	isItPoisonous	*/
void Reptile::setIsItPoisonous(bool isItPoisonous)
{
    this->isItPoisonous = isItPoisonous;
}

/*!	@param	poisonType	*/
void Reptile::setPoisonType (string poisonType)
{
    this->poisonType = poisonType;
}
