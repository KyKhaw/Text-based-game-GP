#include <iostream>
#include <string>
#include "gameObject.h"
#include <limits>
#include <vector>

using namespace std;

// initialize characters
Character wife("Mrs. Buddy", 32, "House wife", "A petite woman with dark brown hair standing alertly.\n Her hands are tucked behind her back, as if trying to conceal them.\n Her upper body and arms appears well-toned and her sullen eyes seem upset.\n", "He was begging for it!\n How dare he cheat on me when he had everything!\n I had taken him to the woods at night under the excuse of a moonlight getaway.\n I had hidden the hunting crossbow earlier there and I killed him.\n", 
	       "I vividly remember that our servant, Francis, asked me if I had a chance to access to the fireplace.\n He seemed to be in a panic a lot.\n");

Character starlet("Ms. Scarlett", 22, "Hollywood actor", "Mr. Buddy used to sponsor her career.\n There were rumours that she was having an affair with the wealthy man.\n", "After his wife found about out our relationship, he abruptly stopped contacting me.\n I came to the ball party to talk with him. I wasn’t trying to kill him.\n I just wanted to threaten him. It was an accident.\n", 
		  "I heard a gunshot last night.\n I woke up because of that sound, but nothing special happend after that, so I went to bed again.\n");

Character author("Mr. White", 40, "Book writer", "The wealthy man was a major investor in his publishing company.\n The company went bankrupt after the wealthy man withdrew his investment.\n Mr.White fell into huge debt because of it.\n", "He was a selfish man. Because of him, my company and career were over. I came to the ball party to talk with him. He just won’t listen to me. I thought he would come to his senses and listen to me. But, it was too late.\n", 
		 "I witnessed Mr. Wesley had an argument with Mr. Buddy.\n Recall that, I noticed it got intenser as time went by.\n");

Character servant("Mr. Francis", 55, "House servant", "He looks older than he says he is and rather sickly.\n His frail posture is accentuated by a slight hunch in it and his gaunt face with a weak smile.\n", "Servant, servant, servant! I have a name, don't I? Fifteen years! Fifteen years I have served the man, and not once has he bothered to ask for my name.\n I couldn’t bear the anger anymore.\n I knew his worst enemies were invited to dinner so I took the opportunity to finish him off in the living room.", 
		  "Mr. White gave me his laundries this morning.\n It was his shirt and trouser and those were with some dirts and stains.\n I did not ask him why he got dirts on his cloths though.\n");

Character colonel("Mr. Phillip", 51, "Military colonel", "Hayes was a general in one military corporation, and once comitted war crime.\n Mr Buddy spent huge amount of money buying out the journalists with information.\n" , "Oh Lord, please forgive me.” He murmured.\n Now I confess that I had planned to kill my old friend, Buddy, on the way to his ever majestic mansion.\n He did many favours for me, but at the same time, he tried to take advantage of those favours. Guilt tripping, gaslighting... \n I had no choice but to kill him! For my dignity, my reputation!\n",
		  "Last night, I saw Mrs. Scarlette and Mr. Buddy entering the swimming pool together.\n");

Character lawyer("Mr. Wesley", 47, "Family lawyer", "He conducted unlawful acts (torts) while investigating a requested case.\n And he was further being bought over to wealthy people's side when he was conducting a case.\n Mr. Buddy knows everything about his misdeeds\n", "“I had no choice. I had to kill him. To save my children, my beloved wife!\n At first, I tried to talk.\n I tried, at least! But that filthy man never listened to a word I said!\n So I wound his neck with my tie that I was holding in my hand.\n", 
		 "I saw Mrs.Buddy around a ditch in the forest.\n");

Character characters[6] = {wife, lawyer, starlet, colonel, author, servant};

// initialize rooms
Room forest("forest", "You notice a strand of hair in the clearing. It is difficult to tell, but it looks hazel.\n");

Room kitchen("kitchen", "Unfortunately, you have not found any useful information.\n");

Room swimmingPool("swimming pool", "One earring was found near the swimming pool.\n Meanwhile, you have found a piece of paper in the pool, which has been blurred but looks like a persoan letter.\n");

Room bedRoom("master bedroom", "The gun was kept where it used to reside, but one bullet is missing from the chamber.\n");

Room meadow("Meadow", "Unfortunately, you have not found any useful information.\n");

Room livingRoom("living room", "The fireplace poker has a shiny glint.\n");

Room rooms[6] = {forest, kitchen, swimmingPool, bedRoom, meadow, livingRoom};


//initialize weapon list
string weapons[6] = {"crossbow", "necktie", "knife", "revolver gun", "baseball bat", "fireplace poker"};

//define class functions
Character::Character(string name_, int age_, string job_, string description_, string confession_, string conversation_) {
  	set_character(name_, age_, job_, description_, confession_, conversation_);
}

void Character::set_character(string name_, int age_, string job_, string description_, string confession_, string conversation_) {
	job = job_;
  	name = name_;
  	age = age_;
  	description = description_;
  	confession = confession_;
	conversation = conversation_;
}

void Character::showInfo() {
  	cout << "Name: " << name << endl;
  	cout << "Age: " << age << endl;
	cout << "Occupation: " << job << endl;
  	cout << "Description: " << description << endl;
}

void Character::showConfession() {
  	cout << name << ": " << ednl;
	cout << confession << endl;
	cout << endl;
}

void Character::showConversation(){
	cout << name << ": " << conversation << endl;
	cout << endl;
}

Room::Room(string name_, string hints_) {
  	set_Room(name_, hints_);
}

void Room::set_Room(string name_, string hints_) {
  	name = name_;
	hints = hints_;
}


void Room::showHints() {
	cout << "****************************"<<endl;
	cout << "You are now in " << name << " ." << endl;
	cout << "****************************"<<endl;
	cout << endl;
  	cout << hints << endl;
	cout << endl;
	cout << "Enter to go back to the meeting room." << endl;
	cin.ignore();
	cout << endl; 
}


MeetingRoom::MeetingRoom(int dice_){
	dice = dice_;
}

void MeetingRoom::welcome() {
	cout << "*******************************************"<<endl;
  	cout << "You are now in the meeting room" << endl;
	cout << "*******************************************"<<endl;
	cout << "Please enter a command for your next move: "<<endl;
	cout << endl;
	cout << "ask: interrogate the suspects. " << endl;
	cout << "move: inspect the crime scene. " << endl;
	cout << "check: check the documents of these suspects again. " << endl;
	cout << "submit: tell the police about your answer. " << endl;
	cout << "note: take notes of what you have in mind. " << endl; 
	cout << endl;

	string command;
	cin >> command;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (command == "ask"){
		askSuspects();
	} else if (command == "move") {
		rooms[dice].showHints();
	} else if (command == "check") {
		showSuspects();
	} else if (command == "submit") {
		submitAnswer();
	} else if (command == "note"){
		noteBook(); 
	}
}

void MeetingRoom::showSuspects() {
 	for (int i=0; i<6; i++) {
  		cout << "No." << i+1 << " : " << characters[i].name << endl;
 	}
	cout << endl;
 	int num;
  	cout << "Enter the corresponding number for document inspection or 0 to exit..." << endl;
	cout << endl;
  	
  	while (cin >> num) {
  		if (num == 0){
  			break;
  		}else if ((num > 0) && (num<7)){
  			characters[num-1].showInfo();
  		}else {
  			cout << "Incorrect input." << endl;
  		}
  	}
}

void MeetingRoom::submitAnswer(){
	string murderer;
	cout << "Please type in the murderer you have in mind and press enter." << endl;
	cout << endl;
	getline(cin, murderer);
	if (murderer == characters[dice].name) {
		cout << "Congrats! You have discovered the murderer!" << endl;
		cout << "Let's look at the confession of " << characters[dice].name << endl;
		cout << "***********************************"<<endl;
		characters[dice].showConfession();
		cout << "***********************************"<<endl;
		cout << "Press enter to exit the game." << endl;
		cin.ignore();
		exit(0);
	} else{
	cout << "Sorry your answer is not correct." << endl; 
	cout << "Enter to go back to the meeting room."<<endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.ignore();
	}
}

void MeetingRoom::askSuspects(){
	
	for (int i=0; i<6; i++) {
		cout << "No." << i+1 << " : " << characters[i].name << endl;
	}
	cout << endl;
	
	int num;
  	cout << "Enter the corresponding number for document inspection or 0 to exit..." << endl;
	cout << endl;
  	
  	while (cin >> num) {
  		if (num == 0){
  			break;
  		}else if ((num > 0) && (num<7)){
  			characters[num-1].showConversation();
  		}else {
  			cout << "Incorrect input." << endl;
  		}
  	}
}

void MeetingRoom::noteBook(){
	system("clear");
	cout << "Enter command: read / write" << endl;
	string command;
	cin >> command;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	
	if (command == "read"){
		cout << endl;
		if (notes.size() != 0){
			for (int i=0; i < notes.size(); i++){
				cout << "Note " << i+1 << " : " << notes[i] << endl;
				cout << endl;
			}
		} else {
			cout << "Your note book is blank. Please write before reading. " << endl;
		}
		cout << "Enter to exit note book." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} else if (command == "write") {
		cout << endl;
		string note;
		getline(cin, note);
		cout << endl;
		notes.push_back(note);
		cout << "Notes saved. " << endl;
		cout << "Enter to exit note book." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} else {
		cout << "incorrect command. " << endl;
	}
}
