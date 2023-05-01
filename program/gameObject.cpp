#include <iostream>
#include <string>
#include "gameObjects.h"

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

Object::Object(string name_, string hints_) {
  set_Object(name_, hints_);
}

void Object::set_Object(string name_, string hints_) {
  name = name_;
  hints = hints_;
}

void Object::showInfo() {
  cout << "Object Name: " << name << endl;
  cout << "Hints: " << hints << endl;
}

Weapon::Weapon(string name_, string description_) {
  set_weapon(name_, description_);
}

void Weapon::set_weapon(string name_, string description_) {
  name = name_;
  description = description_;
}

void Weapon::showInfo() {
  cout << "Weapon Name: " << name << endl;
  cout << "Description: " << description << endl;
}

Character::Character(string name_, int age_, string description_, string confession_) {
  set_character(name_, age_, description_, confession_);
}

void Character::set_character(string name_, int age_, string description_, string confession_) {
  name = name_;
  age = age_;
  description = description_;
  confession = confession_;
}

void Character::showInfo() {
  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
  cout << "Description: " << description << endl;
}

void Character::showConfession() {
  cout << "Confession: " << confession << endl;
}

MurderRoom::MurderRoom(string name_, Object object_[4]) {
  set_MurderRoom(name_, object_);
}

void MurderRoom::set_MurderRoom(string name_, Object object_[4]) {
  name = name_;
  for (int i = 0; i < 4; i++) {
    object[i] = object_[i];
  }
}

void MurderRoom::welcome() {
  cout << "Welcome to the Murder Room: " << name << endl;
}

void MurderRoom::showObject() {
  cout << "Objects in the room:" << endl;
  for (int i = 0; i < 4; i++) {
    object[i].showInfo();
  }
}

void MurderRoom::move() {
  cout << "Moving to the next room..." << endl;
}

void MeetingRoom::welcome() {
  cout << "Welcome to the Meeting Room" << endl;
}

void MeetingRoom::showSuspects() {
  cout << "The suspects are:" << endl;
  cout << "1. John" << endl;
  cout << "2. Alice" << endl;
  cout << "3. Bob" << endl;
}

void MeetingRoom::move() {
  cout << "Moving to the next
}
