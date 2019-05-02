#ifndef __ANFIBIO_H__
#define __ANFIBIO_H__

/*!
 * @file	anfibio.h
 * @brief	Classe Anfibio
 * @author	Sara Santana
 * @date	02/05/2019
 * @since	02/05/2019
 */

//! Includes and Usings
#include "animal.h"
#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

class Anfibio : public Animal
{
  protected:
    int m_total_mudas;
    string m_ultima_muda;
  public:
    //! Construtor e Destrutor
    Anfibio(int id, string animalClass, string scientificName, char sex, double size, string diet, string baptismalName);
    ~Anfibio();

    //! Metodos Getters
    int getTotalMudas();
    string getUltimaMuda();

    //! Metodos Setters
     void setTotalMudas(int m_total_mudas);
     void setUltimaMuda(string m_ultima_muda);
};

#endif