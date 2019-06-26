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
    : Reptile(0, "Reptil Exótico", "", '\0', 0.0, "", "", new Veterinary, new Caregiver, false, ""),
      Exotic("","")

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
                             Veterinary *veterinary, Caregiver *caregiver, bool isItPoisonous, string poisonType,string ibamaAuth, string birthPlace)

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

std::istream &operator>>(std::istream &is, exoticReptile &Beast)
{
    string buff;
    getline(is, buff, ';');
    Beast.id = atoi(buff.c_str());
    getline(is, buff, ';');
    Beast.animalClass = buff;
    getline(is, buff, ';');
    Beast.scientificName = buff;
    getline(is, buff, ';');
    Beast.sex = buff[0];
    getline(is, buff, ';');
    Beast.size = atof(buff.c_str());
    getline(is, buff, ';');
    Beast.diet = buff;
    getline(is, buff, ';');
    Beast.baptismalName = buff;
    getline(is, buff, ';');
    Beast.getVeterinary()->getName();
    getline(is, buff, ';');
    Beast.getCaregiver()->getName();
    getline(is, buff, ';');
    Beast.isItPoisonous = atoi(buff.c_str());
    getline(is, buff, ';');
    Beast.poisonType = buff;
    getline(is, buff, ';');
    Beast.ibamaAuth = buff;
    getline(is, buff, ';');
    Beast.birthPlace = buff;
    return is;
}

void exoticReptile::print(ostream &os) const
{
    os << this->id << ";"
       << this->animalClass << ";"
       << this->scientificName << ";"
       << this->sex << ";"
       << this->size << ";"
       << this->diet << ";"
       << this->baptismalName << ";"
       << this->veterinary << ";"
       << this->caregiver << ";"
       << this->isItPoisonous << ";"
       << this->poisonType << ";"
       << this->ibamaAuth << ";"
       << this->birthPlace << ";" << endl;
}


/*!
 * @details	Sobrecarga do operador de impressão <<
 * @param 	os Output stream
 * @param   Animal Classe Animal
 */
ostream &operator<<(ostream &os, exoticReptile &Beast)
{
    Beast.print(os);
    return os;
}