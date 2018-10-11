#include "group17.h"

Hero afajhan(Hero* protagonist)
{
	int choice;
	bool armed;//give the player a chance to fight with a weapon
	string weaponName = "machete";

	cout << "\nYou entered a dark hallway." << endl;

	//being armed will increase the damage to the opponent
	cout << "You found a " << weaponName << " on the ground with blood "
		<< "stains on it."
		<< endl;
	do {
		cout << "\nDo you want to pick it up?\n\n"
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

	do {
		cout << "A howling monster appears before you. Fight it?\n\n"
			<< "1. Yes\n"
			<< "2. No\n" << endl;
		cin >> choice;
		cin.ignore();

		if (!inRange(choice, 1, 2))
			cout << "Please choose 1 or 2." << endl;
		else if (choice == 1) {
			attackMonster(protagonist, armed);
		}
		else if (choice == 2) {
			cout << "You leave this creepy place." << endl;
		}
	} while (!inRange(choice, 1, 2));

	return *protagonist;
}


void attackMonster(Hero* protagonist, bool armed)
{
	bool imAlive = true, monsterAlive = true, flee = false;
	int monsterHealth = 100;
	int damage;
	int choice;

	while (imAlive && monsterAlive && !flee) {
		// make the alive bools false so that the fight loop stops
		if (monsterHealth < 1){
			monsterAlive = false;
			cout << "You killed the monster!\n" << endl;
		}

		if (protagonist->health < 1) {
			imAlive = false;
			cout << "You were killed by the monster.\n" << endl;
		}

		// skip everything below if the code above set either of the alive
		// bool variable to false
		if (imAlive && monsterAlive) {
			do {
				cout << "\nYour turn:\n"
					<< "1. Attack\n"
					<< "2. Flee\n" << endl;
				cin >> choice;
				cin.ignore();

				if (!inRange(choice, 1, 2)) {
					cout << "Please choose 1 or 2." << endl;
				} else if (choice == 1) {

					//You attack first
					cout << "You attacked the monster!" << endl;

					//do more damage if you are armed
					if (armed)
						damage = getRandomAmount(20);
					else
						damage = getRandomAmount(15);

					monsterHealth -= damage;

					cout << "Monster health: " << monsterHealth 
						<< " health pts." << endl;

					// Monster's turn to attack you back
					cout << "\nThe monster attacked you!" << endl;

					damage = getRandomAmount(15);
					protagonist->health -= damage;

					cout << "Your health: " << protagonist->health 
						<< " health pts.\n" << endl;

				} else if (choice == 2) {
					cout << "That was close!\n" << endl;
					flee = true;
				}
			} while (!inRange(choice, 1, 2));
		}
	}
}

bool inRange(int value, int lower, int upper)
{
	return ( (value >= lower) && (value <= upper) );
}

