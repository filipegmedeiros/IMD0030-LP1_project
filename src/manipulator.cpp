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



bool Manipulator::FileExists(string name){
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

void Manipulator::addWorker()
{
    string data = "ID;FUNCTION;NAME;CPF;AGE;BLOOD TYPE;FACTOR RH;SPECIALTY;CRMV;";
    string name = "data/Worker.csv";

    if((FileExists(name))==false){
        std::ofstream outfileWorker;
        outfileWorker.open("data/Worker.csv",std::ios_base::app);
        outfileWorker << data << endl;
        outfileWorker.close();
    }

    

    cout << "Para adicionar um novo Funcionário é necessário algumas informações." << endl;
    cout << "É um novo vetérinario ou Cuidador?" << endl;
    string Answer;
    cin >> Answer;
    // try
    // {
         if (Answer == "Veterinario" || Answer == "veterinario")
         {
            addVeterinary();
         }

        else if (Answer == "Cuidador" || Answer == "cuidador")
        {
            addCaregiver();
        }
    // }
    // catch (...)
    // {
    //     cout << "Nome Inválido. Tente novamente." << endl;
    //     addWorker();
    // }
}

void Manipulator::addVeterinary()
{
    Veterinary *newVet = new Veterinary(1, "Vet", "Sara", "123.956.789-00", 40, "B",'+', "Vet","1987");
    std::ofstream outfileWorker2;
     outfileWorker2.open("data/Worker.csv", std::ios_base::app);
    
    
        
        outfileWorker2 << *newVet;
        outfileWorker2.close();
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


void Manipulator::addCaregiver()
{
    Caregiver *newCare = new Caregiver();
    std::ofstream outfileWorker2;
     outfileWorker2.open("data/Worker.csv", std::ios_base::app);
    
    
        
        outfileWorker2 << *newCare;
        outfileWorker2.close();
}

void Manipulator::addAnimal()
{
    int animalType=0;
    cout<<"Escolha qual animal deseja adicionar:"<<endl;
    cout<<"1 - Passaro; 2 - Anfibio; 3 - Mamifero; 4 - Reptil"<<endl;
    cin >> animalType;


    string data = "ID;ANIMALCLASS;SCIENTIFIC NAME;SEX;SIZE;DIET;BAPTISMAL NAME;VETERINARY;CAREGIVER;TOTALSEED;LAST SEED";
    string name = "data/Animals/ExoticAmphibian.csv";

    if((FileExists(name))==false){
        std::ofstream outfileWorker;
        outfileWorker.open("data/Animals/ExoticAmphibian.csv",std::ios_base::app);
        outfileWorker << data << endl;
        outfileWorker.close();
    }

    exoticAmphibian *newExoAmph= new exoticAmphibian();
    std::ofstream outfileWorker2;
     outfileWorker2.open("data/Animals/ExoticAmphibian.csv", std::ios_base::app);
    
    
        
        outfileWorker2 << *newExoAmph;
        outfileWorker2.close();

}