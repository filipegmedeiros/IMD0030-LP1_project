/*!
 *	@file	Manipulator.cpp
 *	@brief	Implementação do header da classe Manipulator
 *	@author	Filipe Medeiros
 *	@date	13/05/2019
 *	@since	13/05/2019
 */

#include "manipulator.h"


void Manipulator::loadArchives()
{
    ifstream input("./data/Veterinary.csv");
    Worker *veterinary = new Veterinary();
    string buff;
    if (input.is_open())
    {

        while (getline(input, buff) >> *veterinary)
        {

            workers.insert(pair<int, Worker *>(veterinary->getId(), veterinary));
        }
    }
    else
    {
        cout << endl
             << "Arquivo não encontrado o Veterinary.csv";
    }



    input.close();

    ifstream input2("./data/Caregiver.csv");
    Worker *caregiver = new Caregiver();
    string buff2;
    if (input2.is_open())
    {

        while (getline(input2, buff2) >> *caregiver)
        {

            workers.insert(pair<int, Worker *>(caregiver->getId(), caregiver));
        }
    }
    else
    {
        cout << endl
             << "Arquivo não encontrado o Caregiver.csv";
    }
    input2.close();
}

bool Manipulator::checkId(int id)
{
    //verifica se no map tem o ID passado
    for (map<int, Worker *>::iterator it = workers.begin(); it != workers.end(); it++)
    {
        if (it->first == id)
        {
            cout << "Id Exists. Please choice other." << endl;
            return false;
        }
    }
    return true;
}



void Manipulator::addWorker()
{
    cout << "Choose an option: " << endl
         << "[1] To register a caregiver" << endl
         << "[2] To register a veterinary" << endl;
    int whatIs;
    cin >> whatIs;

    //esse bloco impede um loop infinito se o usuário dititar um tipo diferente de int
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<< "Error in entry. Type a number."<<endl;
        cin >> whatIs;
    }

    int id;
    string function;
    string name;
    string cpf;
    short int age;
    string bloodType;
    char factorRh;
    string specialty;
    

    do
    {
        cout << "[----------------]" << endl;
        cout << "Choose an ID: ";
        cin >> id;
    } while (!checkId(id));

    cout << "He/She Name: ";
    cin >> name;

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
       
        function = "caregiver";

        //cria um worker temp

        Worker *worker = new Caregiver(id, function, name, cpf, age, bloodType, factorRh, specialty, securityLevel);

        //adiciona no map
        workers.insert(pair<int, Worker *>(id, worker));


        ofstream outfileWorker;
        outfileWorker.open("./data/Caregiver.csv", std::ios_base::app);
        outfileWorker << *worker;
        outfileWorker.close();

        delete worker;

        break;
    }
    case 2:
    {
        string crmv;
        cout << "Crmv Register: ";
        cin >> crmv;

        function = "veterinary";

        //cria um worker temp
        Worker *worker = new Veterinary(id, function, name, cpf, age, bloodType, factorRh, specialty, crmv);

        //adiciona no map
        workers.insert(std::pair<int, Worker *>(id, worker));

        ofstream outfileWorker;
        outfileWorker.open("data/Veterinary.csv", std::ios_base::app);
        outfileWorker << *worker;
        outfileWorker.close();

        delete worker;

        break;
    }
    }
}
//Incompleto, falta apenas inserir no arquivo
void Manipulator::addAnimal()
{
    cout << "Choose an option: " << endl
         << "[1] To register an amphibian" << endl
         << "[2] To register a reptile" << endl
         << "[3] To register a bird" << endl
         << "[4] To register a mammal" << endl;
    int whatIs;
    cin >> whatIs;

    //esse bloco impede um loop infinito se o usuário dititar um tipo diferente de int
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<< "Error in entry. Type a number."<<endl;
        cin >> whatIs;
    }
    

    int id;
    string aniClass;
    string name_species;
    string sciname;
    char gender;
    double size;
    string diet;
    int vet;
    int carer;
    string nickname;
    string country;
    string UFplace;
    string ibamaAuth;

    do
    {
        cout << "[----------------]" << endl;
        cout << "Choose an ID: ";
        cin >> id;
    } while (!checkId(id));

    cout << "Species name: ";
    cin >> name_species;

    cout << "Scientific Name: ";
    cin >> sciname;

    cout << "Gender(M/F): ";
    cin >> gender;

    cout << "Animal size(double): ";
    cin >> size;

    cout << "Diet: ";
    cin >> diet;

    cout << "Associated Veterinary ID(0 = none): ";
    cin >> vet;

    cout << "Associated Caregiver ID(0 = none): ";
    cin >> carer;

    cout << "Animal nickname: ";
    cin >> nickname;

    
    switch(whatIs)
    {  
        
        case 1:
        {
            
           cout << "Choose an option: " << endl
                << "[1] To register an Exotic Amphibian" << endl
                << "[2] To register a Native Amphibian" << endl;
            int animalType;
            cin >> animalType;
            
            switch(animalType)
            {
                case 1:

                aniClass = "exotic amphibian";

                cout << "Country of origin: " << endl;
                cin >> country;

                cout << "Ibama Authorization " << endl;
                cin >> ibamaAuth;

                break;

                case 2:
                aniClass = "native amphibian";

                cout << "UF of origin: " << endl;
                cin >> UFplace;

                cout << "Ibama authuorization " << endl;
                cin >> ibamaAuth;

                break;
            }
            ofstream outfileAnimal;
            outfileAnimal.open("data/Animal.csv", std::ios_base::app);
            outfileAnimal << id << ";" 
                          << aniClass << ";"
                          << name_species << ";"
                          << sciname << ";"
                          << gender << ";"
                          << size << ";"
                          << diet << ";"
                          << vet << ";"
                          << carer << ";"
                          << nickname << ";";
                        
            outfileAnimal.close();
            
            break;
        }
        case 2:
        {
            cout << "Choose an option: " << endl
                << "[1] To register an Exotic Reptile" << endl
                << "[2] To register a Native Reptile" << endl;
            int animalType;
            cin >> animalType;
            
            switch(animalType)
            {
                case 1:

                aniClass = "exotic reptile";

                cout << "Country of origin: " << endl;
                cin >> country;

                cout << "Ibama Authorization " << endl;
                cin >> ibamaAuth;

                break;

                case 2:
                aniClass = "native reptile";

                cout << "UF of origin: " << endl;
                cin >> UFplace;

                cout << "Ibama authuorization " << endl;
                cin >> ibamaAuth;

                break;
            }

            ofstream outfileAnimal;
            outfileAnimal.open("data/Animal.csv", std::ios_base::app);
            outfileAnimal << id << ";" 
                          << aniClass << ";"
                          << name_species << ";"
                          << sciname << ";"
                          << gender << ";"
                          << size << ";"
                          << diet << ";"
                          << vet << ";"
                          << carer << ";"
                          << nickname << ";";
            outfileAnimal.close();
            
            break;
        }
        case 3:
        {
            cout << "Choose an option: " << endl
                << "[1] To register an Exotic Bird" << endl
                << "[2] To register a Native Bird" << endl;
            int animalType;
            cin >> animalType;
            
            switch(animalType)
            {
                case 1:

                aniClass = "exotic bird";

                cout << "Country of origin: " << endl;
                cin >> country;

                cout << "Ibama Authorization " << endl;
                cin >> ibamaAuth;

                break;

                case 2:
                aniClass = "native bird";

                cout << "UF of origin: " << endl;
                cin >> UFplace;

                cout << "Ibama authuorization " << endl;
                cin >> ibamaAuth;

                break;
            }

            ofstream outfileAnimal;
            outfileAnimal.open("data/Animal.csv", std::ios_base::app);
            outfileAnimal << id << ";" 
                          << aniClass << ";"
                          << name_species << ";"
                          << sciname << ";"
                          << gender << ";"
                          << size << ";"
                          << diet << ";"
                          << vet << ";"
                          << carer << ";"
                          << nickname << ";";
            outfileAnimal.close();
            
            break;
        }
        case 4:
        {
            cout << "Choose an option: " << endl
                << "[1] To register an Exotic Mammal" << endl
                << "[2] To register a Native Mammal" << endl;
            int animalType;
            cin >> animalType;
            
            switch(animalType)
            {
                case 1:

                aniClass = "exotic mammal";

                cout << "Country of origin: " << endl;
                cin >> country;

                cout << "Ibama Authorization " << endl;
                cin >> ibamaAuth;

                break;

                case 2:
                aniClass = "native mammal";

                cout << "UF of origin: " << endl;
                cin >> UFplace;

                cout << "Ibama authuorization " << endl;
                cin >> ibamaAuth;

                break;
            }

            ofstream outfileAnimal;
            outfileAnimal.open("data/Animal.csv", std::ios_base::app);
            outfileAnimal << id << ";" 
                          << aniClass << ";"
                          << name_species << ";"
                          << sciname << ";"
                          << gender << ";"
                          << size << ";"
                          << diet << ";"
                          << vet << ";"
                          << carer << ";"
                          << nickname << ";";
            outfileAnimal.close();
            
            break;
        }
    }
}

//comentei devido a segmentention fault na declaração do iterator it = workers.begin;
// não faço ideia do pq, tentando ajeitar
void Manipulator::removeWorker()
{
    // int id=0;
    // ofstream outfileWorker2;
   
    // cout << "Type the Worker's ID:" << endl;
    // cin >> id;
    
    // //checa se existe um Worker com a ID digitada
    // if((workers.find(id))==workers.end())
    // {
    //     cout << "ID inválida." << endl;
    // } 
    // else 
    // {
    //     //Se o Worker for um veterinario ele vai atualizar o arquivo Veterinary.csv
    //     if((workers[id]->getFunction()).compare("veterinary")==0)
    //     {
            
    //         workers.erase(id);
    //         delete workers[id];
    //         outfileWorker2.open("./data/Veterinary.csv");
            
    //         for (map<int, Worker *>::iterator it = workers.begin(); it != workers.end(); it++)
    //         {  
    //             if ((it->second->getFunction()).compare("veterinary")==0)
    //             {
    //                 outfileWorker2 << *(it->second);
    //             }
    //         }
    //         outfileWorker2.close();
    //     }
    //     //Se o Worker for um Caregiver ele vai atualizar o arquivo Caregiver.csv
    //     else if((workers[id]->getFunction()).compare("caregiver")==0)
    //     {
    //         workers.erase(id);
    //         outfileWorker2.open("./data/Caregiver.csv");
    //         for (map<int, Worker *>::iterator it = workers.begin(); it != workers.end(); it++)
    //         {  
    //             if ((it->second->getFunction()).compare("caregiver")==0)
    //             {
    //                 outfileWorker2 << *(it->second);
    //             }
    //         }
    //         outfileWorker2.close();
    //     }
    // }
}

