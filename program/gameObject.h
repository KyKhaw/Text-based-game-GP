#ifndef STRUCT_H
#define STRUCT_H

#include <string>
#include <vector>

using namespace std;

class Character {
	public:
        	string name;
        	int age;
		string job;
        	string description;
        	string confession;
		string conversation;

		Character(string name_, int age_, string job_, string description_, string confession_, string conversation_);
		void set_character(string name_, int age_, string job_, string description_, string confession_, string convsersation_);
        	void showInfo();
        	void showConfession();
		void showConversation();
};

class Room {
	public:
		string name;
		string hints;
		Room(string name_, string hints_);
		void set_Room(string name_, string hints_);
		void showHints();
};

class MeetingRoom {
	public:
		int dice;
		vector<string> notes;
		MeetingRoom(int dice_);
		void welcome();
		void showSuspects();
		void askSuspects();
		void submitAnswer();
		void noteBook();
};



extern Character lawyer, starlet, author, colonel, gardener, wife;
extern Room bedRoom, livingRoom, servantQuarter, kitchen, swimmingPool, meadow;
extern Character characters[6];
extern string w_1, w_2, w_3, w_4, w_5, w_6;
extern string weapons[6];
extern Room rooms[6];


#endif 
