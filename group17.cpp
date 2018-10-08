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
    string name;

    cout << "Choose your name: " << endl;
    cin >> name;

    Hero user;
    user = initialize(user, name);

    Hero sean;
    sean = ssoberoi(sean);

    Hero jake;
    jake = jgrout(jake);

    Hero ahmad;
    ahmad = afajhan(ahmad);

}