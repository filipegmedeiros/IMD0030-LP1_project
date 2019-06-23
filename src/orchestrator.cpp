
#include "orchestrator.h"

Orchestrator::Orchestrator()
    : loop(true)
{
}

void Orchestrator::menu()
{
    while (this->loop)
    {
        cout << "Enter a matching number:" << endl
             << "[1] Register employee" << endl
             << "[2] Register animal" << endl
             << "[3] Remove animal" << endl
             << "[4] Remove employee" << endl
             << "[5] Query an animal" << endl
             << "[6] Query Employee" << endl
             << "[7] Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            loadArchives();
            addWorker();
            break;
        }
        case 2:
        {
            loadArchives();
            addAnimal();
            break;
        }
        case 4:
        {
            removeWorker();
            break;
        }
        case 7:
        {
            this->loop = false;
            break;
        }

        default:
            cout << "Invalid Option" << endl;
            break;
        }
    }
}