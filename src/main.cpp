/*!
 *	@file		main.cpp
 *	@brief	Função Principal
 *	@author	Filipe Medeiros
 *	@date		05/05/2019
 *	@since	02/05/2019
 */

//! Includes and Usings

#include "veterinary.h"
#include "caregiver.h"
#include "bird.h"

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
  cout << endl;
  //! Testes dos Veterinarios
  Veterinary *ponteiro_vet = new Veterinary(1, "Veterinario", "A", "000.000.000-00", 00, "AB", '-', "Leões", "000000");
  Veterinary vet(2, "Veterinario", "C", "222.222.222-22", 20, "EF", '-', "Leões", "111111");
  //Veterinary vet_padrao();
  //Veterinary *ponteiro_vet_padrao = new Veterinary();

  cout << "\033[1;31mponteiro_vet parametrizado\033[0m " << endl << *(ponteiro_vet) << endl;
  cout << "\033[1;31mvet parametrizado\033[0m " << endl << vet << endl;
  //?cout << "vet_padrao\033[0m " << endl << vet_padrao << endl;
  //?cout << "ponteiro_vet_padrao\033[0m " << endl << *(ponteiro_vet_padrao) << endl;


  //! Testes dos Cuidadores
  Caregiver *ponteiro_care = new Caregiver(1, "Tratador", "B", "111.111.111-11", 10, "CD", '+', "Tigres", 0);
  Caregiver care(2, "Tratador", "D", "333.333.333-33", 30, "GH", '+', "Tigres", 1);
  //Caregiver care_padrao();
  //Caregiver *ponteiro_care_padrao = new Caregiver();
  
  cout << "\033[1;31mponteiro_care parametrizado\033[0m " << endl << *(ponteiro_care) << endl;
  cout << "\033[1;31mcare parametrizado\033[0m " << endl << care << endl;
  //?cout << "care_padrao\033[0m " << endl << care_padrao << endl;
  //?cout << "ponteiro_care_padrao\033[0m " << endl << *(ponteiro_care_padrao) << endl;



  //! Teste do Animal

  Animal *ponteiro_animal = new Animal(1,"Mamifero", "Leão", 'M', 30.0, "Humanos", "B", ponteiro_vet, ponteiro_care);
  Animal animal(2,"Mamifero", "Leão", 'M', 30.0, "Humanos", "A", ponteiro_vet, ponteiro_care);
  
  cout << "\033[1;31mponteiro_animal parametrizado\033[0m " << endl << *(ponteiro_animal) << endl;
  cout << "\033[1;31manimal parametrizado\033[0m " << endl << animal << endl;

  //! Teste Passaro
  Bird *ponteiro_passaro = new Bird(1,"Mamifero", "Leão", 'M', 30.0, "Humanos", "A", ponteiro_vet, ponteiro_care,30,30);
  Bird passaro(1,"Mamifero", "Leão", 'M', 30.0, "Humanos", "B", ponteiro_vet, ponteiro_care,30,30);
  //Bird *ponteiro_passaro = new Bird();
  //Bird *ponteiro_passaro_padrao = new Bird();

  cout << "\033[1;31mponteiro_animal parametrizado\033[0m " << endl << *(ponteiro_passaro) << endl;
  cout << "\033[1;31mpassaro parametrizado\033[0m " << endl << passaro << endl;
  //?cout << "passaro_padrao\033[0m " << endl << care_padrao << endl;
  //?cout << "passaro_care_padrao\033[0m " << endl << *(ponteiro_care_padrao) << endl;

}