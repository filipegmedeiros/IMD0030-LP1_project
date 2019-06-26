#ifndef _EXP_HELP_H_
#define _EXP_HELP_H_
#pragma once

#include <iostream>
using namespace std;

#include <sstream>
#include <fstream>

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#include "worker.h"
#include "veterinary.h"
#include "caregiver.h"
#include "nativeBird.h"
#include "nativeAmphibian.h"
#include "nativeMammal.h"
#include "nativeReptile.h"
#include "exoticReptile.h"
#include "exoticAmphibian.h"
#include "exoticMammal.h"
#include "exoticBird.h"

#include <map>
using std::map;

#include <string>
using std::string;

#include <vector>



namespace help {
    extern "C" void loadArchives(map<int, Worker *> &workers);
    extern "C" void loadAnimals(map<int, Animal *> &animals);
    extern "C" const vector<string> separate(const string s, const char c);

}

#endif