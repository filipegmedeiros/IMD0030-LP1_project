#ifndef __EXOTIC_H__
#define __EXOTIC_H__

/*!
 *	@file		exotic.h
 *	@brief		Classe Exotic
 *	@author		Filipe Medeiros
 *	@date		02/05/2019
 *	@since		02/05/2019
 */

//! Includes and Usings
#include "wild.h"
#include "bird.h"

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

class Exotic : public Wild
{
protected:
    string birthPlace;

public:
    //! Construtor e Destrutor

    Exotic();
    Exotic(string, string);
    ~Exotic();

    //! Metodos Getters

    string getBirthPlace();

    //! Metodos Setters

    void setBirthPlace(string);

    void printWild(ostream &);
};

#endif