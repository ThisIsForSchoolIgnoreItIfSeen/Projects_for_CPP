#include <iostream>
#include "Room.h"
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

//defining room functions
Room::Room(char desc[80]) {
  description = &desc;
}

Room::~Room() {
  cout << "Something has gone horribly wrong";
}

Room::setExit((char dir, Room* location) {
    exits.push_back(make_pair(dir,location));
}

  Room::setPrev(Room* prev) {
    setExit('b',prev);
  }

  Room::printExits() {
    for (auto i=exits.begin(); i!=exits.end();++i) {
      match(i->first) (
		       pattern('n') = cout << "To the North there is "
		       pattern('s') = cout << "To the South there is "
		       pattern('e') = cout << "To the East there is "
		       pattern('w') = cout << "To the West there is "
		       pattern('b') = cout << "Behind you there is "
		       );
      cout << i->second << '\n';
    }
  }
  //defining item functions
Item::Item(char n[20],char d[80]) {
  name = n;
  description = d;
}
