#include <iostream>
#include "Room.h"
#include <cstring>
#include <vector>
#include <utility>
#include <math.h>
#include "patterns.hpp"
using namespace mpark::patterns;
using namespace std;

player::player() {
  cout << "Welcome to the Game\n";
}

player::~player() {
  cout << "Thanks for playing";
}

void player::displayItems() {
  if (items.size()==0) {
    cout << "You have no items\n";
    return;
  }
  cout << "You have: ";
  for (auto i=items.begin();i!=items.end();++i) {
    cout << (*i)->name << ", ";
  }
  cout << endl;
}

void player::play(Room* current, bool hallway, int rounds, Room* winRoom) {
  //check win for hallway
  if (hallway) {
    int chance = 1 + rand()%100;
    if ((100/(1+99.919*exp(rounds*-0.0092)))>chance) {
      cout << "Congratulations on Perservering, you have escaped the infinite hallway\nThat took you " << rounds << " moves";
      return;
    }
  } else if (current==winRoom) {
    int whymIAskingIfIDontCare;
    cout << "congratulations on escaping the loopy forest, how was the experience?\n_/5 *s:";
    cin >> whymIAskingIfIDontCare;
    cout << "Thanks for the input!";
    return;
  }
  
  //give options
  cout << "You are in " << current->description << '\n';
  displayItems();
  current->printExits();

  //collect choice


  //movement
  char dir;
  cout << "Which way do you want to go?\n";
  cin >> dir;
  cin.ignore(15,'\n');
  if (('A'<=dir)&&(dir<='Z')) {
    dir += 'a'-'A';
  }
  if (dir=='q') {
    cout << "thanks for playing!";
    return;
  }
  Room* next = current->getExit(dir);
  if (next==NULL) {
    next = current;
  }
  play(next,hallway,rounds+1,winRoom);
}


Item::Item(char n[20],char d[80]) {
  for (int i=0;i<20&&n;i++) {
    name[i]=*n;
    n++;
  }
  for (int i=0;i<80&&d;i++) {
    description[i]=*d;
    d++;
  }
}


Item::Item() {
  //this doesn't need to do anything
}
Item::~Item() {
  //this also doesn't need to do anything
}


//defining room functions
Room::Room(char desc[80]) {
  for (int i=0;i<80&&desc;i++) {
    description[i]=*desc;
    desc++;
  }
}

Room::~Room() {
  cout << "Something has gone horribly wrong";
}

void Room::removeExit(char dir) {
  for (auto i=exits.begin();i!=exits.end();++i) {
    if (i->first==dir) {
      exits.erase(i--);
    }
  }
}

void Room::setExit(char dir, Room* location) {
  if (getExit(dir)!=NULL) {return;}
  exits.push_back(make_pair(dir,location));
  char opp = match(dir) (
			 pattern('n') = []{return 's';},
			 pattern('s') = []{return 'n';},
			 pattern('e') = []{return 'w';},
			 pattern('w') = []{return 'e';},
			 pattern('u') = []{return 'b';},
			 pattern('b') = []{return 'u';}
			 );
  if (location->getExit(opp)==NULL) {
    location->setExit(opp,this);
  }
}

void Room::setPrev(Room* prev) {
  setExit('b',prev);
}

void Room::printExits() {
  for (auto i=exits.begin(); i!=exits.end();++i) {
    match(i->first) (
		     pattern('n') = []{cout << "To the North there is ";},
		     pattern('s') = []{cout << "To the South there is ";},
		     pattern('e') = []{cout << "To the East there is ";},
		     pattern('w') = []{cout << "To the West there is ";},
		     pattern('u') = []{cout << "Above you there is ";},
		     pattern('b') = []{cout << "Below you there is ";}
		     );
    cout << i->second->description << '\n';
  }
}
Room* Room::getExit(char key) {
  for (auto i=exits.begin();i!=exits.end();++i) {
    if (key==i->first)
      return i->second;
  }
  return NULL;
}

void node::append(int value) {
  if (next == NULL) {
    next = new node(value);
  } else {
    next->append(value);
  }
}

node::node() {
  value = 0;
  next=NULL;
}

node::node(int a) {
  value = a;
  next = NULL;
}

node::~node() {
}
