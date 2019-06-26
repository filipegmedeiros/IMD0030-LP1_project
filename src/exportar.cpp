
#include "exporthelp.h"

int main( int argc, char* const argv[]){
    

    string save_caregiver = ".data/Caregiver.csv";
    string save_veterinary = ".data/Veterinary.csv";
    string save_animals = ".data/Animal.csv";
    string save_export = ".data/Export.csv";

    map<int, Animal *> animals;
    map<int, Worker *> workers;

    string arg_classe;
    string arg_vet;
    string arg_carer;
    /*
    pair<int, string> arg_classe(0,"");
    pair<int, string> arg_vet(0,"");
    pair<int, string> arg_carer(0,"");
    */

    int c;

    while(optind < argc)
    {
        if((c = getopt(argc, argv, "cvt")) != -1)
        {
            switch (c)
            {
            case 'c':
                arg_classe = optarg;
                break;

            case 'v':
                arg_vet = optarg;
                break;
        
            case 't':
                arg_carer = optarg;
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



/*  Tipo antigo de checagem de argumentos.
    if(argc != 2 && argc != 4 && argc != 6 && argc != 8)
    {
        cerr << "ERROR: Incorrect number of arguments!" << endl;
        cout << "HOW TO USE: ./exportar.exe -c <class> -v <veterinary> -t <caregiver> <outfile name>" << endl;
        return -1;
    }else{
        save_export = argv[argc - 1];

        if(argc >= 4)
        {
            int i = 1;
            while(i < argc-1)
            {
                string arg_comp = argv[i];
                if(arg_comp == "-c")
                {
                    arg_classe.first = i;
                    arg_classe.second = argv[i+1];
                }else
                if(arg_comp == "-v")
                {
                    arg_vet.first = i;
                    arg_vet.second = argv[i+1];
                }else
                if(arg_comp == "-t")
                {
                    arg_carer.first = i;
                    arg_carer.second = argv[i+1];
                }

                i+=2;
            }

            if(arg_classe.first == 0 && arg_vet.first == 0 && arg_carer.first == 0)
            {
                cerr << "ERROR: Wrong parameters!" << endl;
                cout << "HOW TO USE: ./exportar.exe -c <class> -v <veterinary> -t <caregiver> <outfile name>" << endl;
                return -1;
            }
        }
    }*/

    help::loadArchives(workers);

    /* Falta:
        - Dar load no map de animais
        - Fazer os filtros
        - Exportação em sí
     */

}