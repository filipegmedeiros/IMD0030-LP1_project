/*!
 *	@file		main.cpp
 *	@brief	Função Principal
 *	@author	Filipe Medeiros
 *	@date		05/05/2019
 *	@since	02/05/2019
 */

//! Includes and Usings

#include "nativeBird.h"
#include "nativeAmphibian.h"
#include "nativeMammal.h"
#include "nativeReptile.h"
#include "exoticReptile.h"
#include "manipulator.h"
#include "orchestrator.h"

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
  Orchestrator newPetshop;
  newPetshop.menu();
}