#include "group17.h"

Hero initialize(Hero user, string name)
{
    user.name = name;
    user.health = 100;
    user.gold = 0;
    user.key = false;

    return user;
}

World generate(World area)
{
    area.room1 = false;
    area.room2 = false;
    area.room3 = false;
    area.room4 = false;

    return area;
}

int main()
{
    int doorChoice;
    string name;

    cout << "Choose your name: " << endl;
    cin >> name;

    World area;
    area = generate(area);

    Hero user;
    user = initialize(user, name);

    cout << "You enter a large area with four doors, choose between 1-4 to enter: " << endl;
    cin >> doorChoice;

    if (checkDoorChoice(doorChoice) == true)
    {
        playGame(&user, &area, doorChoice);   
    }

    while(true)
    {
        cout << "You enter a large area with four doors, choose between 1-4 to enter: " << endl;
        cin >> doorChoice;

        if (checkDoorChoice(doorChoice) == true)
        {
            if (doorChoice == 4)
            {
                endGame(&user, &area);
                break;
            }
            else
            {
                // check area is visited already
                if (checkAreaVisited(doorChoice, &area) == false)
                {
                    // room has not been visited yet
                    playGame(&user, &area, doorChoice);
                }
                else
                {
                    cout << "You've already visited this room, please choose another!" << endl;
                }
            }
        }
        else
        {
            break;
        }
    }
}

bool checkAreaVisited(int target, World* area)
{
    if (target == 1)
    {
        if (area->room1 == false)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    if (target == 2)
    {
        if (area->room2 == false)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    return true;
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

int playGame(Hero* user, World* area, int doorChoice)
{
    // Rooms
    Hero seanRoom;
    Hero jakeRoom;

    switch(doorChoice)
    {
        case 1:
            area->room1 = true;
            jakeRoom = jgrout(user);
            break;
        case 2:
            area->room2 = true;
            seanRoom = ssoberoi(user);
            break;
        default:
            cout << "Nonexistent room, please try again!" << endl;
            break;
    }

    return 0;
}

int endGame(Hero* user, World* area)
{
    cout << "========== RESULTS ============" << endl;

    cout << "Health: " << user->health << endl;
    cout << "Gold: " << user->gold << endl;
    cout << "Key: " << user->key << endl;

    cout << "You " << getAction(area->room1)  << " room 1." << endl;
    cout << "You " << getAction(area->room2)  << " room 2." << endl;
    cout << "You " << getAction(area->room3)  << " room 3." << endl;

    cout << "=============================" << endl;

    return 0;
}

string getAction(int val)
{
    if (val == true)
    {
        return "entered";
    }
    else
    {
        return "did not enter";
    }
}