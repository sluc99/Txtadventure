#include <iostream>
#include <string>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

int levelud = 0;
int levellr = 0;
string direction;
string credits = "Thanks for playing the game ";
string credits2 = " This game was coded by Luc Stolk.\nWith some help from Liam de Koning and Tim Leijten aka (suss). \nThe story was written by Luc Stolk. I hope you enjoyed it ";
string playername;						// playername save

void slowSentence(string sentence) {
	for (int i = 0; i < sentence.length(); i++) {
		std::cout << sentence[i];
		Sleep(1);
	}
}

void moveDirection() {
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
}

void Credits() {
	system("CLS");
	slowSentence(credits);
	slowSentence(playername);
	slowSentence(credits2);
}


int main() {

	// strings that are variable

	string gender;							// gender save
	string confirmgender;					// gender confirmation

	// strings with text

	string chooseadirection = "\nNow choose a direction you want to go. North, East, South, West ";
	string hitawall = "You hit a wall Bonkers ";
	string herasmussendsyouback = "Hello adventurer. you already have been here and there is nothing important for you left here";
	string welcome = "Welcome to this Text adventure game. Please tell me your name.\n";
	string welcomeplayer1 = "Welcome ";
	string welcomeplayer2 = " to the wonderful world of Athernos.";
	string gender1 = "\nNow tell me are you a boy or a girl. \n";
	string gender2 = "So you are a ";
	string gender3 = " are you sure\n";
	string intro = "My name is Herasmus. I am one of the wizards you'll encounter in this world. Some of them will help you on your way others however. They are bad and will try to get you lost. To the north of here you will find a village in there are a couple of people you can talk too. Should you need any help you can always ask ol herasmus here for tips.";
	string introvillage = "Welcome to Starter village you hear as you walk through the gate. My name is Alisha and i am the daughter of the mayor. What is your name : ";
	string introvillage2 = ". Weird i remember that name vaguely, like i have heard it before. Anyway what does a adventurer like you do in Starter village. I bet you want to meet the mayor luckily he is not busy right now. I'll lead you to him.\nShe starts to walk towards the North.";
	string introvillage3 = "You follow Alisha to the north. After a moment you see a big building with marble pillars. She leads you inside into a office. Inside the office sits a man with a curly mustache. As you look at him you see he is about 1.8m you also see his mustache is getting a little white. As he sits there you hear Alisha say that you are a new adventurer. ";
	string introvillage4 = "mt";
	// Welcoming sequence with character selection
		
	slowSentence(welcome);
	std::cin >> playername;
	slowSentence(welcomeplayer1);
	slowSentence(playername);
	slowSentence(welcomeplayer2);
	for (int i = 0; i < 100; i++) {
		slowSentence(gender1);
		std::cin >> gender;
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

	// Intro sequence with first village

	slowSentence(intro);
	for (int i = 0; i < 100; i++) {
		slowSentence(chooseadirection);
		cin >> direction;
		moveDirection();
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
	for (int i = 0; i < 100; i++) {
		slowSentence(chooseadirection);
		cin >> direction;
		moveDirection();
		if (levelud == 2) {
			slowSentence(introvillage3);
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
	/*
	// Credit sequence
	Credits();*/
}



