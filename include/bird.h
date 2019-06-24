#ifndef __BIRD_H__
#define __BIRD_H__

/*!
 *	@file		Bird.h
 *	@brief	Class Bird
 *	@author	Sara Santana
 *	@date		03/05/2019
 *	@since	03/05/2019
 */

//! Includes and Usings

#include "animal.h"
#include "wild.h"

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

/*!
 *	@class	Bird Bird.h
 *	@brief	Class Bird
 *	@details
 */
class Bird : public Animal
{
protected:
  double beakSize;
  double handleSpan;

public:
  //! Construtor e Destrutor

  Bird(int, string, string, char, double, string, string, Veterinary *, Caregiver *, double, double);
  ~Bird();

  //! Metodos Getters

  double getBeakSize();
  double getHandleSpan();

  //! Metodos Setters

  void setBeakSize(double);
  void setHandleSpan(double);

  //! Sobrecargas dos operadores

  //void print(ostream &);
};

#endif