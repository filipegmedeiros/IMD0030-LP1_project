#ifndef __ANIMAL_H__
#define __ANIMAL_H__

/*!
 * @file	worker.h
 * @brief	Classe Worker
 * @author	Gabriel Medeiros, Filipe Medeiros
 * @date	02/05/2019
 * @since	28/04/2019
 */

//! Includes and Usings
#include "caregiver.h"
#include "veterinary.h"

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

/*!
 *  @class		Animal animal.h
 *  @brief		Class Animal
 *  @details	Definição da classe Animal
 */

class Animal
{
  protected:
	int id;
	string animalClass;
	string scientificName;
	char sex;
	double size;
	string diet;
	string baptismalName;

	Veterinary *veterinary;
	Caregiver *caregiver;

  public:
	//! Construtor e Destrutor
	Animal::Animal(int, string, string, char, double, string, string, Veterinary *, Caregiver *);
	~Animal();

	//! Metodos Getters
	int getId();
	string getAnimalClass();
	string getScientificName();
	char getSex();
	double getSize();
	string getDiet();
	string getBaptismalName();

	Veterinary *getVeterinary();
	Caregiver *getCaregiver();

	//! Metodos Setters
	void setId(const int);
	void setAnimalClass(const string);
	void setBaptismalName(const string);
	void setSex(const char);
	void setSize(const double);
	void setDiet(const string);

	void setBaptismalName(const string);

	void setVeterinary(Veterinary *);
	void setCaregiver(Caregiver *);
};

#endif