#ifndef __MAMMAL_H_
#define __MAMMAL_H_

/*!
 *	@file		mammal.h
 *	@brief	Class Mammal
 *	@author	Sara Santana
 *	@date		03/05/2019
 *	@since	03/05/2019
 */

//! Includes and Usings

#include "animal.h"

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

/*!
 *	@class	Mammal mammal.h
 *	@brief	Class Mammal
 *	@details
 */
class Mammal : public Animal
{
protected:
  string furColor;

public:
  //! Construtor e Destrutor

  Mammal();
  ~Mammal();

  //! Metodos Getters

  string getFurColor();

  //! Metodos Setters

  void setFurColor(string);
};

#endif