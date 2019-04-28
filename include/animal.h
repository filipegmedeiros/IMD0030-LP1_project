#include <string.h>
using std::string;

#include <fstream>
using std::istream;
using std::ostream;

#include "worker.h"

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{
	protected:
		int id;
		string classe;
		string nome_cientifico;
		char sexo;
		double tamanho;
		string dieta;
		veterinario Veterinario;
		tratador Tratador;
		string nome_batismo;
	
	public:
		Animal();
		Animal(int, string, string, char, double, string, veterinario, tratador, string);
		~Animal();
		
		int getId();
		string getClasse();
		string getNome_cientifico();
		char getSexo();
		double getTamanho();
		string getDieta();
		veterinario getVeterinario();
		tratador getTratador();
		string getNome_batismo();
		
		void setId(const int);
		void setClasse(const string);
		void setNome_cientifico(const string);
		void setSexo(const char);
		void setTamanho(const double);
		void setDieta(const string);
		void setVeterinario(const veterinario);
		void setTratador(const tratador);
		void setNome_batismo(const string);
		
	friend istream &operator>>(istream &, Animal &);
	friend ostream &operator<<(ostream &, Animal &);
			
};


#endif
