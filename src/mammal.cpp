/*!
 *	@file	mammal.cpp
 *	@brief	Implementação do corpo da classe Mammal
 *	@author	Sara Santana
 *	@date	13/05/2019
 *	@since	13/05/2019
 */

#include "mammal.h"

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
 *  @param  furColor        Cor do pelo.
 */
Mammal::Mammal(int id, string animalClass, string scientificName,
               char sex, double size, string diet, string baptismalName,
               Veterinary *veterinary, Caregiver *caregiver, string furColor)

    : Animal(id, animalClass, scientificName, sex, size,
             diet, baptismalName, veterinary, caregiver),
      furColor(furColor)
{
}

//! Destrutor

/*!	@details	Destrutor padrão da classe Worker*/
Mammal::~Mammal()
{
}

//! Metodos Getters

/*!	@return FurColor */
string Mammal::getFurColor()
{
    return furColor;
}

//! Metodos Setters

/*!	@param	furColor	*/
void Mammal::setFurColor(string furColor)
{
    this->furColor = furColor;
}

/*!
 * @details	Função Print sobrecarregada da print Animal.
 * dessa forma, conseguimos passar um stream de saida com as informações bases para a filha.
 * @param 	os Output stream
 */
/*
void Mammal::print(ostream &os)
{
    Animal::print(os);
    os << "Cor do Pelo: " << this->furColor << endl;
}
 */