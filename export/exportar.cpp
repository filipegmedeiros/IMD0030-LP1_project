
#include "exporthelp.h"
using namespace help;

int main( int argc, char* const argv[]){
    

    string save_caregiver = ".data/Caregiver.csv";
    string save_veterinary = ".data/Veterinary.csv";
    string save_animals = ".data/Animal.csv";
    string save_export = ".data/Export.csv";

    map<int, Animal *> animals;
    map<int, Worker *> workers;

    pair <int,string> arg_classe(0,"");
    pair <int,string> arg_vet(0,"");
    pair <int,string> arg_carer(0,"");
 

    int c;

    while(optind < argc)
    {
        if((c = getopt(argc, argv, "cvt")) != -1)
        {
            switch (c)
            {
            case 'c':
				arg_classe.first = 1;
				arg_classe.second = optarg;
                break;

            case 'v':
				arg_vet.first = 1;
				arg_vet.second = optarg;
                break;
        
            case 't':
				arg_carer.first = 1;
				arg_carer.second = optarg;
                break;

            default:
                break;
            }        
        }
        else
        {
            save_export = optarg;
        }
    }

    loadArchives(workers);
	

	//filtros
	if (arg_classe.first != 0)
	{
		if (filtro(workers, animals, "-c", arg_classe.second))
		{
			cout << "Filtro realizado!" << endl;
		}
		else
		{
			cout << "Essa classe não foi registrada ainda ou não existe." << endl;
		}
	}
	if (arg_vet.first != 0)
	{
		if (filtro(workers, animals, "-v", arg_vet.second))
		{
			cout << "Filtro realizado!" << endl;
		}
		else
		{
			cout << "Esse veterinário não cuida de animal algum ou não existe." << endl;
		}
	}
	if (arg_carer.first != 0)
	{
		if (filtro(workers, animals, "-t", arg_carer.second))
		{
			cout << "Filtro realizado!" << endl;
		}
		else
		{
			cout << "Esse cuidador não cuida de animal algum ou não existe." << endl;
		}
	}

	if (exportarArquivo(workers, animals, save_export))
	{
		cout << endl;
		cout << "Arquivo salvo com sucesso!" << endl;

		workers.clear();
		animals.clear();
	}
	else
	{
		cerr << "Something on the way went wrong" << endl;
		return -1;
	}

	return 0;
}