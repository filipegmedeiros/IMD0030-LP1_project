#ifndef __CAREGIVER_H__
#define __CAREGIVER_H__

/*!
 *	@file		caregiver.h
 *	@brief	Classe Caregiver
 *	@author	Filipe Medeiros
 *	@date		02/05/2019
 *	@since	02/05/2019
 */

//! Includes and Usings

#include <worker.h>

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;
using std::endl;

/*!
 *	@class		Caregiver caregiver.h
 *	@brief		Class Caregiver
 *	@details	Os atributos do cuidador/tratador são herdados
 *	da classe Workers.
 */
class Caregiver : public Worker
{

private:
  int securityLevel;
  ostream& print(ostream& os)const{
    return os << id << ";"
              << name << ";"
              << cpf << ";"
              << age << ";"
              << bloodType << ";"
              << factorRh << ";"
              << specialty << ";" 
              << securityLevel << ";" << endl;
  }
public:
  //! Construtor e Destrutor
  Caregiver();
  Caregiver(int, string, string, string, short int, string, char, string, int);
  ~Caregiver();

  //! Metodos Getters

  int getSecurityLevel();

  //! Metodos Setters

  void setSecurityLevel(int);

  //! Sobrecargas dos operadores
  void print();
  friend istream &operator>>(istream &, Caregiver &);
  friend ostream &operator<<(ostream &, Caregiver &);
};

#endif