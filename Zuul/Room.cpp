#include <iostream>
#include "Room.h"
#include <cstring>
#include <vector>
#include <utility>
#include "patterns.hpp"
using namespace mpark::patterns;
using namespace std;

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

void Room::setExit(char dir, Room* location) {
    exits.push_back(make_pair(dir,location));
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
		     pattern('b') = []{cout << "Behind you there is ";}
		     );
    cout << i->second->description << '\n';
  }
}
Room* Room::getExit(char key) {
  for (auto i=exits.begin();i!=exits.end();++i) {
    if (key==i->first)
      return i->second;
  }
  return this;
}
