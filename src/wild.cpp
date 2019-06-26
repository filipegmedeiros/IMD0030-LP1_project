/*!
 *	@file	Wild.cpp
 *	@brief	Implementação do header da classe Wild
 *	@author	Filipe Medeiros
 *	@date	13/05/2019
 *	@since	13/05/2019
 */

#include "wild.h"

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
 *	@param	ibamaAuth				Autorização do Ibama.
 */
Wild::Wild(string ibamaAuth)
    : ibamaAuth(ibamaAuth)
{
}

//! Destrutor

/*!	@details	Destrutor padrão da classe Worker*/
Wild::~Wild()
{
}

//! Metodos Getters

/*!	@return		Autorização do Ibama*/
string Wild::getIbamaAuth()
{
    return ibamaAuth;
}

//! Metodos Setters

/*!	@param	IbamaAuth		 */
void Wild::setIbamaAuth(string ibamaAuth)
{
    this->ibamaAuth = ibamaAuth;
}

/*!
 * @details	Função Print para fazer evitar o problema da sobrecarga não ser herdavel.
 * dessa forma, conseguimos passar um stream de saida com as informações bases para a filha.
 * @param 	os Output stream
 */
void Wild::printWild(ostream &os)
{
    os << "Autorização do Ibama: " << this->ibamaAuth << endl;
}