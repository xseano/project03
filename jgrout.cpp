#include "group17.h"

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

Hero openDoor(Hero* protagonist)
{
    cout << "Sitting in the middle of the room is the chest." << endl;
    enterChest2(protagonist);
    
    return *protagonist;
}

Hero enterChest(Hero* protagonist)
{
    int choice;
    int newGold = getRandomAmount(50);
    int newHealth = getRandomAmount(25);

    cout << "You found a health potion and gold sack giving you +" << newHealth << " health pts and +" << newGold << " gold." << endl;

    protagonist->gold += newGold;
    protagonist->health += newHealth;

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
    int newGold = getRandomAmount(50);
    int newHealth = getRandomAmount(25);

    cout << "You found a health potion and gold sack giving you +" << newHealth << " health pts and +" << newGold << " gold." << endl;

    protagonist->gold += newGold;
    protagonist->health += newHealth;

    exitRoom(protagonist);

    return *protagonist;
}