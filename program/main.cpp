#include <iostream>
#include <string>
#include <stdlib.h>
#include <ios>
#include <limits>
#include "func.h"
#include "gameObjects.h"


using namespace std;

int main() {
	int dice_result;
	string name;
	system("clear");

	// get name of the player, and roll dice to simulate senario
	cout << "Welcome our long waited detective! Please enter your name: ";
	cin >> name;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "welcome, "<< name<< ", please press enter to roll a dice ";
	cin.ignore();
	dice_result = dice();

	cout << "The dice result is "<<dice_result<<endl;
	cout << "Press to start the game... ...";
	cin.ignore();
	system("clear");
	// story starts	
	cout << "One day, a policeman knocked on your door... ..." << endl;
	cout << "The police tell you that a wealthy woman invites you to track down a criminal case." << endl;
	cout << "Her husband Mr Boddy, a billionaire, was killed at his home during a ball party."<< endl;
	cout << "press enter to continue ... ... ";
	cin.ignore();
	cout << endl;
	
	cout << "However, the wife has not been proved innocent, and therefore is also kept at her house." << endl;
	cout << "The local police team has failed to spot the murderer, and the remuneration offered by this woman is extremly lucrative."<<endl;
	cout << "You have accepted the case and a policeman is driving you to Mr. Boddy's house." <<endl;
	cout << "press enter to continue ... ... ";
	cin.ignore();
	cout << endl;
	
	cout << "When you arrive, policemen are in control of the crime schene."<<endl;
	cout << "You are about to enter the house, and the gate-guarding policeman told you that -"<<endl;
	cout << "************************************************************"<<endl;
	cout << "Mr. Bobby was killed with a " << weapons[dice_result] << " at " << rooms[dice_result].name << endl;
	cout << "************************************************************"<<endl;
	cout << "All the party participants have been kept in the meeting room for your interrogation."<<endl;
	cout << "Press to enter to Sir Hugh's house..." ;
	cin.ignore();
	cout << endl;
	// enter meeting room to meet with suspects
	cout << "You have entered Mr. Bobby's house. A policeman is leading you to the meeting room." <<endl;
	cout << "After the policeman opens the door for you, you six persons in the room, all with nurvous and horrified looks."<<endl;
	cout << "They are all party members. After the murder, all of them have been kept within the house."<<endl;
	cout << "Before you ask the them questions, the policeman nearby hands you some documents with informations of these people."<<endl;
	cout << endl;
	cout << "Enter to continue ...";
	cin.ignore();
	system("clear");

	// read the documents about the suspects; 
	MeetingRoom meetingRoom(dice_result);
	meetingRoom.showSuspects();
	cout << endl;
	system("clear");

	while (true) {
	system("clear");
	meetingRoom.welcome();
	}

	return 0;
}

