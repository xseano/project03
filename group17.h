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

#endif