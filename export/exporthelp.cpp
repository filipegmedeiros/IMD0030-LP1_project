#include "exporthelp.h"

using namespace std;

namespace help {

void loadArchives(map<int, Worker *> workers)
{
    ifstream fileVeterinary("./data/Veterinary.csv", std::ios::in);
    ifstream fileCaregiver("./data/Caregiver.csv", std::ios::in);
    string str;
    vector<string> v;

    if(fileVeterinary){
        while(!fileVeterinary.eof()){
            getline(fileVeterinary, str);
            if(str == "") continue;
            v = separate(str,';');
           
            
            if(v[1] == "veterinary")
            {
                workers.insert( pair<int, Worker*>(stoi(v[0]), new Veterinary(stoi(v[0]), v[1], v[2], v[3], (short)stoi(v[4]), v[5], v[6][0], v[7], v[8])));
            }
            

            v.clear();
        }
    }
        fileVeterinary.close();
        if(fileCaregiver)
        {
            while(!fileCaregiver.eof()){
                getline(fileCaregiver, str);
                if(str == "") continue;
                v = separate(str,';');
            
                    if(v[1] == "caregiver")
                    {
                        workers.insert( pair<int, Worker*>(stoi(v[0]), new Caregiver(stoi(v[0]), v[1], v[2], v[3], (short)stoi(v[4]), v[5], v[6][0], v[7], stoi(v[8]))));
                    }
                v.clear();
            }
            fileCaregiver.close();
        }
        else
        {
            cout << "Files empty." << endl;
        }
}

/* 
void loadAnimals(map<int, Animal *> &animals)
{
    ifstream fileAnimals("./data/Animals.csv", std::ios::in);
    string str;
    vector <string> v;

    if(fileAnimals)
    {
        while(!fileAnimals.eof())
        {
            getline(fileAnimals, str);
            if(str == "") continue;
            v = separate(str, ';');

			Worker* vetinho = nullptr;
			Worker* carerinho = nullptr;
			if(v[1] == "exotic amphibian")
			{
				animals.insert(pair<int, Animal*>(stoi(v[0])), new exoticAmphibian(stoi(v[0]), v[1], v[2], v[3], stod(v[4]), v[5], v[6], vetinho!=nullptr?vetinho:0, carerinho!=nullptr?carerinho:0, stoi(v[9]), v[10], v[11], v[12]));
			}
			
			
			v.clear();

        }
		fileAnimals.close();
    }
	else
	{
		cout << "File empty." << endl;
	}
}
*/

const vector<string> separate(const string s, const char c)
{
    string buff{""};
		vector<string> v;
		
		for(auto n:s)
		{
			if(n != c) buff+=n; else
			if(n == c) { v.push_back(buff); buff = ""; }
		}
		if(buff != "") { v.push_back(buff); buff = ""; }
		
		return v;
}

bool filtro(map<int, Worker*> &workers, map<int, Animal *> &animals, string tipo, string valor)
{
	bool retorno = false;

	for (map<int, Animal*>::iterator it = animals.begin(); it != animals.end(); it++)
	{
		if (tipo == "-v" && it->second->getVeterinary() != nullptr)
		{
			string lol = it->second->getVeterinary()->getName();
			transform(lol.begin(), lol.end(), lol.begin(), ::tolower);
			transform(valor.begin(), valor.end(), valor.begin(), ::tolower);

			if (lol.find(valor) != std::string::npos)
			{
				retorno = true;
			}
			else
			{
				animals.erase(it);
			}
		}
		else 
		if (tipo == "-t" && it->second->getCaregiver() != nullptr)
		{
			string lel = it->second->getCaregiver()->getName();
			transform(lel.begin(), lel.end(), lel.begin(), ::tolower);
			transform(valor.begin(), valor.end(), valor.begin(), ::tolower);

			if (lel.find(valor) != std::string::npos)
			{
				retorno = true;
			}
			else
			{
				animals.erase(it);
			}
		}
		else
		if (tipo == "-c")
		{
			string lil = it->second->getAnimalClass();
			transform(lil.begin(), lil.end(), lil.begin(), ::tolower);
			transform(valor.begin(), valor.end(), valor.begin(), ::tolower);

			if (lil.find(valor) != std::string::npos)
			{
				retorno = true;
			}
			else
			{
				animals.erase(it);
			}
		}
	}
	
	return retorno;
}

bool exportarArquivo(map<int, Worker*> workers, map<int, Animal*> animals, string save_export)
{
	ofstream animal_file;
	animal_file.open(save_export, ios::out | ios::trunc);

	if (animal_file)
	{
		for (map<int, Animal*>::iterator it = animals.begin(); it != animals.end(); it++)
		{
			animal_file << *(it->second);
		}
		animal_file.close();
	}
	else
	{
		cerr << "ERROR: N�o foi poss�vel abrir o arquivo." << endl;
		return false;
	}

	return true;
}

}