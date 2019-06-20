#ifndef __WORKER_H__
#define __WORKER_H__

/*!
 *	@file	worker.h
 *	@brief	Classe Worker
 *	@author	Filipe Medeiros
 *	@date	02/05/2019
 *	@since	25/04/2019
 */

//! Includes and Usings

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

/*!
 *	@class		Worker worker.h
 *	@brief		Class Worker
 *	@details	Definição da classe Worker e suas classe filhas:
 *  Veterinary e Caregiver. 
 */

class Worker
{
protected:
	virtual ostream &print(ostream &) const = 0;
	virtual void input(istream &);
	int id;
	string function;
	string name;
	string cpf;
	short int age;
	string bloodType;
	char factorRh;
	string specialty;

public:
	//! Construtor e Destrutor

	Worker();
	Worker(int, string, string, string, short int, string, char, string);
	virtual ~Worker() = 0;

	//! Metodos Getters

	int getId();
	string getFunction();
	string getName();
	string getCpf();
	short int getAge();
	string getBloodType();
	char getFactorRh();
	string getSpecialty();

	//! Metodos Setters

	void setId(const int);
	void setFunction(const string);
	void setName(const string);
	void setCpf(const string);
	void setAge(const short int);
	void setBloodType(const string);
	void setFactorRh(const char);
	void setSpecialty(const string);

	//! Sobrecargas dos operadores
	virtual void print() = 0;
	friend istream &operator>>(istream &, Worker &);
	friend ostream &operator<<(ostream &os, const Worker &Person)
	{
		return Person.print(os);
	};
};

#endif