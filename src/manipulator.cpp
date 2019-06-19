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
using std::ofstream;
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector;
using std::pair;


void Manipulator::loadArchives()
{/* 
    ifstream workersCsv("data/Workers.csv");
    //!ifstream animalsCsv("data/Animals.csv");

    //Carregando os dados dos funcionários
    if (workersCsv.is_open())
    {
        string line;
        //! Procurar na net algo que separe o csv em campos.
        vector<string> fields; //Campos do csv separados... 

        while (getline(workersCsv, line))
        {
            //Carregando algumas das informações do funcionário

            
            //Caso for um tratador
            if (funcao.compare("TRATADOR") == 0)
            {
                Worker *temp = new Caregiver(1, "a", "a", "b", 2, "c", '\0', "a", 1);
                workers.insert(pair<int, Worker *>(id, temp));
            }
            //Caso for um funcionário
            else
            {
                //string crmv = palavras[8];
                Worker *temp = new Veterinary(1, "a", "a", "b", 2, "c", '\0', "a", "b");
                workers.insert(pair<int, Worker *>(id, temp));
            }
        }
    } */
}

void Manipulator::addWorker()
{
    cout << "Adicionar (1)Veterinario ou (2)Cuidador?";
    int a;
    std::cin >> a;

    switch (a)
    {
    case 1:
        int id;
        cin >> id;
        // falta os cins

        //verifica se no map tem o ID passado
        for (map<int, Worker *>::iterator it = workers.begin(); it != workers.end(); it++)
        {
            if (it->first == 1 /*id*/)
            {
                cout << " já existe esse id";
                break;
            }
        }
        //cria um worker temp
        Worker *worker = new Veterinary(id, "a", "a", "b", 2, "c", '\0', "a", "b");

        //adiciona no map
        workers.insert(std::pair<int, Worker *>(1, worker));

        //salva no arquivo.
        std::ofstream outfileWorker;
        outfileWorker.open("data/Worker.csv", std::ios_base::app);
        outfileWorker << *worker;
        outfileWorker.close();

        break;
    }
}
