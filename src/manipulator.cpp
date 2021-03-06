/*!
 *	@file	Manipulator.cpp
 *	@brief	Implementação do header da classe Manipulator
 *	@author	Filipe Medeiros
 *	@date	13/05/2019
 *	@since	13/05/2019
 */

#include "manipulator.h"
#include <sstream>

const vector<string> Manipulator::separate(const string s, const char c)
{

    string buff{""};
    vector<string> v;

    for (auto n : s)
    {
        if (n != c)
            buff += n;
        else if (n == c)
        {
            v.push_back(buff);
            buff = "";
        }
    }
    if (buff != "")
    {
        v.push_back(buff);
        buff = "";
    }

    return v;
}

void Manipulator::loadArchives()
{
    ifstream fileWorkers("./data/Workers.csv", std::ios::in);
    ifstream fileAnimal("./data/Animals.csv", std::ios::in);
    string str;
    vector<string> v;

    if (fileWorkers)
    {
        while (!fileWorkers.eof())
        {
            getline(fileWorkers, str);
            if (str == "")
                continue;
            v = separate(str, ';');

            if (v[1] == "veterinary")
            {
                workers.insert(pair<int, Worker *>(stoi(v[0]), new Veterinary(stoi(v[0]), v[1], v[2], v[3], (short)stoi(v[4]), v[5], v[6][0], v[7], v[8])));
            }
            else if(v[1] == "caregiver")
            {
                workers.insert(pair<int, Worker *>(stoi(v[0]), new Caregiver(stoi(v[0]), v[1], v[2], v[3], (short)stoi(v[4]), v[5], v[6][0], v[7], stoi(v[8]))));
            }

            v.clear();
        }
    }
    fileWorkers.close();
    
    if (fileAnimal)
    {
        while (!fileAnimal.eof())
        {
            getline(fileAnimal, str);
            if (str == "")
                continue;
            v = separate(str, ';');

            if (v[1].compare("exotic amphibian")==0)
            {
                animals.insert(pair<int, Animal *>(stoi(v[0]), new exoticAmphibian(stoi(v[0]), v[1], v[2], v[3][0], (double)stoi(v[4]), v[5], v[6], v[7], (v[8]), stoi(v[9]), v[10], v[11], v[12]);
            }
            else if(v[1].compare("exotic reptile")==0)
            {
                animals.insert(pair<int, Animal *>());
            }
            else if(v[1].compare("exotic bird")==0)
            {
                animals.insert(pair<int, Animal *>());
            }
            else if(v[1].compare("exotic mammal")==0)
            {
                animals.insert(pair<int, Animal *>());
            }
            else if(v[1].compare("native amphibian")==0)
            {
                animals.insert(pair<int, Animal *>());
            }
            else if(v[1].compare("native reptile")==0)
            {
                animals.insert(pair<int, Animal *>());
            }
            else if(v[1].compare("native bird")==0)
            {
                animals.insert(pair<int, Animal *>());
            }
            else if(v[1].compare("native mammal")==0)
            {
                animals.insert(pair<int, Animal *>());
            }
            v.clear();
        }
        fileAnimal.close();
    }
    
}

void Manipulator::listWorkers()
{

    cout << "-----------------------Workers---------------------" << endl;
    for (map<int, Worker *>::iterator it = workers.begin(); it != workers.end(); ++it)
    {
        cout << "ID: " << it->first << endl
             << "Function: " << it->second->getFunction() << endl
             << "Name: " << it->second->getName() << endl
             << "CPF: " << it->second->getCpf() << endl
             << "Age: " << it->second->getAge() << endl
             << "Blood Type: " << it->second->getBloodType() << endl
             << "RH factor: " << it->second->getFactorRh() << endl
             << "Specialty " << it->second->getSpecialty() << endl;
        if (((it->second)->getFunction()).compare("veterinary") == 0)
        {
            cout << "CRMV: " << ((Veterinary *)(it->second))->getCrmv() << endl
                 << "----------------------------------------------------" << endl;
        }
        else if (((it->second)->getFunction()).compare("caregiver") == 0)
        {
            cout << "Security Level: " << ((Caregiver *)(it->second))->getSecurityLevel() << endl
                 << "----------------------------------------------------" << endl;
        }
    }
    cout << "----------------------------------------------------" << endl;
}

bool Manipulator::checkId(int id)
{
    //verifica se no map tem o ID passado
    for (map<int, Worker *>::iterator it = workers.begin(); it != workers.end(); it++)
    {
        if (it->first == id)
        {
            cout << "Id Exists. Please choose another." << endl;
            return false;
        }
    }
    return true;
}

bool Manipulator::checkIdAnimal(int id)
{
    //verifica se no map tem o ID passado
    for (map<int, Animal *>::iterator it = animals.begin(); it != animals.end(); it++)
    {
        if (it->first == id)
        {
            cout << "Id Exists. Please choose another." << endl;
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
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Error in entry. Type a number." << endl;
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
        outfileWorker.open("./data/Workers.csv", std::ios_base::app);
        outfileWorker << *worker;
        outfileWorker.close();

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
        outfileWorker.open("./data/Workers.csv", std::ios_base::app);
        outfileWorker << *worker;
        outfileWorker.close();

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
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Error in entry. Type a number." << endl;
        cin >> whatIs;
    }

    int animalType;
    switch (whatIs)
    {
    case 1:
    {
        cout << "Choose an option: " << endl
             << "[1] To register an Exotic Amphibian" << endl
             << "[2] To register a Native Amphibian" << endl;
        cin >> animalType;
        break;
    }
    case 2:
    {
        cout << "Choose an option: " << endl
             << "[1] To register an Exotic Reptile" << endl
             << "[2] To register a Native Reptile" << endl;
        cin >> animalType;

        break;
    }
    case 3:
    {
        cout << "Choose an option: " << endl
             << "[1] To register an Exotic Bird" << endl
             << "[2] To register a Native Bird" << endl;
        cin >> animalType;
        break;
    }
    case 4:
    {
        cout << "Choose an option: " << endl
             << "[1] To register an Exotic Mammal" << endl
             << "[2] To register a Native Mammal" << endl;
        cin >> animalType;
        break;
    }
    default:
    {
        cout << "Invalid option." << endl;
    }
    }

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Error in entry. Type a number." << endl;
        cin >> animalType;
    }

    int id;
    string aniClass;
    string name_species;
    string sciname;
    char gender;
    double size;
    string diet;
    int vetId;
    int carerId;
    string nickname;
    int totalSeed;
    string lastSeed;
    bool isItPoisonous;
    string poisonType;
    double beakSize;
    double handleSpan;
    string furColor;
    string UFplace;
    string country;
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

    cout << "Associated Veterinary ID ";
    cin >> vetId;

    // //checa se existe um veterinary associado ao id dado e chama findWorker();
    // Worker *selectedVet = new Veterinary;
    // if((workers.find(vetId)) == workers.end())
    // {
    //     //enquanto o vet não for valido ele vai imprimir uma lista de vets e pedir um id valido
    //     while((workers.find(vetId)) == workers.end())
    //     {
    //         cout << "Veterinary not found. Type a valid ID." << endl
    //         << "----------------------------------------------------" << endl;
    //         for (map<int, Worker *>::iterator it = workers.begin(); it != workers.end(); ++it)
    //         {
    //             if(((it->second)->getFunction()).compare("veterinary")==0)
    //             {
    //                 cout << "List of Veterinaries: " << endl
    //                 << "Veterinary Name: " << it->second->getName() << "ID: " << it->second->getId() << endl;

    //             }
    //         }
    //         cout << "----------------------------------------------------" << endl;
    //         cin >> vetId;
    //     }
    // }
    // else
    // {

    //     selectedVet = findWorker(vetId, 0);
    // }

    cout << "Associated Caregiver ID ";
    cin >> carerId;

    // //checa se existe um caregiver associado ao id dado e chama findWorker();
    // Worker *selectedCarer = new Caregiver;
    // if((workers.find(carerId)) == workers.end())
    //     {
    //         //enquanto o caregiver não for valido ele vai imprimir uma lista de caregivers e pedir um id valido
    //         while((workers.find(carerId)) == workers.end())
    //         {
    //             cout << "Caregiver not found. Type a valid ID." << endl
    //             << "----------------------------------------------------" << endl;
    //             for (map<int, Worker *>::iterator it = workers.begin(); it != workers.end(); ++it)
    //             {
    //                 if(((it->second)->getFunction()).compare("caregiver")==0)
    //                 {
    //                     cout << "List of Caregivers: " << endl
    //                     << "Caregiver Name: " << it->second->getName() << "ID: " << it->second->getId() << endl;

    //                 }
    //             }
    //             cout << "----------------------------------------------------" << endl;
    //             cin >> carerId;
    //         }
    //     }
    //     else
    //     {
    //     selectedCarer = findWorker(carerId, 1);
    //     }

    cout << "Animal nickname: ";
    cin >> nickname;

    ofstream outfileAnimal;
    outfileAnimal.open("data/Animals.csv", std::ios_base::app);

    Veterinary *vet1 = findWorkerVet(vetId);
    Caregiver *care1 = findWorkerCare(carerId);

    switch (whatIs)
    {

    case 1:
    {

        cout << "Total seed: (int)" << endl;
        cin >> totalSeed;
        cout << "Last seed:" << endl;
        cin >> lastSeed;

        switch (animalType)
        {
        case 1:
        {

            aniClass = "exotic amphibian";

            cout << "Country of origin: " << endl;
            cin >> country;

            cout << "Ibama Authorization " << endl;
            cin >> ibamaAuth;

            Animal *animal = new exoticAmphibian(id, aniClass, sciname, gender, size, diet, nickname, vet1, care1, totalSeed, lastSeed, ibamaAuth, country);

            //adiciona no map
            animals.insert(std::pair<int, Animal *>(id, animal));

            outfileAnimal << *animal;
            outfileAnimal.close();

            break;
        }
        case 2:
        {
            aniClass = "native amphibian";

            cout << "UF of origin: " << endl;
            cin >> UFplace;

            cout << "Ibama authuorization " << endl;
            cin >> ibamaAuth;

            //Animal *animal = new nativeAmphibian(id, aniClass, sciname, gender, size, diet, nickname, vet1, care1, totalSeed, lastSeed, ibamaAuth, UFplace);

            //adiciona no map

            break;
        }
        }
        break;
    }
    case 2:
    {
        cout << "isItPoisonous: (bool)" << endl;
        cin >> isItPoisonous;
        cout << "Poison Type:" << endl;
        cin >> poisonType;

        switch (animalType)
        {
        case 1:
        {

            aniClass = "exotic reptile";

            cout << "Country of origin: " << endl;
            cin >> country;

            cout << "Ibama Authorization " << endl;
            cin >> ibamaAuth;

            Animal *animal = new exoticReptile(id, aniClass, sciname, gender, size, diet, nickname, vet1, care1, isItPoisonous, poisonType, ibamaAuth, country);
            animals.insert(std::pair<int, Animal *>(id, animal));
            outfileAnimal << *animal;
            outfileAnimal.close();

            //adiciona no map

            break;
        }
        case 2:
        {
            aniClass = "native reptile";

            cout << "UF of origin: " << endl;
            cin >> UFplace;

            cout << "Ibama authuorization " << endl;
            cin >> ibamaAuth;

            //Animal *animal = new nativeReptile(id, aniClass, sciname, gender, size, diet, nickname, vet1, care1, totalSeed, lastSeed, ibamaAuth, country);
        }
        break;
        }

        break;
    }
    case 3:
    {
        cout << "Beak Size (double)" << endl;
        cin >> beakSize;
        cout << "Handle Span(double)" << endl;
        cin >> handleSpan;

        switch (animalType)
        {
        case 1:
        {

            aniClass = "exotic bird";

            cout << "Country of origin: " << endl;
            cin >> country;

            cout << "Ibama Authorization " << endl;
            cin >> ibamaAuth;

            Animal *animal = new exoticBird(id, aniClass, sciname, gender, size, diet, nickname, vet1, care1, beakSize, handleSpan, ibamaAuth, country);

            //adiciona no map
            animals.insert(std::pair<int, Animal *>(id, animal));

            outfileAnimal << *animal;
            outfileAnimal.close();

            break;
        }
        case 2:
        {
            aniClass = "native bird";

            cout << "UF of origin: " << endl;
            cin >> UFplace;

            cout << "Ibama authuorization " << endl;
            cin >> ibamaAuth;

            break;
        }
        }

        break;
    }
    case 4:
    {

        cout << "Fur Color: " << endl;
        cin >> furColor;

        switch (animalType)
        {
        case 1:
        {

            aniClass = "exotic mammal";

            cout << "Country of origin: " << endl;
            cin >> country;

            cout << "Ibama Authorization " << endl;
            cin >> ibamaAuth;

            Animal *animal = new exoticMammal(id, aniClass, sciname, gender, size, diet, nickname, vet1, care1, furColor, ibamaAuth, country);
            animals.insert(std::pair<int, Animal *>(id, animal));

            outfileAnimal << *animal;
            outfileAnimal.close();
            break;
        }
        case 2:
        {
            aniClass = "native mammal";

            cout << "UF of origin: " << endl;
            cin >> UFplace;

            cout << "Ibama authuorization " << endl;
            cin >> ibamaAuth;

            break;
        }
        }
        break;
    }
    }
}

//comentei devido a segmentention fault na declaração do iterator it = workers.begin;
// não faço ideia do pq, tentando ajeitar
void Manipulator::removeWorker()
{
    int id = 0;
    ofstream outfileWorker2;

    cout << "Type the Worker's ID:" << endl;
    cin >> id;
    //checa se existe um Worker com a ID digitada
    if ((workers.find(id)) == workers.end())
    {
        cout << "ID inválida." << endl;
    }
    else
    {
        workers.erase(id);
        outfileWorker2.open("data/Workers.csv");

        for (map<int, Worker *>::iterator it = workers.begin(); it != workers.end(); it++)
        {
                outfileWorker2 << *(it->second);
        
        }
        outfileWorker2.close();
        }
    //     //Se o Worker for um Caregiver ele vai atualizar o arquivo Caregiver.csv
    //     else if ((workers[id]->getFunction()).compare("caregiver") == 0)
    //     {
    //         workers.erase(id);
    //         outfileWorker2.open("data/Caregiver.csv");
    //         for (map<int, Worker *>::iterator it = workers.begin(); it != workers.end(); it++)
    //         {
    //             if ((it->second->getFunction()).compare("caregiver") == 0)
    //             {
    //                 outfileWorker2 << *(it->second);
    //             }
    //         }
    //         outfileWorker2.close();
    //     }
    // }
}

Veterinary *Manipulator::findWorkerVet(int id)
{
    try
    {
        Veterinary *person = new Veterinary;
        map<int, Worker *>::iterator it = workers.find(id);
        if ((it->second)->getFunction().compare("caregiver") == 0)
        {
            person = dynamic_cast<Veterinary *>(it->second);
        }
        return person;
    }
    catch (...)
    {
        cout << "Isso não é um Veterinario ou não existe." << endl;
    }
}

Caregiver *Manipulator::findWorkerCare(int id)
{
    try
    {
        Caregiver *person = new Caregiver;
        map<int, Worker *>::iterator it = workers.find(id);
        if ((it->second)->getFunction().compare("caregiver") == 0)
        {
            person = dynamic_cast<Caregiver *>(it->second);
        }
        return person;
    }
    catch (...)
    {
        cout << "Isso não é um Caregiver ou não existe." << endl;
    }
}