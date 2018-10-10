#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

#ifndef GROUP17_H
#define GROUP17_H

#define ROOM_LEN 4
#define INVENTORY_LEN 2

struct Hero
{
    string name;
    int health;
    int gold;
    bool key;
};

struct Grid
{
    bool zone_1;
    bool zone_2;
    bool zone_3;
    bool zone_4;
};

Hero jgrout(Hero* protagonist);
Hero ssoberoi(Hero* protagonist);
Hero afajhan(Hero* protagonist);
Hero initialize(Hero hero, string name);

// Main
int playGame(Hero* protagonist, Grid* area, int doorChoice);
int endGame(Hero* protagonist, Grid* area);
bool checkDoorChoice(int choice);
bool checkAreaVisited(int target, Grid* area);
string getAction(int val);

// Global
int getRandomAmount(int max);
bool validateChoice(vector<int>, int choice);
Hero exitRoom(Hero* protagonist);

//Jake
Hero openDoor(Hero* protagonist);
Hero enterChest(Hero* protagonist);
Hero enterChest2(Hero* protagonist);

// Sean
Hero openChest(Hero* protagonist);
Hero fightMonster(Hero* protagonist);
Hero fleeScene(Hero* protagonist);

#endif