#ifndef __AMPHIBIAN__H_
#define __AMPHIBIAN__H_

/*!
 *	@file		amphibian.h
 *	@brief	Class Amphibian
 *	@author	Sara Santana
 *	@date		02/05/2019
 *	@since	02/05/2019
 */

//! Includes and Usings

#include "animal.h"

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

/*!
 *	@class	Amphibian amphibian.h
 *	@brief	Class Amphibian
 *	@details
 */

class Amphibian : public Animal
{
protected:
  int totalSeed;
  string lastSeed;

public:
  //! Construtor e Destrutor
  Amphibian();
  ~Amphibian();

  //! Metodos Getters
  int getTotalSeed();
  string getLastSeed();

  //! Metodos Setters
  void setTotalSeed(int);
  void setLastSeed(string);
};

#endif