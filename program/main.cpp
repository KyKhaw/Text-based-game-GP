#include <iostream>
#include <string>
#include <stdlib.h>
#include <ios>
#include <limits>
#include "func.h"
#include "gameObject.h"


using namespace std;

int main() {
	int dice_result;
	string name;
	system("clear");

	// get name of the player, and roll dice to simulate senario
	cout << "Welcome our long waited detective! Please enter your name: ";
	cin >> name;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Welcome "<< name<< ", please press enter to roll a dice ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	dice_result = dice();

	cout << "The dice result is "<<dice_result<<endl;
	cout << "Press to start the game... ...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("clear");
	// story starts	
	cout << "One day, a policeman knocks on your door... ..." << endl;
	cout << "The police tells you that a wealthy woman has invited you to track down a criminal case." << endl;
	cout << "Her billionaire husband Mr Buddy, was killed at his home during a ball party."<< endl;
	cout << "Press enter to continue ... ... ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	
	cout << "However, the wife has not yet been proven innocent, and therefore will also be kept at the house as a potential suspect." << endl;
	cout << "The local police team has failed to determine the murderer, and the remuneration offered by this woman is extremely lucrative."<<endl;
	cout << "You have accepted the case and a policeman is driving you to Mr. Buddy's house." <<endl;
	cout << "Press enter to continue ... ... ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	
	cout << "When you arrive, you notice troops of policemen guarding the crime scene."<<endl;
	cout << "As you are about to enter the house, the gate-guarding policeman tells you that..."<<endl;
	cout << "************************************************************"<<endl;
	cout << "Mr. Buddy was killed with a " << weapons[dice_result] << " at " << rooms[dice_result].name << endl;
	cout << "************************************************************"<<endl;
	cout << "All the party participants have been kept in the meeting room for your interrogation."<<endl;
	cout << "Press enter to set foot in Sir Hugh's house..." ;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	// enter meeting room to meet with suspects
	cout << "You have entered Mr. Bobby's house. A policeman is leading you to the meeting room." <<endl;
	cout << "The policeman opens the door, and you are faced with the six prime suspects, each of them holding nervous and horrified expressions."<<endl;
	cout << "These are all party members. After the murder, all of them have been kept within the house."<<endl;
	cout << "Before you begin asking questions, the policeman nearby hands you some documents containing information regarding each of the suspects."<<endl;
	cout << endl;
	cout << "Press enter to continue ...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

