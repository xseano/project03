#include "group17.h"
#define INVENTORY_LEN 2

Hero initialize(Hero user, string name)
{
    user.name = name;
    user.health = 100;
    user.gold = 0;
    user.key = false;

    return user;
}

int main()
{
    // Rooms
    Hero seanRoom;
    Hero jakeRoom;

    // Vars
    int doorChoice;
    bool isValid;
    string name;

    cout << "Choose your name: " << endl;
    cin >> name;

    Hero user;
    user = initialize(user, name);

    cout << "You enter a large area with four doors, choose between 1-4 to enter: " << endl;
    cin >> doorChoice;

    isValid = checkDoorChoice(doorChoice);

    if (isValid == true)
    {
        switch(doorChoice)
        {
            case 1:
                jakeRoom = jgrout(user);
                break;
            case 2:
                seanRoom = ssoberoi(user);
                break;
            default:
                cout << "Invalid choice, exiting now!" << endl;
                break;
        }
    }
}

bool checkDoorChoice(int choice)
{
    if (choice <= 4 || choice >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}