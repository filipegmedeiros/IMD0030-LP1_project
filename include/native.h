#ifndef __NATIVE_H__
#define __NATIVE_H__

/*!
 *	@file	native.h
 *	@brief	Classe Exotic
 *	@author	Filipe Medeiros
 *	@date	02/05/2019
 *	@since	02/05/2019
 */

//! Includes and Usings
#include "wild.h"

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

class Native : public Wild
{
protected:
    string UFplace;

public:
    //! Construtor e Destrutor

    Native();
    Native(string, string);
    ~Native();

    //! Metodos Getters

    string getUFplace();

    //! Metodos Setters

    void setUFplace(string);

    void printWild(ostream &);
};

#endif