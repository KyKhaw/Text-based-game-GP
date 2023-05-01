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
	char command = 'x';
	system("clear");
	
	cout << "Please enter your name ";
	cin >> name;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "welcome "<< name<< ", please press enter to roll a dice ";
	cin.ignore();
	dice_result = dice();
	cout << "your dice is "<<dice_result<<endl;
	cout << "Sir Hugh was killed in X room with Y weapon"<<endl;
	cout << "Enter to move to Sir Hugh's house" <<endl;
	cin.ignore();
	
	system("clear");
	cout << "welcome to Sir Hugh's house" <<endl;
	cout << "Suspects are now kept at meeting room by police" << endl;
	cout << "You can travel to the Murder Room and to the meeting room by entering move" << endl;
	
	return 0;
}
