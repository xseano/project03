#include "group17.h"

using namespace std;

Hero exitRoom(Hero* protagonist)
{
    cout << "You exit the room with " << protagonist->health << " health and " << protagonist->gold << " gold." << endl;

    return *protagonist;
}

int getRandomAmount(int max)
{
    return (rand() % max + 1);
}