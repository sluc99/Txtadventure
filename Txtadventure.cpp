#include <iostream>
#include <istream>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

float levelud = 0;
float levellr = 0;
int breakfree = false;
int playerlevel = 1;
int Hpc = 20;
int Hpb = 20;
int Hplmod;
int lvlmod [10] = {8, 15, 22, 29, 36, 43, 50 };
int lvl = 1;
int experience;
int levelexp = 0;
int swordansweri = false;
int swordanswerc;
int inventoryids[12];
int inventorydesc[12];
int isize = 12;
int inventoryamount[12];

string Items[13] = { "-----","Health potion", "Gold"};
string direction;
string exitgame = "The game will exit. Goodbye ";
string credits = "Thanks for playing the game ";
string saving = "Saving game do not exit ";
string playername;						// playername save
string positionload;					// loading gamesave
string exitsave;						// making save on exit
string player;							// playername in save file
string gender;							// gender save
string gendername;						// gendername in save file
string swordanswers;					// swordanswer for first battle

void slowSentence(string sentence) {
	for (int i = 0; i < sentence.length(); i++) {
		std::cout << sentence[i];
		Sleep(1);
	}
}

void HplmodCalc() {
	Hplmod = lvlmod[lvl];
}

void HpLevel() {
	Hpc = Hpb + Hplmod;
}

void Credits() {
	system("CLS");
	slowSentence(credits);
	slowSentence(playername);
	//slowSentence(credits2);
	exit (0);
}

void InventoryidSave() {
	ofstream inventoryIds("iids.txt");
	if (inventoryIds.is_open()) {
		cout << "itemSave file is open";
		for (int i = 0; i < isize; i++) {
			inventoryIds << inventoryids[i] << "\n";
		}
		inventoryIds.close();
	}
	else {
		cout << "itemsave file not found";
	}

}

void InventoryamountSave() {
	ofstream inventoryIds("ia.txt");
	if (inventoryIds.is_open()) {
		cout << "itemamount file is open";
		for (int i = 0; i < isize; i++) {
			inventoryIds << inventoryamount[i] << "\n";
		}
		inventoryIds.close();
	}
	else {
		cout << "itemamount file not found";
	}

}

void NameSave() {
	ofstream namefile("namesave.txt");
	if (namefile.is_open()) {
		cout << "namesave file is open";
		namefile << playername << endl;
		namefile.close();
	}
	else {
		cout << "namesave file not found";
	}
}

void PositionSave() {
	vector<double> a = { levelud, levellr };
	ofstream myfile("save.txt");
	if (myfile.is_open()) {
		cout << "save file is open";
		ostream_iterator<double> output_iterator(myfile, "\n");
		copy(a.begin(), a.end(), output_iterator);
		myfile.close();
	}
	else {
		cout << "save file not found";
	}
}

void GenderSave() {
	ofstream genderfile("gendersave.txt");
	if (genderfile.is_open()) {
		cout << "gendersave file is open";
		genderfile << gender << endl;
		genderfile.close();
	}
}


void MainSave() {
	PositionSave();
	NameSave();
	GenderSave();
	InventoryidSave();
}

void Exit() {
	cout << "Before you leave do you want to save ";
	cin >> exitsave;
	if (exitsave == "y" || exitsave == "Y" || exitsave == "Yes" || exitsave == "yes") {
		slowSentence(saving);
		MainSave();
		slowSentence(exitgame);
		exit (0);
	}
	else {
		slowSentence(exitgame);
		exit (0);
	}
}

void MoveDirection() {
	if (direction == "N" || direction == "North" || direction == "n" || direction == "north") {
		levelud += 1;
	}
	if (direction == "E" || direction == "East" || direction == "e" || direction == "east") {
		levellr += 1;
	}
	if (direction == "S" || direction == "South" || direction == "s" || direction == "South") {
		levelud -= 1;
	}
	if (direction == "W" || direction == "West" || direction == "w" || direction == "west") {
		levellr -= 1;
	}
	if (direction == "save" || direction == "Save") {
		MainSave();
	}
	if (direction == "Exit" || direction == "exit") {
		Exit();
	}
	if (direction == "Inventory" || direction == "I" || direction == "inventory" || direction == "i") {
		for (int i = 0; i < 12; i++) {
			cout << inventoryids[i];
			cout << inventoryamount[i];
		}
	}
	if (direction == "Position" || direction == "Pos" || direction == "P" || direction == "position" || direction == "pos" || direction == "p") {
		cout << "X position" << levellr << "Y position" << levelud;
	}
}

void InventoryLoad() {
	vector<double> newVector;
	ifstream inventoryIds("iids.txt");
	double idcall;
	while (inventoryIds >> idcall) 
	{
		newVector.push_back(idcall);
	}
	if (inventoryIds.is_open()) {
		if (newVector.size() > 12) {
		}
		inventoryIds.close();
		inventoryids[0] = newVector[0];
		inventoryids[1] = newVector[1];
		inventoryids[2] = newVector[2];
		inventoryids[3] = newVector[3];
		inventoryids[4] = newVector[4];
		inventoryids[5] = newVector[5];
		inventoryids[6] = newVector[6];
		inventoryids[7] = newVector[7];
		inventoryids[8] = newVector[8];
		inventoryids[9] = newVector[9];
		inventoryids[10] = newVector[10];
		inventoryids[11] = newVector[11];
	}
}

void NameLoad() {
	string Name;
	ifstream namefile("namesave.txt");
	if (namefile.is_open()) {
		while (getline(namefile, Name)) {
			playername = Name;
		}
		namefile.close();
	}
	else {
		cout << "file not found";
	}
}

void GenderLoad() {
	string Gender;
	ifstream genderfile("gendersave.txt");
	if (genderfile.is_open()) {
		while (getline(genderfile, Gender)) {
			gender = Gender;
		}
	}
}

void PositionLoad() {
	vector<double> newVector;
	ifstream myfile("save.txt");
	double tempVar;
	while (myfile >> tempVar)
	{
		newVector.push_back(tempVar);
	}
	if (myfile.is_open()){
		if (newVector.size() > 1) {
		}
		myfile.close();
		levelud = newVector[0];
		levellr = newVector[1];
	}
	else
	{
		cout << "save file not found";
	}
	myfile.close();	
}

void MainLoad() {
	PositionLoad();
	NameLoad();
	GenderLoad();
	InventoryLoad();
}

int main() {

	// strings that are variable
	string confirmgender;					// gender confirmation

	// strings with text

	string chooseadirection = "\nNow choose a direction you want to go. North, East, South, West ";
	string hitawall = "You hit a wall Bonkers ";
	string herasmussendsyouback = "Hello adventurer. you already have been here and there is nothing important for you left here";
	string welcome = "Welcome to this Text adventure game. Please tell me your name. Or if your returning use Load. \n";
	string welcomeplayer1 = "Welcome ";
	string welcomeplayer2 = " to the wonderful world of Athernos.";
	string gender1 = "\nNow tell me are you a boy or a girl. \n";
	string gender2 = "So you are a ";
	string gender3 = " are you sure\n";
	string intro = "My name is Herasmus. I am one of the wizards you'll encounter in this world. Some of them will help you on your way others however. They are bad and will try to get you lost. To the north of here you will find a village in there are a couple of people you can talk too. Should you need any help you can always ask ol herasmus here for tips.";
	string introvillage = "Welcome to Starter village you hear as you walk through the gate. My name is Alisha and i am the daughter of the mayor. What is your name : ";
	string introvillage2 = ". Weird i remember that name vaguely, like i have heard it before. Anyway what does a adventurer like you do in Starter village. I bet you want to meet the mayor luckily he is not busy right now. I'll lead you to him.\nShe starts to walk towards the North.";
	string introvillage3 = "You follow Alisha to the north. After a moment you see a big building with marble pillars. She leads you inside into a office. Inside the office sits a man with a curly mustache. As you look him you see his mustache is getting a little white. As he sits there you hear Alisha say that you are a new adventurer. ";
	string introvillage4 = "A new adventurer you say. Perfect we are in need of help. But before i sent you off i want to see what you are capable off";
	string introvillage5 = "Test your strenght against my guard. He will not go easy on you so be prepared. I will give you these healing potions. Do you happen to have a sword ";
	string battlenosword = "\nOkay then if you have a sword you can use it. Remember my guard won't go easy on you\n";
	string battlegotsword = "\nHonesty will help you a long way in this world. But be carefull not everyone is good.\n";

	// Welcoming sequence with character selection

	slowSentence(welcome);
	for (int i = 0; i < 12; i++) {
		inventoryids[i] == 0;
	}
	cin >> playername;
	if (playername == "Load" || playername == "load" || playername == "L" || playername == "l") {
		MainLoad();
		cout << "Welcome back " << playername;
	}
	int i_levelud = levelud;
	int i_levellr = levellr;
	if (i_levelud == 0 && i_levellr == 0) {
		slowSentence(welcomeplayer1);
		slowSentence(playername);
		slowSentence(welcomeplayer2);
		for (int i = 0; i < 100; i++) {
			slowSentence(gender1);
			std::cin >> gender;
			if (gender == "boy" || gender == "Boy" || gender == "girl" || gender == "Girl") {
				slowSentence(gender2);
				slowSentence(gender);
				slowSentence(gender3);
				std::cin >> confirmgender;
				if (confirmgender == "yes" || confirmgender == "Yes") {
					break;
				}
				else if (confirmgender == "no" || confirmgender == "No") {
					cout << " So you are not a " << gender;
				}
			}
		}


		// Intro sequence with first village

		slowSentence(intro);
		for (int i = 0; i < 100; i++) {
			slowSentence(chooseadirection);
			cin >> direction;
			MoveDirection();
			if (levelud == 1) {
				slowSentence(introvillage);
				break;
			}
			if (levellr == 1) {
				slowSentence(hitawall);
				levellr--;
			}
			if (levelud == -1) {
				slowSentence(hitawall);
				levelud--;
			}
			if (levellr == -1) {
				slowSentence(hitawall);
				levellr++;
			}
		}
		slowSentence(playername);
		slowSentence(introvillage2);
	}

		for (int i = 0; i < 100; i++)
		{
			slowSentence(chooseadirection);
			cin >> direction;
			MoveDirection();
			if (levelud == 2) {
				slowSentence(introvillage3);
				breakfree = true;
				break;
			}
			if (levellr == 1) {
				slowSentence(hitawall);
				levellr--;
			}
			if (levelud == 0) {
				slowSentence(herasmussendsyouback);
				levelud++;
			}
			if (levellr == -1) {
				slowSentence(hitawall);
				levellr++;
			}
		}

		slowSentence(introvillage4);
		slowSentence(introvillage5);


		while (swordansweri == false) {
			cin >> swordanswers;
			if (swordanswers == "Yes" || swordanswers == "Y" || swordanswers == "yes" || swordanswers == "y") {
				swordansweri = true;
				swordanswerc = 1;
			}
			if (swordanswers == "No" || swordanswers == "N" || swordanswers == "no" || swordanswers == "n") {
				swordansweri = true;
				swordanswerc = 2;
			}
		}
		if (swordanswerc == 1) {
			slowSentence(battlenosword);
			Sleep(10000);
		}
		if (swordanswerc == 2) {
			slowSentence(battlegotsword);
			Sleep(10000);
		}


		// Credit sequence
		Credits();
}