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



void Manipulator::addWorker()
{
    cout << "Para adicionar um novo Funcionário é necessário algumas informações." << endl;
    cout << "É um novo vetérinario ou Cuidador?" << endl;
    string Answer;
    cin >> Answer;
    try
    {
        if (Answer == "Veterinario" || "veterinario")
        {
            addVeterinary();
        }
        else if (Answer == "Cuidador" || "cuidador")
        {
            addCaregiver();
        }
    }
    catch (...)
    {
        cout << "Nome Inválido. Tente novamente." << endl;
        addWorker();
    }
}

void Manipulator::addVeterinary()
{
    Veterinary *newVet = new Veterinary();
    cout << "Informe o ID do novo Veterinário " << endl;
    try
    {
        int id;
        cin >> id;
        newVet->setId(id);
    }
    catch (...)
    {
        cout << "O valor do ID tem que ser inteiro." << endl;
    }
}
#endif