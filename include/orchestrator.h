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

    cout << "'1' para adicionar um fucionario" << endl;
    cout << "'2' para adicionar um animal" << endl;
    int Case;
    cin >> Case;

    switch (Case)
    {
    case 1:
        addWorker();
        break;
        
    default:
        cout << "opçao invalida" << endl;
        break;
    }
}

#endif