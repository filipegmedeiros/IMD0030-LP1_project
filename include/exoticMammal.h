#ifndef __EXOTICMAMMAL_H__
#define __EXOTICMAMMAL_H__

/*!
 *	@file		exoticMammal.h
 *	@brief		Classe exoticMammal
 *	@author		Sara Santana
 *	@date		13/05/2019
 *	@since		13/05/2019
 */

//! Includes and Usings

#include "mammal.h"
#include "exotic.h"

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

class exoticMammal : public Mammal, public Exotic
{

private:
    void print(ostream &os) const;

public:
    //! Construtor e Destrutor

    exoticMammal();
    exoticMammal(int, string, string, char, double, string, string, Veterinary *, Caregiver *, string, string, string);
    ~exoticMammal();

    //! Sobrecargas dos operadores
    friend istream &operator>>(istream &, exoticMammal &);
    friend ostream &operator<<(ostream &, exoticMammal &);
};

#endif