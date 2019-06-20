
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
             << "[1] Registre employee" << endl
             << "[2] Registre animal" << endl
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
            addWorker();
            break;
        }
        case 7:
        {
            this->loop = false;
        }

        default:
            cout << "Invalid Option" << endl;
            break;
        }
    }
}