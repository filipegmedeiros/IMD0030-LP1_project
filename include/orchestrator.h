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
protected:
public:
    void menu();
};

void Orchestrator::menu()
{
    char Case;
    cin >> Case;

    switch (Case)
    {
    case 'A':
        addWorker();
        break;
    case 'B':
        addAnimal();
        break;
    case 'C':
        changeAnimal();
        break;
    case 'D':
        removeWorker();
        break;
    case 'E':
        removeAnimal();
        break;
    case 'F':
        searchAnimal();
        break;
    case 'G':
        searchWorker();
        break;
    }
}

#endif