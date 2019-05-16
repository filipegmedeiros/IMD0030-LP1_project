/*!
 *	@file	Wild.cpp
 *	@brief	Implementação do header da classe Wild
 *	@author	Filipe Medeiros
 *	@date	13/05/2019
 *	@since	13/05/2019
 */

#include "exotic.h"

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
 *	@param	birthPlace				Local de Origem.
 */
Exotic::Exotic(string ibamaAuth, string birthPlace)
    : Wild(ibamaAuth),
      birthPlace(birthPlace)
{
}

//! Destrutor

/*!	@details	Destrutor padrão da classe Worker*/
Exotic::~Exotic()
{
}

//! Metodos Getters

/*!	@return		Local de Nascimento*/
string Exotic::getBirthPlace()
{
    return birthPlace;
}

//! Metodos Setters

/*!	@param	birthPlace		 */
void Exotic::setBirthPlace(string birthPlace)
{
    this->birthPlace = birthPlace;
}

/*!
 * @details	Função Print para fazer evitar o problema da sobrecarga não ser herdavel.
 * dessa forma, conseguimos passar um stream de saida com as informações bases para a filha.
 * @param 	os Output stream
 */
void Exotic::printWild(ostream &os)
{
    Wild::printWild(os);
    os << "Local de Origem: " << this->birthPlace << endl;
}