/*!
 *	@file	native.cpp
 *	@brief	Implementação do header da classe native
 *	@author	Filipe Medeiros
 *	@date	16/05/2019
 *	@since	16/05/2019
 */

#include "native.h"

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
 *	@param	UFplace				Estado de Origem.
 */
Native::Native(string ibamaAuth, string UFplace)
    : Wild(ibamaAuth),
      UFplace(UFplace)
{
}

//! Destrutor

/*!	@details	Destrutor padrão da classe Worker*/
Native::~Native()
{
}

//! Metodos Getters

/*!	@return		Estado de Nascimento*/
string Native::getUFplace()
{
    return UFplace;
}

//! Metodos Setters

/*!	@param	UFplace		 */
void Native::setUFplace(string UFplace)
{
    this->UFplace = UFplace;
}

/*!
 * @details	Função Print para fazer evitar o problema da sobrecarga não ser herdavel.
 * dessa forma, conseguimos passar um stream de saida com as informações bases para a filha.
 * @param 	os Output stream
 */
void Native::printWild(ostream &os)
{
    Wild::printWild(os);
    os << "Estado de Origem: " << this->UFplace << endl;
}