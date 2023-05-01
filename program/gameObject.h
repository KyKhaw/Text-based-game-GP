#ifndef STRUCT_H
#define STRUCT_H

#include <string>
using namespace std;


class Object {
	public:
		string name;
		string hints;
		Object(string name_, string hints_);
		void set_Object(string name_, string hints_);
		void showInfo();
};

class Weapon {
	public:
		string name;
		string description;
		Weapon(string name_, string description_);
		void set_weapon(string name_, string description_);
		void showInfo();
};

class Character {
	public:
        	string name;
        	int age;
        	string description;
        	string confession;
		Character(string name_, int age_, string description_, string confession_);
		void set_character(string name_, int age_, string description_, string confession_);
        	void showInfo();
        	void showConfession():
};

class MurderRoom {
	public:
		string name;
		Object object[4];
		MurderRoom(string name_, Object object_[4]);
		void set_MurderRoom(string name_, Obejct object_[4]);
		void welcome();
		void showObject();
		void move();
};

class MeetingRoom {
		void welcome();
		void showSuspects();
		void move();
}


extern Character c_1, c_2, c_3, c_4, c_5, c_6,c_7,c_8;
extern Weapon w_1, w_2, w_3, w_4, w_5, w_6,c_7,c_8;
extern Room r_1, r_2, r_3, r_4, r_5, r_6,c_7,c_8;
extern Character characters[8];
extern Weapon weapons[8];

#endif 
