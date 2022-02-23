#include <iostream>
using namespace std;

int strenght = 0;
int intelligence = 0;
int wisdom = 0;
int constitution = 0;
int dexterity = 0;
int charisma = 0;
int points = 28;
string pointchoice;
string choice;


void character_creation(){
	cout << "Put points into stats" << endl;
	for (int i = 0; i < points; i++) {
		cout << "Strenght = " << strenght << endl;
		cout << "Intelligence = " << intelligence << endl;
		cout << "Wisdom = " << wisdom << endl;
		cout << "Constitution = " << constitution << endl;
		cout << "Dexterity = " << dexterity << endl;
		cout << "Charisma = " << charisma << endl;
		cin >> pointchoice;
		if (pointchoice == "S" || pointchoice == "s" || pointchoice == "Strenght" || pointchoice == "strenght") {
			strenght++;
			cout << endl;
		}
		if (pointchoice == "I" || pointchoice == "i" || pointchoice == "Intelligence" || pointchoice == "intelligence") {
			intelligence++;
			cout << endl;
		}
		if (pointchoice == "W" || pointchoice == "w" || pointchoice == "Wisdom" || pointchoice == "wisdom") {
			wisdom++;
			cout << endl;
		}
		if (pointchoice == "Constitution" || pointchoice == "constitution") {
			constitution++;
			cout << endl;
		}
		if (pointchoice == "D" || pointchoice == "d" || pointchoice == "Dexterity" || pointchoice == "dexterity") {
			dexterity++;
			cout << endl;
		}
		if (pointchoice == "Charisma" || pointchoice == "charisma") {
			charisma++;
			cout << endl;
		}
	}
	cout << "all points are spend your stats are the following" << endl;
	cout << "Strenght = " << strenght << endl;
	cout << "Intelligence = " << intelligence << endl;
	cout << "Wisdom = " << wisdom << endl;
	cout << "Constitution = " << constitution << endl;
	cout << "Dexterity = " << dexterity << endl;
	cout << "Charisma = " << charisma << endl;
}

int main() {
	cout << "New or returning player " << endl;
	cin >> choice;
	if (choice == "N" || choice == "n" || choice == "New" || choice == "new") {
		character_creation();
	}
	if (choice == "R" || choice == "r" || choice == "Returning" || choice == "returning") {
		cout << "stat system" << endl;
		cout << "Your Stats" << endl;
		cout << "Strenght = " << strenght << endl;
		cout << "Intelligence = " << intelligence << endl;
		cout << "Wisdom = " << wisdom << endl;
		cout << "Constitution = " << constitution << endl;
		cout << "Dexterity = " << dexterity << endl;
		cout << "Charisma = " << charisma << endl;
	}
}