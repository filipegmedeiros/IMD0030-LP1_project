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
#include "amphibian.h"

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
  Veterinary *ponteiro_vet_padrao = new Veterinary();

  cout << "\033[44;5m<><><><><><>TESTE DOS VETERINARIOS<><><><><><>\033[0m " << endl << endl;
  cout << "\033[1;41mponteiro_vet parametrizado\033[0m " << endl << *(ponteiro_vet) << endl;
  cout << "\033[1;41mvet parametrizado\033[0m " << endl << vet << endl;
  //?cout << "\033[1;42mvet_padrao\033[0m " << endl << vet_padrao << endl;
  cout << "\033[1;42mponteiro_vet_padrao\033[0m " << endl << *(ponteiro_vet_padrao) << endl;


  //! Testes dos Cuidadores

  Caregiver *ponteiro_care = new Caregiver(1, "Tratador", "B", "111.111.111-11", 10, "CD", '+', "Tigres", 0);
  Caregiver care(2, "Tratador", "D", "333.333.333-33", 30, "GH", '+', "Tigres", 1);
  //Caregiver care_padrao();
  Caregiver *ponteiro_care_padrao = new Caregiver();
  
  cout << "\033[44;5m<><><><><><>TESTE DOS CUIDADORES<><><><><><>\033[0m " << endl << endl;
  cout << "\033[1;41mponteiro_care parametrizado\033[0m " << endl << *(ponteiro_care) << endl;
  cout << "\033[1;41mcare parametrizado\033[0m " << endl << care << endl;
  //?cout << "\033[1;42mcare_padrao\033[0m " << endl << care_padrao << endl;
  cout << "\033[1;42mponteiro_care_padrao\033[0m " << endl << *(ponteiro_care_padrao) << endl;



  //! Teste do Animal

  Animal *ponteiro_animal = new Animal(1,"Mamifero", "Leão", 'M', 30.0, "Humanos", "B", ponteiro_vet, ponteiro_care);
  Animal animal(2,"Mamifero", "Leão", 'M', 30.0, "Humanos", "A", ponteiro_vet, ponteiro_care);
  
  cout << "\033[44;5m<><><><><><>TESTE DOS ANIMAL<><><><><><>\033[0m " << endl << endl;
  cout << "\033[1;41mponteiro_animal parametrizado\033[0m " << endl << *(ponteiro_animal) << endl;
  cout << "\033[1;41manimal parametrizado\033[0m " << endl << animal << endl;

  //! Teste Passaro
  Bird *ponteiro_passaro = new Bird(1,"Bird", "Leão", 'M', 30.0, "Humanos", "A", ponteiro_vet, ponteiro_care,30,30);
  Bird passaro(1,"Bird", "Passaro", 'M', 30.0, "Humanos", "B", ponteiro_vet, ponteiro_care,30,30);
  //Bird passaro_padrao();
  Bird *ponteiro_passaro_padrao = new Bird();

  cout << "\033[44;5m<><><><><><>TESTE DOS PASSAROS<><><><><><>\033[0m " << endl << endl;
  cout << "\033[1;41mponteiro_passaro parametrizado\033[0m " << endl << *(ponteiro_passaro) << endl;
  cout << "\033[1;41mpassaro parametrizado\033[0m " << endl << passaro << endl;
  //?cout << "\033[1;42mpassaro_padrao\033[0m " << endl << passaro_padrao << endl;
  cout << "\033[1;42mponteiro_passaro_padrao\033[0m " << endl << *(ponteiro_passaro_padrao) << endl;



  //! Teste Anfibio
  Amphibian *ponteiro_sapo = new Amphibian(1,"Anfibio", "Sapo", 'M', 30.0, "Humanos", "A", ponteiro_vet, ponteiro_care,30,"setembro");
  Amphibian sapo(1,"Anfibio", "Sapo", 'M', 30.0, "Humanos", "B", ponteiro_vet, ponteiro_care,30,"aaa");
  //Amphibian sapopadrao();
  Amphibian *ponteiro_sapo_padrao = new Amphibian();

  cout << "\033[44;5m<><><><><><>TESTE DOS ANFIBIO<><><><><><>\033[0m " << endl << endl;
  cout << "\033[1;41mponteiro_sapo parametrizado\033[0m " << endl << *(ponteiro_sapo) << endl;
  cout << "\033[1;41msapo parametrizado\033[0m " << endl << sapo << endl;
  //?cout << "\033[1;42msapo_padrao\033[0m " << endl << sapopadrao << endl;
  cout << "\033[1;42mponteiro_sapo_padrao\033[0m " << endl << *(ponteiro_sapo_padrao) << endl;

}