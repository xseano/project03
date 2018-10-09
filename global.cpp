#include "group17.h"

Hero exitRoom(Hero* protagonist)
{
    cout << "You exit the room with " << protagonist->health << " health and " << protagonist->gold << " gold." << endl;

    return *protagonist;
}

bool validateChoice(int options[], int choice)
{
    if (choice == option1 || choice == option2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getRandomAmount(int max)
{
    return (rand() % max + 1);
}