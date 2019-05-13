/*!
 *	@file	exoticAmphibian.cpp
 *	@brief	Implementação do header da classe exoticAmphibian
 *	@author	Sara
 *	@date	13/05/2019
 *	@since	13/05/2019
 */

#include "exoticAmphibian.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

//!Construtor

/*! @details O construtor padrão é iniciado com valores defaults */
exoticAmphibian::exoticAmphibian()
    : Amphibian(0, "Amphibian", "", '\0', 0.0, "", "", new Veterinary, new Caregiver, 0, ""),
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
 *  @param  totalSeed       Sementes totais.
 *  @param  lastSeed        Ultima semente.
 *  @param  ibamaAuth       Autorização do Ibama.
 *  @param  birthPlace      País de Origem.
 */
exoticAmphibian::exoticAmphibian(int id, string animalClass, string scientificName,
                       char sex, double size, string diet, string baptismalName,
                       Veterinary *veterinary, Caregiver *caregiver, int totalSeed, string lastSeed, string ibamaAuth, string birthPlace)

    : Amphibian(id, animalClass, scientificName, sex, size,
           diet, baptismalName, veterinary, caregiver, totalSeed, lastSeed),
      Exotic(ibamaAuth, birthPlace)
{
}

//! Destrutor

/*!	@details	Destrutor padrão da classe Worker*/
exoticAmphibian::~exoticAmphibian()
{
}

/*!
 * @details	Sobrecarga do operador de impressão <<
 * @param 	os Output stream
 * @param   Animal Classe Animal
 */
ostream &operator<<(ostream &os, exoticAmphibian &animal)
{
    return os;
}