#ifndef __BIRD_H_
#define __BIRD_H_

/*!
 *	@file		bird.h
 *	@brief	Class Bird
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
 *	@class	Bird bird.h
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

  Bird();
  ~Bird();

  //! Metodos Getters

  double getBeakSize();
  double getHandleSpan();

  //! Metodos Setters

  void setBeakSize(double);
  void setHandleSpan(double);
};

#endif