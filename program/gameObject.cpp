#include <iostream>
#include <string>
#include "gameObject.h"
#include <limits>

using namespace std;

// initialize characters
Character wife("Mrs.Buddy", 32, "House wife", "A petite woman with dark brown hair standing alert.\n Slightly concealing her arms.\n Her upper body appears well-toned and her sullen eyes seem upset.\n", "He was begging for it!\n How dare he cheat on me when he had everything!\n I had taken him to the woods at night under the excuse of a moonlight getaway.\n I had hidden the hunting crossbow earlier there and I killed him.\n", "nothing");

Character starlet("Ms.Scarlett", 22, "Hollywood actor", "Mr. Buddy used to sponser her career.\n There were rumours that she was having an affair with the wealthy man.\n", "After his wife found about out our relationship, he abruptly stopped contacting me.\n I came to the ball party to talk with him. I wasn’t trying to kill him.\n I just wanted to threaten him. It was an accident.\n", "nothing");

Character author("Mr.White", 40, "Book writer", "The wealthy man was an investor in his publishing company.\n The company went bankrupt after the wealthy man pulled out his investment.\n Mr.White was in huge debt because of it.\n", "He was a selfish man. Because of him, my company and career were over. I came to the ball party to talk with him. He just won’t listen to me. I thought he would come to his senses and listen to me. But, it was too late.\n", "nothing");

Character servant("Mr.Francis", 55, "House servant", "He looks older than he says he is and rather sickly.\n His frail posture is accentuated by a slight hunch in it and his gaunt face with a weak smile.\n", "Servant!? Servant!? I have a name, don't I? Fifteen years I served the man and he never bothered to ask my name.\n I couldn’t bear the anger anymore.\n I knew his worst enemies were invited to dinner so I took the opportunity to finish him off in the living room.", "I saw Mrs.Buddy around a ditch in the forest.\n");

Character colonel("Mr.Phillip", 51, "Military colonel", "Hayes was a general in one military corporation, and once comitted war crime.\n Mr Buddy spent huge amount of money buying out the journalists with information.\n" , "Oh Lord, please forgive me.” He murmured.\n Now I confess that I have planned to kill my old friend, Buddy, on the way to this majestic mansion.\n He did many good things for me, but at the same time he tried to take advantage of what he did to me.\n I had no choice but to kill him to keep my reputation.\n","nothing");

Character lawyer("Mr.Wesley", 47, "Family lawyer", "He conducted unlawful acts (torts) when he was investigating a requested case.\n And he was further being bought over to wealthy people's side when he was doing a case.\n Mr. Buddy knows everything about his misdeeds\n", "“There was no choice for me. I had to kill him to save my children and my beloved wife.\n At first, I tried to have a chat with him.\n I tried, at least. But that filthy man never listened to me!\n So I wound his neck with my tie that I was holding in my hand.\n", "nothing");

Character characters[6] = {wife, lawyer, starlet, colonel, author, servant};

// initialize rooms
Room forest("forest", "Unfortunately, you have not found any useful information.\n");

Room kitchen("kitchen", "Unfortunately, you have not found any useful information.\n");

Room swimmingPool("swimming pool", "One earring was found near the swimming pool.\n Meanwhile, you have found a piece of paper in the pool, which has been blurred but looks like a persoan letter.\n");

Room bedRoom("master bedroom", "The gun was kept where it used to reside, but one bullet is missing from the chamber.\n");

Room meadow("Meadow", "Unfortunately, you have not found any useful information.\n");

Room livingRoom("living room", "The fireplace poker looks pretty new.\n");

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
  	cout << name << ": " << confession << endl;
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
	cout << "Enter ask for interrogation, or move for visiting crime scheme"<<endl;
	cout << "Enter check to read documents again, or submit to sumbit the answer" << endl;
	cout << endl;

	string command;
	cin >> command;
	if (command == "ask"){
		askSuspects();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} else if (command == "move") {
		rooms[dice].showHints();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} else if (command == "check") {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		showSuspects();
	} else if (command == "submit") {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		submitAnswer();
	} 

}

void MeetingRoom::showSuspects() {
 	for (int i=0; i<6; i++) {
  		cout << "No." << i+1 << " : " << characters[i].name << endl;
 	}
	cout << endl;
 	int num;
  	cout << "Enter corresponding number for document inspection or 0 to exit..." << endl;
  	
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
	cout << "Please type the murderer in you mind and press enter." << endl;
	cout << endl;
	cin >> murderer;
	if (murderer == characters[dice].name) {
		cout << "Congrats! You have discovered the murderer!" << endl;
		cout << "Let's look at the confession of " << characters[dice].name << endl;
		cout << "***********************************"<<endl;
		characters[dice].showConfession();
		cout << "***********************************"<<endl;
		cout << "Press enter to exit the game." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "";
	cin.ignore();
}

