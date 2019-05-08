#ifndef __REPTILE_H_
#define __REPTILE_H_

/*!
 *	@file		reptile.h
 *	@brief	Class Reptile
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
 *	@class	Reptile reptile.h
 *	@brief	Class Reptile
 *	@details
 */
class Reptile : public Animal
{
protected:
  bool isItPoisonous;
  string poisonType;

public:
  //! Construtor e Destrutor

  Reptile();
  ~Reptile();

  //! Metodos Getters

  bool getIsItPoisonous();
  string getPoisonType();

  //! Metodos Setters

  void setIsItPoisonous(bool);
  void setPoisonType(string);
};

#endif