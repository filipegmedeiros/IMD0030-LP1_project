#ifndef __EXOTICBIRD_H__
#define __EXOTICBIRD_H__

/*!
 *	@file		exoticBird.h
 *	@brief		Classe exoticBird
 *	@author		Filipe Medeiros
 *	@date		13/05/2019
 *	@since		13/05/2019
 */

//! Includes and Usings

#include "bird.h"
#include "exotic.h"

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

class exoticBird : public Bird, public Exotic
{

private:
    void print(ostream &os) const;

public:
    //! Construtor e Destrutor

    exoticBird();
    exoticBird(int, string, string, char, double, string, string, Veterinary *, Caregiver *, double, double, string, string);
    ~exoticBird();

    //! Sobrecargas dos operadores
    void print();
    friend istream &operator>>(istream &, exoticBird &);
    friend ostream &operator<<(ostream &, exoticBird &);
};

#endif