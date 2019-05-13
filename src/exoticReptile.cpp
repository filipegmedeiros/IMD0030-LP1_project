/*!
 *	@file	exoticReptile.cpp
 *	@brief	Implementação do header da classe exoticReptile
 *	@author	Filipe Medeiros
 *	@date	11/05/2019
 *	@since	11/05/2019
 */

#include "exoticReptile.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

//!Construtor

/*! @details O construtor padrão é iniciado com valores defaults */
exoticReptile::exoticReptile()
    : Reptile(0, "Ave", "", '\0', 0.0, "", "", new Veterinary, new Caregiver, false, ""),
      Exotic("")

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
 *  @param  isItPoisonous   Venenoso ou não.
 *  @param  poisonType      Tipo do veneno.
 *  @param  ibamaAuth       Autorização do Ibama.
 *  @param  birthPlace      País de Origem.
 */
exoticReptile::exoticReptile(int id, string animalClass, string scientificName,
                       char sex, double size, string diet, string baptismalName,
                       Veterinary *veterinary, Caregiver *caregiver, bool isItPoisonous, string poisonType, string birthPlace)

    : Reptile(id, animalClass, scientificName, sex, size,
           diet, baptismalName, veterinary, caregiver, isItPoisonous, poisonType),
      Exotic(ibamaAuth, birthPlace)
{
}

//! Destrutor

/*!	@details	Destrutor padrão da classe Worker*/
exoticReptile::~exoticReptile()
{
}

/*!
 * @details	Sobrecarga do operador de impressão <<
 * @param 	os Output stream
 * @param   Animal Classe Animal
 */
ostream &operator<<(ostream &os, exoticReptile &animal)
{
    return os;
}