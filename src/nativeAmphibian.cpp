/*!
 *	@file	nativeAmphibian.cpp
 *	@brief	Implementação do header da classe nativeAmphibian
 *	@author	Filipe Medeiros
 *	@date	16/05/2019
 *	@since	16/05/2019
 */

#include "nativeAmphibian.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

//!Construtor

/*! @details O construtor padrão é iniciado com valores defaults */
nativeAmphibian::nativeAmphibian()
    : Amphibian(0, "Anfibio Nativo", "", '\0', 0.0, "", "", new Veterinary, new Caregiver, 0, ""),
      Native("", "")

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
 *  @param  UFplace      País de Origem.
 */
nativeAmphibian::nativeAmphibian(int id, string animalClass, string scientificName,
                                 char sex, double size, string diet, string baptismalName,
                                 Veterinary *veterinary, Caregiver *caregiver, int totalSeed, string lastSeed, string ibamaAuth, string UFplace)

    : Amphibian(id, animalClass, scientificName, sex, size,
                diet, baptismalName, veterinary, caregiver, totalSeed, lastSeed),
      Native(ibamaAuth, UFplace)
{
}

//! Destrutor

/*!	@details	Destrutor padrão da classe Worker*/
nativeAmphibian::~nativeAmphibian()
{
}

/*!
 * @details	Sobrecarga do operador de impressão <<
 * @param 	os Output stream
 * @param   Animal Classe Animal
 */
ostream &operator<<(ostream &os, nativeAmphibian &animal)
{
    animal.print(os);
    animal.printWild(os);
    return os;
}