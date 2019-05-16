#ifndef __NATIVEREPTILE_H__
#define __NATIVEREPTILE_H__

/*!
 *	@file		nativeReptile.h
 *	@brief		Classe nativeReptile
 *	@author		Sara Santana
 *	@date		13/05/2019
 *	@since		13/05/2019
 */

//! Includes and Usings

#include "reptile.h"
#include "native.h"

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

class nativeReptile : public Reptile, public Native
{

public:
    //! Construtor e Destrutor

    nativeReptile();
    nativeReptile(int, string, string, char, double, string, string, Veterinary *, Caregiver *, bool, string, string, string);
    ~nativeReptile();

    //! Sobrecargas dos operadores

    friend ostream &operator<<(ostream &, nativeReptile &);
};

#endif