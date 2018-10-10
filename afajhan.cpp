#include "group17.h"

void fightMonster(Hero* protagonist, bool armed);
bool inRange(int value, int upper, int lower);

Hero afajhan(Hero* protagonist)
{
  int choice;
  bool armed;

  cout << "\nYou entered a dark hallway." << endl;

  if (rand() % 2) {
    cout << "You found a machete on the ground with blood stains on it."
      << endl;
    do {
      cout << "Do you want to pick it up?\n\n"
        << "1. Yes\n"
        << "2. No\n\n";
      cin >> choice;
      cin.ignore();

      if (!inRange(choice, 1, 2))
        cout << "\nPlease choose 1 or 2." << endl;
      else if (choice == 1) {
        cout << "\nYou picked up the machete.\n" << endl;
        armed = true;
      }
      else if (choice == 2) {
        cout << "\nSuit yourself.\n" << endl;
        armed = false;
      }
    } while (!inRange(choice, 1, 2));
  }

  if (rand() % 2) {
    do {
      cout << "A howling monster appears before you. Fight it?\n\n"
        << "1. Yes\n"
        << "2. No\n" << endl;
      cin >> choice;
      cin.ignore();

      if (!inRange(choice, 1, 2))
        cout << "Please choose 1 or 2." << endl;
      else if (choice == 1) {
        fightMonster(protagonist);
      }
      else if (choice == 2) {
        cout << "You leave this creepy place." << endl;
      }
    } while (!inRange(choice, 1, 2));
  }

  return *protagonist;
}


void fightMonster(Hero& protagonist)
{
  bool imAlive = true, monsterAlive = true;
  int monsterHealth = 100;
  int damage;
  int choice;

  while (imAlive && monsterAlive) {
    do {
      cout << "1. Attack\n"
        << "2. Flee" << endl;
      cin >> choice;
      cin.ignore();

      if (!inRange(choice, 1, 2)) {
        cout << "Please choose 1 or 2." << endl;
      } else if (choice == 1) {
        cout << "You attacked the monster!" << endl;
        damage = getRandomAmount(15);
        cout << "monster: -" << damage << " health pts." << endl;

      } else if (choice == 2) {
        cout << "The monster attacked you!" << endl;
        damage = getRandomAmount(10);
        cout << "your health: -" << damage << " health pts." << endl;
      }
    } while (!inRange(choice, 1, 2));
  }
}

bool inRange(int value, int lower, int upper)
{
  return ( (value >= lower) && (value <= upper) );
}

