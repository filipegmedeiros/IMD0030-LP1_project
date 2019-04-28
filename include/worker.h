/*!
 * @file	worker.h
 * @brief   Classe Worker, Veterinary e Caregiver
 * @author	Filipe Medeiros, Sara Beatriz, Gabriel Medeiros
 * @date	25/04/2019
 */

#include <animal.h>

#include <string>
using std::string;

//! Para usar o Friend
#include <fstream>
using std::istream;
using std::ostream;

#ifndef WORKER_H
#define WORKER_H

/*!
 *  @class 	Worker worker.h
 * @brief 	Class Worker
 * @details	Os atributos estão dentro da Struct ID 
 * que contém o nome,cpf a função e a idade. 
 */

class Worker
{
  protected:
	int id;
	string function;
	string name;
	string cpf;
	short int age;
	string bloodType;
	char factorRh;
	string Specialty;

  public:
	//! Construtor e Destrutor
	Worker();
	Worker(int, string, string, string, short int, string, char, string);
	~Worker();

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
	friend istream &operator>>(istream &, Worker &);
	friend ostream &operator<<(ostream &, Worker &);
};

/*!
 *  @class 	Veterinary worker.h
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

/*!
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