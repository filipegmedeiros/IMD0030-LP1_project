/*!
 *	@file		main.cpp
 *	@brief	Função Principal
 *	@author	Filipe Medeiros
 *	@date		05/05/2019
 *	@since	02/05/2019
 */

//! Includes and Usings

#include "exoticBird.h"
#include "exoticAmphibian.h"
#include "exoticMammal.h"


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

  //! Vet e Cuidador Testes
  Veterinary *ponteiro_vet = new Veterinary(1, "Veterinario", "A", "000.000.000-00", 00, "AB", '-', "Leões", "000000");
  Caregiver *ponteiro_care = new Caregiver(1, "Tratador", "B", "111.111.111-11", 10, "CD", '+', "Tigres", 0);

  //! Teste Passaro Exotico
  exoticBird *Bird = new exoticBird(0, "teste", "teste", 'c', 20.0, "string", "strin2", ponteiro_vet, ponteiro_care, 30.0, 15.0, "string", "aqui é oq?");
  exoticBird *Bird2 = new exoticBird();
  //cout << "teste: " << Bird->getBirthPlace() << endl;

  cout << "\033[44;5m<><><><><><>TESTE DOS PASSAROS EXOTICOS<><><><><><>\033[0m " << endl << endl;
  cout << "\033[1;41mExoticBird parametrizado\033[0m " << endl << *(Bird) << endl;
  cout << "\033[1;41mExoticBird Padrão\033[0m " << endl << *(Bird2) << endl;

  //! Teste Anfibio Exotico
  exoticAmphibian *Anfibio = new exoticAmphibian(0,"string","string",'c',2,"string","string",ponteiro_vet,ponteiro_care,2,"a","a","a");
  exoticAmphibian *Anfibio2 = new exoticAmphibian();

  cout << "\033[44;5m<><><><><><>TESTE DOS ANFIBIOS EXOTICOS<><><><><><>\033[0m " << endl << endl;
  cout << "\033[1;41mAnfibioExotico parametrizado\033[0m " << endl << *(Anfibio) << endl;
  cout << "\033[1;41mAnfibioExotico Padrão\033[0m " << endl << *(Anfibio2) << endl;

  //! Teste Mamifero Exotico
  exoticMammal *Mamifero = new exoticMammal(0, "teste", "teste", 'c', 20.0, "string", "strin2", ponteiro_vet, ponteiro_care,"string","string","string");
  exoticMammal *Mamifero2 = new exoticMammal();

  cout << "\033[44;5m<><><><><><>TESTE DOS MAMIFEROS EXOTICOS<><><><><><>\033[0m " << endl << endl;
  cout << "\033[1;41mMamiferoExotico parametrizado\033[0m " << endl << *(Mamifero) << endl;
  cout << "\033[1;41mMamiferoExotico Padrão\033[0m " << endl << *(Mamifero2) << endl;

}