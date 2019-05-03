#ifndef __VETERINARY_H__
#define __VETERINARY_H__

/*!
 *	@file		veterinary.h
 *	@brief	Classe Veterinary
 *	@author	Filipe Medeiros
 *	@date		02/05/2019
 *	@since	02/05/2019
 */

//! Includes and Usings

#include <worker.h>

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

/*!
 *	@class		Veterinary worker.h
 *	@brief		Template Class Veterinary
 *	@details	Os atributos do funcionário são herdados
 *	da classe Workers.
 */

class Veterinary : public Worker
{
  public:
    //! Construtor e Destrutor
    Veterinary();
    Veterinary(int, string, string, string, short int, string, char, string);
    ~Veterinary();

    //! Sobrecargas dos operadores
    friend istream &operator>>(istream &, Veterinary &);
    friend ostream &operator<<(ostream &, Veterinary &);
};

#endif