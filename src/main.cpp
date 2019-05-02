/*!
 * @file		main.cpp
 * @brief		Função Principal
 * @author		Filipe Medeiros
 * @date		02/05/2019
 * @since		02/05/2019
 */

//! Includes and Usings

#include <veterinary.h>
#include <caregiver.h>


#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main(void)
{
    Veterinary Vet(01, "Veterinarian", "Jon", "000.000.000-00", 10, "AB", '-', "Lions");
    Caregiver Care(02, "Caregiver", "Snow", "111.111.111-11", 20, "CD", '+', "Leoas");

    cout << Vet << Care << endl;

}