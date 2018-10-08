#include "group17.h"
#define INVENTORY_LEN 2
#define ROOM_LEN 4

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
    int doorChoice;
    string name;

    cout << "Choose your name: " << endl;
    cin >> name;

    Hero user;
    user = initialize(user, name);

    cout << "You enter a large area with four doors, choose between 1-4 to enter: " << endl;
    cin >> doorChoice;

    if (checkDoorChoice(doorChoice) == true)
    {
        playGame(&user, doorChoice);   
    }

    while(true)
    {
        cout << "You enter a large area with four doors, choose between 1-4 to enter: " << endl;
        cin >> doorChoice;

        if (checkDoorChoice(doorChoice) == true)
        {
            if (doorChoice == 4)
            {
                endGame(&user);
                break;
            }
            else
            {
                playGame(&user, doorChoice);
            }
        }
        else
        {
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

int playGame(Hero* user, int doorChoice)
{
    // Rooms
    Hero seanRoom;
    Hero jakeRoom;

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

    return 0;
}

int endGame(Hero* user)
{
    cout << "========== RESULTS ============" << endl;

    cout << "Health: " << user->health << endl;
    cout << "Gold: " << user->gold << endl;
    cout << "Key: " << user->key << endl;

    cout << "=============================" << endl;

    return 0;
}