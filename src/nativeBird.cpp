/*!
 *	@file	nativeBird.cpp
 *	@brief	Implementação do header da classe nativeBird
 *	@author	Filipe Medeiros
 *	@date	16/05/2019
 *	@since	16/05/2019
 */

#include "nativeBird.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

//!Construtor

/*! @details O construtor padrão é iniciado com valores defaults */
nativeBird::nativeBird()
    : Bird(0, "Ave Nativo", "", '\0', 0.0, "", "", new Veterinary, new Caregiver, 0, 0),
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
 *  @param  beakSize        Tamanho do Bico.
 *  @param  handleSpan      Tamanho da Enveradura.
 *  @param  ibamaAuth       Autorização do Ibama.
 *  @param  UFplace      País de Origem.
 */
nativeBird::nativeBird(int id, string animalClass, string scientificName,
                       char sex, double size, string diet, string baptismalName,
                       Veterinary *veterinary, Caregiver *caregiver, double beakSize, double handleSpan, string ibamaAuth, string UFplace)

    : Bird(id, animalClass, scientificName, sex, size,
           diet, baptismalName, veterinary, caregiver, beakSize, handleSpan),
      Native(ibamaAuth, UFplace)
{
}

//! Destrutor

/*!	@details	Destrutor padrão da classe Worker*/
nativeBird::~nativeBird()
{
}

std::istream &operator>>(std::istream &is, nativeBird &Beast)
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
    Beast.beakSize = atof(buff.c_str());
    getline(is, buff, ';');
    Beast.handleSpan = atof(buff.c_str());
    getline(is, buff, ';');
    Beast.ibamaAuth = buff;
    getline(is, buff, ';');
    Beast.UFplace = buff;
    return is;
}

void nativeBird::print(ostream &os) const
{
    os << this->id << ";"
       << this->animalClass << ";"
       << this->scientificName << ";"
       << this->sex << ";"
       << this->size << ";"
       << this->diet << ";"
       << this->baptismalName << ";"
       << this->veterinary->getName() << ";"
       << this->caregiver->getName() << ";"
       << this->beakSize << ";"
       << this->handleSpan << ";"
       << this->ibamaAuth << ";"
       << this->UFplace << ";" << endl;
}

/*!
 * @details	Sobrecarga do operador de impressão <<
 * @param 	os Output stream
 * @param   Animal Classe Animal
 */
ostream &operator<<(ostream &os, nativeBird &Beast)
{
    Beast.print(os);
    return os;
}