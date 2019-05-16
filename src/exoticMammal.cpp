/*!
 *	@file	exoticMammal.cpp
 *	@brief	Implementação do header da classe exoticMammal
 *	@author	Sara 
 *	@date	13/05/2019
 *	@since	13/05/2019
 */

#include "exoticMammal.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

//!Construtor

/*! @details O construtor padrão é iniciado com valores defaults */
exoticMammal::exoticMammal()
    : Mammal(0, "Mamifero Exótico", "", '\0', 0.0, "", "", new Veterinary, new Caregiver, ""),
      Exotic("", "")

{
}

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
 *  @param  furColor     Cor do pelo.
 *  @param  ibamaAuth       Autorização do Ibama.
 *  @param  birthPlace      País de Origem.
 */
exoticMammal::exoticMammal(int id, string animalClass, string scientificName,
                           char sex, double size, string diet, string baptismalName,
                           Veterinary *veterinary, Caregiver *caregiver, string furColor, string ibamaAuth, string birthPlace)

    : Mammal(id, animalClass, scientificName, sex, size,
             diet, baptismalName, veterinary, caregiver, furColor),
      Exotic(ibamaAuth, birthPlace)
{
}

//! Destrutor

/*!	@details	Destrutor padrão da classe Worker*/
exoticMammal::~exoticMammal()
{
}

/*!
 * @details	Sobrecarga do operador de impressão <<
 * @param 	os Output stream
 * @param   Animal Classe Animal
 */
ostream &operator<<(ostream &os, exoticMammal &animal)
{
    animal.print(os);
    animal.printWild(os);
    return os;
}