/*!
 *	@file	bird.cpp
 *	@brief	Implementação do header da classe Bird
 *	@author	Filipe Medeiros
 *	@date	11/05/2019
 *	@since	11/05/2019
 */

#include "bird.h"

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
 *  @param  beakSize        Tamanho do Bico.
 *  @param  handleSpan      Tamanho da Enveradura.
 */
Bird::Bird(int id, string animalClass, string scientificName,
           char sex, double size, string diet, string baptismalName,
           Veterinary *veterinary, Caregiver *caregiver, double beakSize, double handleSpan)

    : Animal(id, animalClass, scientificName, sex, size,
             diet, baptismalName, veterinary, caregiver),
      beakSize(beakSize),
      handleSpan(handleSpan)
{
}

//! Destrutor

/*!	@details	Destrutor padrão da classe Worker*/
Bird::~Bird()
{
}

//! Metodos Getters

/*!	@return		Nome  do Animal */
double Bird::getBeakSize()
{
    return beakSize;
}

/*!	@return		Nome  do Animal */
double Bird::getHandleSpan()
{
    return handleSpan;
}

//! Metodos Setters

/*!	@param	beakSize		 */
void Bird::setBeakSize(double beakSize)
{
    this->beakSize = beakSize;
}

/*!	@param	handleSpan		 */
void Bird::setHandleSpan(double handleSpan)
{
    this->handleSpan = handleSpan;
}
