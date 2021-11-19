//Kabir Vidyarthi
//Zuul game
//10/26/21
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Room.h"
#include <cstring>
#include <time.h>
#include "patterns.hpp"
using namespace std;
using namespace mpark::patterns;

void infiniteHallway();
void loopyRooms();
void play(Room* current, bool hallway, int time, Room* winRoom);

const bool testing = true;

int main() {
  //select map
  infiniteHallway();
  return 0;
}

//function to start the infinite hallway zuul game
void infiniteHallway() {
  //initialize room
  Room* hallway = new Room("A white hallway, with no distinguishable features");
  hallway->setExit('w', hallway);
  hallway->setExit('e', hallway);
  //start play loop
  play(hallway,true,0,hallway);
}

void loopyRooms() {
  //initilize rooms
  //initilize items
  //start play loop
}

void play(Room* current, bool hallway, int time, Room* winRoom) {
  //check win for hallway
  if (hallway) {
    srand(time(NULL));
    if (time>rand()%101) {
      cout << "Congratulations on Perservering, you have escaped the infinite hallway";
      return;
    }
  }

  //give options
  cout << "You are in " << current->description << '\n';
  current->printExits();
  
  //collect choice


  //movement
  char dir;
  cout << "Which way do you want to go?\n";
  cin >> dir;
  cin.ignore(15,'\n');
  Room* next = current->getExit(dir);
  play(next,hallway,time+1,winRoom);
}
