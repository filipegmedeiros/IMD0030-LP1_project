/*!
 *	@file	Manipulator.cpp
 *	@brief	Implementação do header da classe Manipulator
 *	@author	Filipe Medeiros
 *	@date	13/05/2019
 *	@since	13/05/2019
 */

#include "manipulator.h"

#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;




void Manipulator::addWorker()
{
    cout << "Para adicionar um novo Funcionário é necessário algumas informações." << endl;
    cout << "É um novo vetérinario ou Cuidador?" << endl;
    string Aswner;
    cin >> Aswner;
    try
    {
        if (Aswner == "Veterinario" || "veterinario")
        {
            addVeterinary();
        }
        else if (Aswner == "Cuidador" || "cuidador")
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
    string data = "ID;NAME;CPF;AGE;BLOOD TYPE;FACTOR RH;SPECIALTY;CRMV;";
    std::ofstream outfile("Worker.csv");

    if(!outfile.is_open()){
        cout << "Error opening file" << endl;
    }else if(outfile.is_open()){
        outfile << data << *newVet << endl;
        outfile.close();
    }

    // cout << "Informe o ID do novo Veterinário " << endl;
    // try
    // {
    //     int id;
    //     cin >> id;
    //     newVet->setId(id);
    // }
    // catch (...)
    // {
    //     cout << "O valor do ID tem que ser inteiro." << endl;
    // }
}