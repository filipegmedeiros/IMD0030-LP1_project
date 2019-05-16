#ifndef __NATIVEBIRD_H__
#define __NATIVEBIRD_H__

/*!
 *	@file		nativeBird.h
 *	@brief		Classe nativeBird
 *	@author		Filipe Medeiros
 *	@date		13/05/2019
 *	@since		13/05/2019
 */

//! Includes and Usings

#include "bird.h"
#include "native.h"

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

class nativeBird : public Bird, Native
{

public:
    //! Construtor e Destrutor

    nativeBird();
    nativeBird(int, string, string, char, double, string, string, Veterinary *, Caregiver *, double, double, string, string);
    ~nativeBird();

    //! Sobrecargas dos operadores

    friend ostream &operator<<(ostream &, nativeBird &);
};

#endif