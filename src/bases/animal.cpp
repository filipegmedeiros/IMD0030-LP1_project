/*!
 *	@file	animal.cpp
 *	@brief	Implementação do header da classe animal
 *	@author	Filipe Medeiros
 *	@date	02/05/2019
 *	@since	02/05/2019
 */

#include <animal.h>

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
 */

Animal::Animal(int id, string animalClass, string scientificName,
               char sex, double size, string diet, string baptismalName,
               Veterinary *veterinary, Caregiver *caregiver)

    : id(this->id),
      animalClass(this->animalClass),
      scientificName(this->scientificName),
      sex(this->sex),
      size(this->size),
      diet(this->diet),
      baptismalName(this->baptismalName),
      veterinary(this->veterinary),
      caregiver(this->caregiver)
{
}

//! Destrutor

/*!	@details	Destrutor padrão da classe Worker*/
Animal::~Animal()
{
}

//! Metodos Getters

/*!	@return		Identificador do Animal */
int Animal::getId()
{
    return id;
}

/*!	@return		a classe que o Animal pertence */
string Animal::getAnimalClass()
{
    return animalClass;
}

/*!	@return		Nome Cientifico do Animal */
string Animal::getScientificName()
{
    return scientificName;
}

/*!	@return		Sexo do Animal */
char Animal::getSex()
{
    return sex;
}

/*!	@return		o tamanho do Animal */
double Animal::getSize()
{
    return size;
}

/*!	@return		o tipo de dieta do Animal */
string Animal::getDiet()
{
    return diet;
}

/*!	@return		Nome  do Animal */
string Animal::getBaptismalName()
{
    return baptismalName;
}

/*!	@return		Veterinary associado ao animal */
Veterinary *Animal::getVeterinary()
{
    return veterinary;
}

/*!	@return		Caregiver associado ao animal */
Caregiver *Animal::getCaregiver()
{
    return caregiver;
}

//! Metodos Setters

/*!	@param	id		Identificador do Animal */
void Animal::setId(int id)
{
    this->id = id;
}

/*!	@param	animalClass		a classe que o Animal pertence */
void Animal::setAnimalClass(string animalClass)
{
    this->animalClass = animalClass;
}

/*!	@param	sex		Sexo do Animal */
void Animal::setSex(char sex)
{
    this->sex = sex;
}

/*!	@param	size		o tamanho do Animal */
void Animal::setSize(double size)
{
    this->size = size;
}

/*!	@param	diet		o tipo de dieta do Animal */
void Animal::setDiet(string diet)
{
    this->diet = diet;
}

/*!	@param	baptismalName		do Animal */
void Animal::setBaptismalName(string baptismalName)
{
    this->baptismalName = baptismalName;
}

/*!	@param	veterinary		associado ao animal */
void Animal::setVeterinary(Veterinary *veterinary)
{
    this->veterinary = veterinary;
}

/*!	@param	caregiver		associado ao animal */
void Animal::setCaregiver(Caregiver *caregiver)
{
    this->caregiver = caregiver;
}