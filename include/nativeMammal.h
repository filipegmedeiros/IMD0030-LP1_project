#ifndef __NATIVEMAMMAL_H__
#define __NATIVEMAMMAL_H__

/*!
 *	@file		nativeMammal.h
 *	@brief		Classe nativeMammal
 *	@author		Sara Santana
 *	@date		13/05/2019
 *	@since		13/05/2019
 */

//! Includes and Usings

#include "mammal.h"
#include "native.h"

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

class nativeMammal : public Mammal,public Native
{

public:
    //! Construtor e Destrutor

    nativeMammal();
    nativeMammal(int, string, string, char, double, string, string, Veterinary *, Caregiver *, string, string, string);
    ~nativeMammal();

    //! Sobrecargas dos operadores

    friend ostream &operator<<(ostream &, nativeMammal &);
};

#endif