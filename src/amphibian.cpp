/*!
 *	@file	amphibian.cpp
 *	@brief	Implementação do header da classe Amphibian
 *	@author	Filipe Medeiros
 *	@date	11/05/2019
 *	@since	11/05/2019
 */

#include "amphibian.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

//!Construtor

/*! @details O construtor padrão é iniciado com valores defaults */
Amphibian::Amphibian()
    : Animal(0, "Anfibio", "", '\0', 0.0, "", "", new Veterinary, new Caregiver)

{
    this->totalSeed = 0;
    this->lastSeed = "";
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
 *  @param  totalSeed       Número de mudas da pele.
 *  @param  lastSeed        Ultima muda.
 */
Amphibian::Amphibian(int id, string animalClass, string scientificName,
                     char sex, double size, string diet, string baptismalName,
                     Veterinary *veterinary, Caregiver *caregiver, int totalSeed, string lastSeed)

    : Animal(id, animalClass, scientificName, sex, size,
             diet, baptismalName, veterinary, caregiver),
      totalSeed(totalSeed),
      lastSeed(lastSeed)
{
}

//! Destrutor

/*!	@details	Destrutor padrão da classe Worker*/
Amphibian::~Amphibian()
{
}

//! Metodos Getters

/*!	@return		Nome  do Animal */
int Amphibian::getTotalSeed()
{
    return totalSeed;
}

/*!	@return		Nome  do Animal */
string Amphibian::getLastSeed()
{
    return lastSeed;
}

//! Metodos Setters

/*!	@param	totalSeed		 */
void Amphibian::setTotalSeed(int totalSeed)
{
    this->totalSeed = totalSeed;
}

/*!	@param	lastSeed		 */
void Amphibian::setLastSeed(string lastSeed)
{
    this->lastSeed = lastSeed;
}

/*!
 * @details	Função Print sobrecarregada da print Animal.
 * dessa forma, conseguimos passar um stream de saida com as informações bases para a filha.
 * @param 	os Output stream
 */
void Amphibian::print(ostream &os)
{
    Animal::print(os);
    os << "Número de mudas da pele: " << this->totalSeed << endl;
    os << "Última Muda: " << this->lastSeed << endl;
}