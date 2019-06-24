/*!
 *	@file	nativeMammal.cpp
 *	@brief	Implementação do header da classe nativeMammal
 *	@author	Filipe Medeiros 
 *	@date	16/05/2019
 *	@since	16/05/2019
 */

#include "nativeMammal.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

//!Construtor

/*! @details O construtor padrão é iniciado com valores defaults */
nativeMammal::nativeMammal()
    : Mammal(0, "Mamifero Nativo", "", '\0', 0.0, "", "", new Veterinary, new Caregiver, ""),
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
 *  @param  furColor        Cor do pelo.
 *  @param  ibamaAuth       Autorização do Ibama.
 *  @param  UFplace         Estado de Origem.
 */
nativeMammal::nativeMammal(int id, string animalClass, string scientificName,
                           char sex, double size, string diet, string baptismalName,
                           Veterinary *veterinary, Caregiver *caregiver, string furColor, string ibamaAuth, string UFplace)

    : Mammal(id, animalClass, scientificName, sex, size,
             diet, baptismalName, veterinary, caregiver, furColor),
      Native(ibamaAuth, UFplace)
{
}

//! Destrutor

/*!	@details	Destrutor padrão da classe Worker*/
nativeMammal::~nativeMammal()
{
}

std::istream &operator>>(std::istream &is, nativeMammal &Beast)
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
    Beast.furColor= buff;
    getline(is, buff, ';');
    Beast.ibamaAuth = buff;
    getline(is, buff, ';');
    Beast.UFplace = buff;
    return is;
}

void nativeMammal::print(ostream &os) const
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
       << this->furColor << ";"
       << this->ibamaAuth << ";"
       << this->UFplace << ";" << endl;
}

/*!
 * @details	Sobrecarga do operador de impressão <<
 * @param 	os Output stream
 * @param   Animal Classe Animal
 */
ostream &operator<<(ostream &os, nativeMammal &Beast)
{
    Beast.print(os);
    return os;
}