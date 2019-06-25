#ifndef __EXOTICREPTILE_H__
#define __EXOTICREPTILE_H__

/*!
 *	@file		exoticReptile.h
 *	@brief		Classe exoticReptile
 *	@author		Sara Santana
 *	@date		13/05/2019
 *	@since		13/05/2019
 */

//! Includes and Usings

#include "reptile.h"
#include "exotic.h"

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

class exoticReptile : public Reptile, public Exotic
{

private:
    void print(ostream &os) const;

public:
    //! Construtor e Destrutor

    exoticReptile();
    exoticReptile(int, string, string, char, double, string, string, Veterinary *, Caregiver *, bool, string, string, string);
    ~exoticReptile();

    //! Sobrecargas dos operadores

    friend istream &operator>>(istream &, exoticReptile &);
    friend ostream &operator<<(ostream &, exoticReptile &);
};

#endif