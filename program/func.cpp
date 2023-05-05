#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include "func.h"
using namespace std;

int dice() {
	bool trials[7] = {false}; // Initialize all elements to false

	// Read from file if it exists
	ifstream fin("history.txt");
	if (fin.is_open()) {
		bool trial;
		while (fin >> trial) {
			trials[trial] = true;
		}
		fin.close();
	}

	// Check if all scenarios have been played
	bool allTrue = true;
	for (int i = 1; i < 7; i++) {
		if (trials[i] == false) {
			allTrue = false;
			break;
		}
	}

	if (allTrue == true) {
		cout << "Congratulations! You have played all the scenarios!" << endl;
		cout << "Press Enter to end the game." << endl;
		cin.ignore();
		exit(0);
	}

	// Roll the dice until a scenario that has not been played is found
	int roll;
	srand((unsigned int) time(NULL));
	do {
		roll = rand() % 6 + 1;
	} while (trials[roll] == true);

	// Update history and return the result
	ofstream fout("history.txt", ios::app);
	if (fout.is_open()) {
		fout << roll << endl;
		fout.close();
	} else {
		cout << "Error: Failed to update history file." << endl;
	}
	
	return roll;
}

