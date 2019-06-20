/*!
 *	@file	Manipulator.cpp
 *	@brief	Implementação do header da classe Manipulator
 *	@author	Filipe Medeiros
 *	@date	13/05/2019
 *	@since	13/05/2019
 */

#include "manipulator.h"

void Manipulator::checkId(int id)
{
    //verifica se no map tem o ID passado
    for (map<int, Worker *>::iterator it = workers.begin(); it != workers.end(); it++)
    {
        if (it->first == id)
        {
            cout << "That ID has been found. Try Again.";
        }
    }
}

void Manipulator::addWorker()
{
    cout << "Choice One Option: " << endl
         << "[1] To Register an Veterinary" << endl
         << "[2] To Register an Caregiver" << endl;
    int whatIs;
    cin >> whatIs;

    int id;
    string function;
    string name;
    string cpf;
    short int age;
    string bloodType;
    char factorRh;
    string specialty;

    cout << "[----------------]" << endl;
    cout << "Choice an ID: ";
    cin >> id;
    checkId(id);

    cout << "Type the Function: ";
    cin >> function;

    cout << "He/She Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "CPF: (000.000.000-00) ";
    cin >> cpf;

    cout << "He/She Age: ";
    cin >> age;

    cout << "blood Type: ";
    cin >> bloodType;

    cout << "factor RH: ";
    cin >> factorRh;

    cout << "Specialty: ";
    cin.ignore();
    getline(cin, specialty);

    switch (whatIs)
    {
    case 1:
    {
        int securityLevel;

        cout << "Security Level: ";
        cin >> securityLevel;
        //cria um worker temp

        Worker *worker = new Caregiver(id, function, name, cpf, age, bloodType, factorRh, specialty, securityLevel);

        //adiciona no map
        workers.insert(std::pair<int, Worker *>(1, worker));

        ofstream outfileWorker;
        outfileWorker.open("data/Worker.csv", std::ios_base::app);
        outfileWorker << *worker;
        outfileWorker.close();

        break;
    }
    case 2:
    {
        string crmv;
        cout << "Crmv Register: ";
        cin >> crmv;

        //cria um worker temp
        Worker *worker = new Veterinary(id, function, name, cpf, age, bloodType, factorRh, specialty, crmv);

        //adiciona no map
        workers.insert(std::pair<int, Worker *>(1, worker));

        ofstream outfileWorker;
        outfileWorker.open("data/Worker.csv", std::ios_base::app);
        outfileWorker << *worker;
        outfileWorker.close();

        break;
    }
    }
}