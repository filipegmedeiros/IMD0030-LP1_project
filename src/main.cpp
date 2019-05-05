/*!
 *	@file		main.cpp
 *	@brief	Função Principal
 *	@author	Filipe Medeiros
 *	@date		05/05/2019
 *	@since	02/05/2019
 */

//! Includes and Usings

#include <veterinary.h>
#include <caregiver.h>
#include <animal.h>

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;


/*!
 * @file	main.cpp
 * @brief testes implementações do PetFera
 * @author	Filipe Medeiros
 * @since	05/04/2019
 * @date	05/04/2019
 */
int main(void)
{
  Veterinary *Vet = new Veterinary(1, "Veterinario", "Jon", "000.000.000-00", 10, "AB", '-', "Leões");
  Caregiver *Care = new Caregiver(2, "Tratador", "Snow", "111.111.111-11", 20, "CD", '+', "Tigres");
  Caregiver Caregiver(3, "Veterinario", "Thuize", "222.222.222-22", 30, "EF", '-', "Gatos");
 
  cout << "Vet 01) " << endl << *(Vet) << endl;
  cout << "Vet 02) " << endl << *(Care) << endl;
  cout << "Vet 03) " << endl << Caregiver << endl;


  Animal Lion(1,"Mamifero", "Leão", 'M', 30.0, "Humanos", "Filipolino", Vet, Care);

  cout << "Animal 01) " << endl << Lion << endl;
}