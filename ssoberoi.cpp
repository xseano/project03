#include "group17.h"

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
    int damage = getRandomAmount(60);

    cout << "The monster scraped your leg while you were trying to escape! You lost " << damage << " pts of health!" << endl;

    protagonist->health -= damage;

    exitRoom(protagonist);

    return *protagonist;
}

Hero openChest(Hero* protagonist)
{
    int newGold = getRandomAmount(50);
    int newHealth = getRandomAmount(25);
    
    cout << "Opening the chest, you find a health potion and gold sack giving you +" << newHealth << " health pts and +" << newGold << " gold." << endl;

    protagonist->gold += newGold;
    protagonist->health += newHealth;

    exitRoom(protagonist);

    return *protagonist;
}