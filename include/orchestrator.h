#ifndef __ORCHESTRATOR_H__
#define __ORCHESTRATOR_H__

/*!
 *	@file		orchestrator.h
 *	@brief	Classe Orchestrator
 *	@author	Filipe Medeiros
 *	@date		02/05/2019
 *	@since	02/05/2019
 */

//! Includes and Usings

#include "manipulator.h"

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

class Orchestrator : public Manipulator
{
private:
    bool loop;

public:
    Orchestrator();
    void menu();
};

#endif