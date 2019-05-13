#ifndef __WILD__H__
#define __WILD__H__

/*!
 *	@file	wild.h
 *	@brief	Classe Wild
 *	@author	Filipe Medeiros
 *	@date	13/05/2019
 *	@since	13/05/2019
 */

//! Includes and Usings

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

/*!
 *	@class		Wild wild.h
 *	@brief		Class Wild
 *	@details	Definição da classe Wild
 */

class Wild
{
protected:
    virtual void printIbama(ostream &);
    string ibamaAuth;

public:
    //! Construtor e Destrutor

    Wild();
    Wild(string);
    ~Wild();

    //! Metodos Getters

    string getIbamaAuth();

    //! Metodos Setters

    void setIbamaAuth(string);
};

#endif