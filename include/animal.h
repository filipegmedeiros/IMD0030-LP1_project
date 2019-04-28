/*!
 * @file	animal.h
 * @brief   Classe Animal, Amphibian, Mammal, Reptile e Bird. 
 * @author	Filipe Medeiros, Sara Beatriz, Gabriel Medeiros
 * @date	25/04/2019
 */

#include <string>
using std::string;

#include <fstream>
using std::istream;
using std::ostream;

#include "worker.h"

#ifndef ANIMAL_H
#define ANIMAL_H

/*!
 *  @class 	Animal animal.h
 * @brief 	Class Animal
 * @details	Definição da classe Animal e suas classe filhas:
 *  Amphibian, Mammal, Reptile e Bird. 
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
	Veterinary Veterinary;
	Caregiver Caregiver;
	string baptismalName;

  public:
	//! Construtor e Destrutor
	Animal();
	Animal(int, string, string, char, double, string, Veterinary &, Caregiver &, string);
	~Animal();

	//! Metodos Getters
	int getId();
	string getAnimalClass();
	string getScientificName();
	char getSex();
	double getSize();
	string getDiet();
	string getBaptismalName();

	Veterinary getVeterinary();
	Caregiver getCaregiver();

	//! Metodos Setters
	void setId(const int);
	void setAnimalClass(const string);
	void setBaptismalName(const string);
	void setSex(const char);
	void setSize(const double);
	void setDiet(const string);
	void setVeterinary(const veterinario &);
	void setCaregiver(const tratador);
	void setBaptismalName(const string);

	friend istream &operator>>(istream &, Animal &);
	friend ostream &operator<<(ostream &, Animal &);
};

#endif
