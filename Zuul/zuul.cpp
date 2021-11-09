//Kabir Vidyarthi
//Zuul game
//10/26/21
#include <iostream>
#include <vector>
#include "Room.h"
using namespace std;

void infiniteHallway();
void loopyRooms();
void play();

const testing = true;

int main() {
  //select map
  return 0;
}

//function to start the infinite hallway zuul game
void infiniteHallway() {
  //initialize room
  Room* hallway = new Room("A white hallway, with no distinguishable features");
  hallway->setExit("left", hallway);
  hallway->setExit("right", hallway);
  //start play loop
  play(hallway,true,0,hallway);
}

void loopyRooms() {
  //initilize rooms
  //initilize items
  //start play loop
}

void play(Room* current, bool hallway, int time, Room* winRoom) {
  //give options
  

  //collect choice


  //movement
}
