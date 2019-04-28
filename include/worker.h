/**
 * @file	worker.h
 * @brief   Classe Worker, Veterinary e Caregiver
 * @author	Filipe Medeiros, Sara Beatriz, Gabriel Medeiros
 * @date	25/04/2019
 */

#include <string>
using std::string;

//! Para usar o Friend
#include <fstream>
using std::istream;
using std::ostream;


#ifndef WORKER_H
#define WORKER_H

/** 
 * @class 	Worker worker.h
 * @brief 	Class Worker
 * @details	Os atributos estão dentro da Struct ID 
 * que contém o nome,cpf a função e a idade. 
 */

class Worker
{
  protected:
	typedef struct id
	{

		int id;
		string function;
		string name;
		string cpf;
		short int age;
		string bloodType;
		char factorRh;

	} Identidy;

  public:
	//! Construtor e Destrutor
	Worker();
	Worker(Worker &Person);
	~Worker();

	//! Metodos Getters
	int getId();
	string getFunction();
	string getName();
	string getCpf();
	short int getAge();
	string getBloodType();
	char getFactorRh();

	//! Metodos Setters
	void setId(int);
	void setFunction(string);
	void setName(string);
	void setCpf(string);
	void setAge(short int);
	void setBloodType(string);
	void setFactorRh(char);

	//! Sobrecargas dos operadores
	friend istream &operator>>(istream &, Worker &);
	friend ostream &operator<<(ostream &, Worker &);
};

/*
 * @class 	Veterinary worker.h
 * @brief 	Template Class Veterinary
 * @details	Os atributos do funcionário são herdados
 * da classe Workers e Animals.
 */


class Veterinary : public Worker, public Animal
{
  public:
	Veterinary();
	~Veterinary();
};

/*
 * @class 	 Caregiver worker.h
 * @brief    Class Caregiver
 * @details	 Os atributos do cuidador/tratador são herdados
 * da classe Workers e Animals.
 */
class Caregiver : public Worker, public Animal
{
  public:
	Caregiver();
	~Caregiver();
};

#endif