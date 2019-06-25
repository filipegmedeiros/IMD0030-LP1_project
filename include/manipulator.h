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
#include "animal.h"
#include "worker.h"

#include "veterinary.h"
#include "caregiver.h"
#include "exoticAmphibian.h"
#include "exoticReptile.h"
#include "exoticBird.h"
#include "exoticMammal.h"

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include <map>
using std::map;

#include <vector>
using std::pair;
using std::vector;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ostream;

#include <limits>

class Manipulator
{
protected:
    map<int, Animal *> animals;
    map<int, Worker *> workers;

    const vector<string> separate(const string s, const char c);
    void loadArchives();

    bool checkId(int);

    void addWorker();

    void addAnimal();

    void searchWorker();
    void searchAnimal();

    void changeAnimal();

    void removeAnimal();
    void removeWorker();

    void listWorkers();
    Worker* findWorker(int, int);

public:
};

#endif
