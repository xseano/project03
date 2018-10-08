#include <iostream>
#include "group17.h"

using namespace std;

Hero ssoberoi(Hero* protagonist)
{
    int choice;
    bool isValid;

    cout << "You entered a dark spooky room, there's a monster and a chest, to unlock the chest you must fight the monster (1) or you may leave the room through the door you came in (2): " << endl;
    cin >> choice;

    isValid = validateChoice(1, 2, choice);

    if (isValid == true)
    {
        switch(choice)
        {
            case 1:
                fightMonster(protagonist);
                break;
            case 2:
                fleeScene(protagonist);
                break;
            default:
                break;
        }
    }

    return *protagonist;
};

bool validateChoice(int option1, int option2, int choice)
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

Hero fightMonster(Hero* protagonist)
{
    cout << "You defeated the monster but at the expense of 30 health points!" << endl;
    protagonist->health -= 30;
    cout << "Your current health now is " << protagonist->health << "!" << endl;

    openChest(protagonist);

    return *protagonist;
}

Hero fleeScene(Hero* protagonist)
{
    cout << "The monster scraped your leg while you were trying to escape! Oh no!" << endl;
    protagonist->health -= 10;
    exitRoom(protagonist);

    return *protagonist;
}

Hero openChest(Hero* protagonist)
{
    int newGold = getRandomAmount(50);
    int newHealth = getRandomAmount(25);
    
    cout << "You found a large health potion and small gold sack giving you +" << newHealth <<" health pts and +" << newGold << " gold." << endl;

    protagonist->gold += newGold;
    protagonist->health += newHealth;

    exitRoom(protagonist);

    return *protagonist;
}