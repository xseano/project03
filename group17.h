#ifndef GROUP17_H
#define GROUP17_H
#define ROOM_LEN 4

#include <iostream>
using namespace std;


struct Hero
{
    string name;
    int health;
    int gold;
    bool key;
};

struct World
{
    bool room1;
    bool room2;
    bool room3;
    bool room4;
};

Hero jgrout(Hero* protagonist);
Hero ssoberoi(Hero* protagonist);
Hero afajhan(Hero* protagonist);
Hero initialize(Hero hero, string name);

// Main
int playGame(Hero* protagonist, World* area, int doorChoice);
int endGame(Hero* protagonist, World* area);
bool checkDoorChoice(int choice);
string getAction(int val);

// Global
int getRandomAmount(int max);
Hero exitRoom(Hero* protagonist);

//Jake
Hero openDoor(Hero* protagonist);
bool checkChoice(int option1, int option2, int option3, int choice);
Hero enterChest(Hero* protagonist);
Hero enterChest2(Hero* protagonist);

// Sean
Hero openChest(Hero* protagonist);
Hero fightMonster(Hero* protagonist);
Hero fleeScene(Hero* protagonist);
bool validateChoice(int option1, int option2, int choice);

#endif