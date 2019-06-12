#ifndef __MANIPULATOR_H__
#define __MANIPULATOR_H__

/*!
 *	@file		manipulator.h
 *	@brief	Classe Manipulator
 *	@author	Filipe Medeiros
 *	@date		02/05/2019
 *	@since	02/05/2019
 */

//! Includes and Usings

#include "veterinary.h"

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

class Manipulator
{
protected:
    void addWorker();
    void addVeterinary();
    void addCaregiver();

    void addAnimal();

    void searchWorker();
    void searchAnimal();

    void changeAnimal();

    void removeAnimal();
    void removeWorker();

public:
};





#endif