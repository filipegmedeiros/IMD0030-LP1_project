#ifndef __EXOTICAMPHIBIAN_H__
#define __EXOTICAMPHIBIAN_H__

/*!
 *	@file		exoticAmphibian.h
 *	@brief		Classe exoticAmphibian
 *	@author		Sara Santana
 *	@date		13/05/2019
 *	@since		13/05/2019
 */

//! Includes and Usings

#include "amphibian.h"
#include "exotic.h"

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

class exoticAmphibian : public Amphibian, Exotic
{

public:
    //! Construtor e Destrutor

    exoticAmphibian();
    exoticAmphibian(int, string, string, char, double, string, string, Veterinary *, Caregiver *, int, string, string, string);
    ~exoticAmphibian();

    //! Sobrecargas dos operadores

    friend ostream &operator<<(ostream &, exoticAmphibian &);
};

#endif