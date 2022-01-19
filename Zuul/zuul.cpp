//Kabir Vidyarthi
//Zuul game
//10/26/21
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Room.h"
#include <cstring>
#include <time.h>
#include "patterns.hpp"
#include <math.h>
#include <utility>
using namespace std;
using namespace mpark::patterns;

void infiniteHallway(player* theUser);
void loopyRooms(player* theUser);
void play(Room* current, bool hallway, int time, Room* winRoom);

const bool testing = true;

int main() {
  srand(time(NULL));
  player* theUser = new player();
  //select map
  //coin flip
  if (rand()%2==0) {
    loopyRooms(theUser);
  } else {
    infiniteHallway(theUser);
  }
  return 0;
}

//function to start the infinite hallway zuul game
void infiniteHallway(player* theUser) {
  //initialize room
  Room* hallway = new Room("A white hallway, with no distinguishable features, but it seems to extend to infinity in either direction");
  hallway->setExit('w', hallway);
  hallway->setExit('e', hallway);
  //start play loop
  theUser->play(hallway,true,0,hallway);
}

void loopyRooms(player* theUser) {
  //initilize rooms
  Room* rooms[21] = {new Room("A forest clearing"), new Room("A very bright room"), new Room("A dim room with a paneled ceiling and a ton of computers"), new Room("An intersection"), new Room("A clearing with picnic tables"), new Room("A polygon shaped room that potentially has a ceiling"), new Room("A room with a dead body in the corner"), new Room("A pitch black room"), new Room("A dark place, you seem to be falling very slowly"), new Room("A room with white colored walls"), new Room("A room with walls"), new Room("A misspelled romm"), new Room("Ay rrom wiht smoe amuotn ouv fetures"), new Room("A room with some amount of features"), new Room("A room"), new Room("A seemingly endless room with no visible ways to escape, bye"), new Room("A room that may be running out of ideas"), new Room("A room that is problably running out of ideas"), new Room("A room that is definetly running out of ideas"), new Room("A room with very few ideas"), new Room("A room that is out of ideas")};
  //initilize items
  //initilize layout
  vector<int> possibleEnds;
  bool taken[49];
  for (int i=0;i<49;i++) {
    taken[i]=false;
  }
  taken[24]=true;
  int currentCount = 0;
  node* cur = new node(24);
  do {
    bool manyExits = false;
    cout << "Checking: " << cur->value << endl;
      //determine exits
      //north
    if  ((cur->value>6)&&(!taken[cur->value-7])) {
      if (((cur->value%7==0)||(!taken[cur->value-8]))&&((cur->value<=13)||(!taken[cur->value-14]))&&((cur->value%7==6)||(!taken[cur->value-6]))) {
	//check random
	int chance = rand()%101;
	cout << "Chance:" << chance << endl;
	if (chance<75) {
	  manyExits=true;
	  taken[cur->value-7]=true;
	  cur->append(cur->value-7);
	  cout << "new point:" << cur->value-7 << endl;
	  currentCount++;
	}
      }
    }
    //east
    if ((cur->value%7<6)&&(!taken[cur->value+1])) {
      if (((cur->value<=6)||(!taken[cur->value-6]))&&((cur->value%7==5)||(!taken[cur->value+2]))&&((cur->value>=42)||(!taken[cur->value+8]))) {
	//check random
	int chance = rand()%101;
	cout << "Chance:" << chance << endl;
	if (chance<75) {
	  manyExits=true;
	  taken[cur->value+1]=true;
	  cur->append(cur->value+1);
	  cout << "new point:" << cur->value+1 << endl;
	  currentCount++;
	}
      }
    }
    //south
    if ((cur->value<42)&&(!taken[cur->value+7])) {
      if (((cur->value%7==6)||(!taken[cur->value+8]))&&((cur->value>=35)||(!taken[cur->value+14]))&&((cur->value%7==0)||(!taken[cur->value+6]))) {
	//check random
	int chance = rand()%101;
	cout << "Chance:" << chance << endl;
	if (chance<75) {
	  manyExits=true;
	  taken[cur->value+7]=true;
	  cur->append(cur->value+7);
	  cout << "new point:" << cur->value+7 << endl;
	  currentCount++;
	}
      }
    }
    //west
    if ((cur->value%7>0)&&(!taken[cur->value-1])) {
      if (((cur->value<=6)||(!taken[cur->value-8]))&&((cur->value>=42)||(!taken[cur->value+6]))&&((cur->value%7==1)||(!taken[cur->value-2]))) {
	  //check random
	  int chance = rand()%101;
	cout << "Chance:" << chance << endl;
	if (chance<75) {
	  manyExits=true;
	  taken[cur->value-1]=true;
	  cur->append(cur->value-1);
	  cout << "new point:" << cur->value-1 << endl;
	  currentCount++;
	}
	}
    }
    if (!manyExits) {
      possibleEnds.push_back(cur->value);
    }
    //iterate
    if (cur->next!=NULL) {
      cout << "onto next" << endl;
      node* temp = cur;
      cur = cur->next;
      delete temp;
    } else {
      break;
    }
  } while (cur!=NULL && currentCount<18);
  if (cur!=NULL) {
    delete cur;
  }
  
  //set rooms
  Room* layoutRooms[49];
  int anIter = 0;
  for (int i=0; i<49; i++) {
    if (taken[i]) {
      cout << '1';
      layoutRooms[i]=rooms[anIter];
      anIter++;
    }
    else {
      cout << '0';
      layoutRooms[i]=NULL;
    }
    if (i%7==6) {cout << endl;}
    else {cout << ',';}
  }
  
  //set exits
  for (int i=0;i<49;i++) {
    if (!taken[i]) {continue;}
    //north
    if (i>6)
      if (taken[i-7])
	layoutRooms[i]->setExit('n',layoutRooms[i-7]);
    //east
    if (i%7<6)
      if (taken[i+1])
	layoutRooms[i]->setExit('e',layoutRooms[i+1]);
    //south
    if (i<42)
      if (taken[i+7])
	layoutRooms[i]->setExit('s', layoutRooms[i+7]);
    //west
    if (i%7>0)
      if (taken[i-1])
	layoutRooms[i]->setExit('w', layoutRooms[i-1]);
  }
  layoutRooms[possibleEnds[2]]->setExit('u',new Room("A melancholy room"));
  layoutRooms[possibleEnds[2]]->getExit('u')->setExit('u',new Room("A sad Room"));
  layoutRooms[possibleEnds[2]]->getExit('u')->getExit('u')->setExit('u',new Room("a horrified Room"));
  //start play loop
  theUser->play(layoutRooms[24],false,0,layoutRooms[possibleEnds[2]]->getExit('u')->getExit('u')->getExit('u'));
}
