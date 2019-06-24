#ifndef __NATIVEAMPHIBIAN_H__
#define __NATIVEAMPHIBIAN_H__

/*!
 *	@file		nativeAmphibian.h
 *	@brief		Classe nativeAmphibian
 *	@author		Sara Santana
 *	@date		13/05/2019
 *	@since		13/05/2019
 */

//! Includes and Usings

#include "amphibian.h"
#include "native.h"

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

class nativeAmphibian : public Amphibian, public Native
{
private:
    void print(ostream &os) const;

public:
    //! Construtor e Destrutor

    nativeAmphibian();
    nativeAmphibian(int, string, string, char, double, string, string, Veterinary *, Caregiver *, int, string, string, string);
    ~nativeAmphibian();

    //! Sobrecargas dos operadores
    friend istream &operator>>(istream &, nativeAmphibian &);
    friend ostream &operator<<(ostream &, nativeAmphibian &);
};

#endif