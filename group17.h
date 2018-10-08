#ifndef GROUP17_H
#define GROUP17_H

#include <iostream>
using namespace std;


struct Hero
{
    string name;
    int health;
    int gold;
    bool key;
};

Hero jgrout(Hero protagonist);
Hero ssoberoi(Hero protagonist);
Hero afajhan(Hero protagonist);
Hero initialize(Hero hero, string name);

//Jake
Hero openDoor(Hero protagonist);
bool checkChoice(int option1, int option2, int option3, int choice);
Hero enterChest(Hero protagonist);
Hero enterChest2(Hero protagonist);
Hero leaveRoom(Hero protagonist);

// Sean
Hero openChest(Hero protagonist);
Hero fightMonster(Hero protagonist);
Hero fleeScene(Hero protagonist);
Hero exitRoom(Hero protagonist);
bool validateChoice(int option1, int option2, int choice);

#endif