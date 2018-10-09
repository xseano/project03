#include "group17.h"

Hero exitRoom(Hero* protagonist)
{
    cout << "You exit the room with " << protagonist->health << " health and " << protagonist->gold << " gold." << endl;

    return *protagonist;
}

bool validateChoice(vector<int> options, int choice)
{
    bool inRange = find(begin(options), end(options), choice) != end(options);

    if (inRange)
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