#include <iostream>
#include "group17.h"

using namespace std;

Hero jgrout(Hero* protagonist)
{
    int choice;
    bool isValid;

    cout << "You entered a cellar with a chest and two doors. \nYou can open the chest (1), go through the door across from you (2), or leave through the door you came from (3): " << endl;
    cin >> choice;

    isValid = checkChoice(1, 2, 3, choice);

    if (isValid == true)
    {
        switch(choice)
        {
            case 1:
                enterChest(protagonist);
                break;
            case 2:
                openDoor(protagonist);
                break;
            case 3:
                exitRoom(protagonist);
                break;
            default:
                break;
        }
    }
    
    return *protagonist;
};

bool checkChoice(int option1, int option2, int option3, int choice)
{
    if (choice == option1 || choice == option2 || choice == option3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Hero openDoor(Hero* protagonist)
{
    cout << "Sitting in the middle of the room is the chest." << endl;
    enterChest2(protagonist);
    
    return *protagonist;
}

Hero enterChest(Hero* protagonist)
{
    int choice;

    cout << "You found a health potion (5 health pts) and 25 gold, congrats!" << endl;
    protagonist->gold += 25;
    protagonist->health += 5;

    cout << "You can either go through the door across the room (1), or leave through the door you came through (2)."<< endl;
    cin >> choice;

    switch(choice)
    {
        case 1:
            openDoor(protagonist);
            break;
        case 2:
            exitRoom(protagonist);
            break;
        default:
            break;

    }
    
    return *protagonist;
}

Hero enterChest2(Hero* protagonist)
{
    cout << "You found a health potion (10 health pts) and 10 gold, congrats!" << endl;
    protagonist->gold += 10;
    protagonist->health += 10;

    exitRoom(protagonist);

    return *protagonist;
}