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
    : Amphibian(0, "Anfibio Exótico", "", '\0', 0.0, "", "", new Veterinary, new Caregiver, 0, ""),
      Exotic("", "")

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
 * @details	Sobrecarga do operador de impressão >>
 * @param 	is input stream
 * @param   Animal Classe exoticAmphibian
 */
std::istream &operator>>(std::istream &is, exoticAmphibian &Beast)
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
    Beast.totalSeed = atoi(buff.c_str());
    getline(is, buff, ';');
    Beast.lastSeed = buff;
    getline(is, buff, ';');
    Beast.ibamaAuth = buff;
    getline(is, buff, ';');
    Beast.birthPlace = buff;
    return is;
}

void exoticAmphibian::print(ostream &os) const
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
       << this->totalSeed << ";"
       << this->lastSeed << ";"
       << this->ibamaAuth << ";"
       << this->birthPlace << ";" << endl;
}

/*!
 * @details Sobrecarga do operador de impressão <<
 * @param os Output stream
 * @param Animal Classe exoticAmphibian
 */
ostream &operator<<(ostream &os, exoticAmphibian &Beast)
{
    Beast.print(os);
    return os;
}