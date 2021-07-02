#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

string items;
string inventory;

void Inventory() {
	ifstream myfile("items.txt");

	if (myfile.is_open()) {
		while (getline(myfile, inventory)) {
			cout << inventory << '\n';
		}
		myfile.close();
	}
	else cout << "Unable to open file";

}

int main()
{
	int hpe = 20;					// Enemy hitpoints
	int hpy = 20;					// Your hitpoints
	int damage;						// Damage save
	int turn = 0;					// Turn save
	int choicebot = 0;				// Choice save for the bot
	int dodgechance;				// Dodgechance save
	int dodge = 0;					// Checks if you dodge
	int fleechance;					// Fleechance save
	int fleeattempts = 0;			// Modifier for fleeing
	string choiceplayer;			// Choice save for the player
	string choiceinventory;			// Inventory choice save

	cout << "Battle time\n";

	for (int i = 0; i < 100; i++) {
		srand(time(NULL));
		cout << "Your enemy has " << hpe << "amount of hitpoints left\n";
		cout << "You have " << hpy << "amount of hitpoints left\n";
		cout << "Your turn\nAttack, Dodge, Flee, Item \n";
		cin >> choiceplayer;	
		if (choiceplayer == "Attack" || choiceplayer == "attack" || choiceplayer == "A" || choiceplayer == "a") {
			damage = rand() % 6;
			hpe -= damage;
			"\n";
			turn =+ 1;
		}

		if (choiceplayer == "Dodge" || choiceplayer == "dodge" || choiceplayer == "D" || choiceplayer == "d") {
			dodgechance = rand() % 50 + 50;
			if (dodgechance >= 85) {
				cout << " You will dodge the next attack \n";
				dodge == 1;
			}
		}
		if (choiceplayer == "Flee" || choiceplayer == "flee" || choiceplayer == "F" || choiceplayer == "f") {
			if (fleeattempts == 0) {
				fleechance = rand() % 200 + 1;
				fleechance = fleechance / 2;
				if (fleechance > 12.5) {
					cout << "You succesfully flee from the encounter \n";
					break;
				}
				else {
					cout << "You failed to flee from the encounter \n";
					fleeattempts++;
				}

			}
			else {
				fleechance = rand() % 200 + 1;
				fleechance = fleechance / 2;
				for (int i = 0; i < fleeattempts; i++) {
					fleechance + 10;
					}
			}
		}
		if (choiceplayer == "Items" || choiceplayer == "items" || choiceplayer == "I" || choiceplayer == "i") {

			Inventory();
			cin >> choiceinventory;
		}

		if (hpe <= 0) {
			cout << "The enemy is dead\n";
			break;
		}
		if (turn == 1) {
			cout << "Enemy turn\n";
			choicebot == 0;
			if (choicebot == 0) {
				if (dodge == 1) {
				}
				else {
					damage = rand() % 6;
					hpy -= damage;
					"\n";
					turn == 0;
				}
			}
		}
		if (hpy <= 0) {
			cout << "You Died\n";
			break;
		}
	}

	cout << "Encounter over";
}
