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
            animals.insert()

        }
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

}