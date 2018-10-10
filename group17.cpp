#include "group17.h"

Hero initialize(Hero user, string name)
{
    user.name = name;
    user.health = 100;
    user.gold = 0;
    user.key = false;

    return user;
}

Grid generate(Grid area)
{
    area.zone_1 = false;
    area.zone_2 = false;
    area.zone_3 = false;
    area.zone_4 = false;

    return area;
}

int main()
{
    int doorChoice;
    string name;

    cout << "Choose your name: " << endl;
    cin >> name;

    Grid area;
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
                if (user.key == true)
                {
                    area.zone_4 = true;
                    cout << "The magical key unlocks the door, revealing a paradise!" << endl;
                    endGame(&user, &area);
                    break;
                }
                else
                {
                    cout << "You must have a magical key to open this door, try searching around the area!" << endl;
                }
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

bool checkAreaVisited(int target, Grid* area)
{
    if (target == 1)
    {
        if (area->zone_1 == false)
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
        if (area->zone_2 == false)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    if (target == 3)
    {
        if (area->zone_3 == false)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    if (target == 4)
    {
        if (area->zone_4 == false)
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

int playGame(Hero* user, Grid* area, int doorChoice)
{
    // Rooms
    Hero seanRoom;
    Hero jakeRoom;
    Hero afaRoom;

    switch(doorChoice)
    {
        case 1:
            area->zone_1 = true;
            jakeRoom = jgrout(user);
            break;
        case 2:
            area->zone_2 = true;
            seanRoom = ssoberoi(user);
            break;
        case 3:
            area->zone_3 = true;
            afaRoom = afajhan(user);
            break;
        default:
            cout << "Nonexistent room, please try again!" << endl;
            break;
    }

    if ((area->zone_1 == true) && (area->zone_2 == true) && (area->zone_3 == true))
    {
        giveKey(user);
    }

    return 0;
}

int giveKey(Hero* user)
{
    cout << "After visiting all three rooms, a magical key appears before you!" << endl;
    user->key = true;

    return 0;
}

int endGame(Hero* user, Grid* area)
{
    cout << "========== RESULTS ============" << endl;

    cout << "Health: " << user->health << endl;
    cout << "Gold: " << user->gold << endl;
    cout << "Key: " << user->key << endl;

    cout << "You " << getAction(area->zone_1)  << " room 1." << endl;
    cout << "You " << getAction(area->zone_2)  << " room 2." << endl;
    cout << "You " << getAction(area->zone_3)  << " room 3." << endl;
    cout << "You " << getAction(area->zone_4)  << " room 4." << endl;

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