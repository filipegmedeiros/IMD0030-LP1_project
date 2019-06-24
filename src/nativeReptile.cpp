/*!
 *	@file	nativeReptile.cpp
 *	@brief	Implementação do header da classe nativeReptile
 *	@author	Filipe Medeiros
 *	@date	11/05/2019
 *	@since	11/05/2019
 */

#include "nativeReptile.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

//!Construtor

/*! @details O construtor padrão é iniciado com valores defaults */
nativeReptile::nativeReptile()
    : Reptile(0, "Reptil Nativo", "", '\0', 0.0, "", "", new Veterinary, new Caregiver, false, ""),
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
 *  @param  isItPoisonous   Venenoso ou não.
 *  @param  poisonType      Tipo do veneno.
 *  @param  ibamaAuth       Autorização do Ibama.
 *  @param  UFplace         Estado de Origem.
 */
nativeReptile::nativeReptile(int id, string animalClass, string scientificName,
                             char sex, double size, string diet, string baptismalName,
                             Veterinary *veterinary, Caregiver *caregiver, bool isItPoisonous, string poisonType, string ibamaAuth, string UFplace)

    : Reptile(id, animalClass, scientificName, sex, size,
              diet, baptismalName, veterinary, caregiver, isItPoisonous, poisonType),
      Native(ibamaAuth, UFplace)
{
}

//! Destrutor

/*!	@details	Destrutor padrão da classe Worker*/
nativeReptile::~nativeReptile()
{
}

std::istream &operator>>(std::istream &is, nativeReptile &Beast)
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
    //Beast.veterinary = Veterinary.getname();
    //getline(is, buff, ';');
    //Beast.caregiver = Caregiver.getname();
    //getline(is, buff, ';');
    Beast.isItPoisonous = atoi(buff.c_str());
    getline(is, buff, ';');
    Beast.poisonType = buff;
    getline(is, buff, ';');
    Beast.ibamaAuth = buff;
    getline(is, buff, ';');
    Beast.UFplace = buff;
    return is;
}

void nativeReptile::print(ostream &os) const
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
       << this->UFplace << ";" << endl;
}


/*!
 * @details	Sobrecarga do operador de impressão <<
 * @param 	os Output stream
 * @param   Animal Classe Animal
 */
ostream &operator<<(ostream &os, nativeReptile &Beast)
{
    Beast.print(os);
    return os;
}