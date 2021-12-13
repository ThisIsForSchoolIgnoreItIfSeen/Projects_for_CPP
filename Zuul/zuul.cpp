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
  loopyRooms(theUser);
  infiniteHallway(theUser);
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
  //initilize end Rooms
  rooms[4]->setExit('e',new Room("A melancholy room"));
  rooms[4]->getExit('e')->setExit('e',new Room("A sad Room"));
  rooms[4]->getExit('e')->getExit('e')->setExit('e',new Room("a horrified Room"));
  //initilize items
  //initilize layout
  /*bool taken[49];
  for (int i=0;i<7;i++) {
    for (int j=0;j<7;j++) {
      taken[i][j]=false;
    }
  }
  taken[4][4]=true;
  int currentCount = 0;
  pair_node* cur = new pair_node(4,4);
  pair_node* last = cur;
  cur->next = new pair_node(-1,-1);
  while (((cur->first>=0)&&(cur->second>=0))&&((cur->first<7)&&(cur->second<7))&&(currentCount<10)) {
      //determine exits
      //north
    if  (cur->first>0) {
      if (!taken[cur->first-1][cur->second]) {
	if (((cur->first<=1)||((cur->first>1)&&(!taken[cur->first-2][cur->second])))&&((cur->second<=0)||((cur->second>0)&&(!taken[cur->first-1][cur->second-1])))&&((cur->second>=2)||((cur->second<2)&&(!taken[cur->first-1][cur->second+1]))) {
	    //check random
	    int chance = rand()%101;
	    cout << "Chance:" << chance << endl;
	    if (chance<5*(10-currentCount)) {
	      taken[cur->first-1][cur->second]=true;
	      last->next= new pair_node(cur->first-1,cur->second);
	      last = last->next;
	      cout << "new point:" << last->first << ',' << last->second << endl;
	      currentCount++;
	    }
	  }
      }
      }
    }
      //east
      if ((cur->second<6)&&(!taken[cur->first][cur->second+1])&&((cur->first<=0)||((cur->first>0)&&(!taken[cur->first-1][cur->second+1])))&&((cur->second>=5)||((cur->second<5)&&(!taken[cur->first][cur->second+2])))&&((cur->first>=6)||((cur->first<6)&&(!taken[cur->first+1][cur->second+1])))) {
	  //check random
	  int chance = rand()%101;
	  cout << "Chance:" << chance << endl;
	  if (chance<5*(10-currentCount)) {
	    taken[cur->first][cur->second+1]=true;
	    last->next= new pair_node(cur->first,cur->second+1);
	    last = last->next;
	    cout << "new point:" << last->first << ',' << last->second;
	    currentCount++;
	  }
	}
      //south
      if ((cur->first<5)&&(!taken[cur->first+1][cur->second])&&((cur->first>=5)||((cur->first<5)&&(!taken[cur->first+2][cur->second])))&&((cur->second<=0)||((cur->second>0)&&(!taken[cur->first+1][cur->second-1])))&&((cur->second>=6)||((cur->second<6)&&(!taken[cur->first-1][cur->second+1])))) {
	  //check random
	  int chance = rand()%101;
	  cout << "Chance:" << chance << endl;
	  if (chance<5*(10-currentCount)) {
	    taken[cur->first+1][cur->second]=true;
	    last->next= new pair_node(cur->first+1,cur->second);
	    last = last->next;
	    currentCount++;
	  }
	}
      //west
      if ((cur->second>0)&&(!taken[cur->first][cur->second-1])&&((cur->first<=0)||((cur->first>0)&&(!taken[cur->first-1][cur->second-1])))&&((cur->second<=1)||((cur->second>1)&&(!taken[cur->first][cur->second-2])))&&((cur->first>=6)||((cur->first<6)&&(!taken[cur->first-1][cur->second-1])))) {
	  //check random
	  int chance = rand()%101;
	  cout << "Chance:" << chance << endl;
	  if (chance<5*(10-currentCount)) {
	    taken[cur->first][cur->second-1]=true;
	    last->next= new pair_node(cur->first,cur->second-1);
	    last = last->next;
	    cout << "new point:" << last->first << ',' << last->second;
	    currentCount++;
	  }
	}
      //iterate
      pair_node* temp = cur;
      cur = cur->next;
      delete [] temp;
  }
  delete [] cur;
  delete [] last;
  */
  //set rooms
  //set exits
  rooms[0]->setExit('e',rooms[1]);
  rooms[0]->setExit('s',rooms[3]);
  rooms[3]->setExit('w',rooms[2]);
  rooms[3]->setExit('s',rooms[5]);
  rooms[5]->setExit('s',rooms[9]);
  rooms[9]->setExit('s',rooms[14]);
  rooms[14]->setExit('s',rooms[17]);
  rooms[17]->setExit('e',rooms[18]);
  rooms[18]->setExit('e',rooms[19]);
  rooms[19]->setExit('e',rooms[20]);
  rooms[20]->setExit('n',rooms[15]);
  rooms[9]->setExit('w',rooms[8]);
  rooms[8]->setExit('w',rooms[7]);
  rooms[7]->setExit('s',rooms[13]);
  rooms[13]->setExit('w',rooms[12]);
  rooms[12]->setExit('s',rooms[16]);
  rooms[9]->setExit('e',rooms[10]);
  rooms[10]->setExit('e',rooms[11]);
  rooms[11]->setExit('n',rooms[6]);
  rooms[6]->setExit('n',rooms[4]);
  rooms[15]->removeExit('s');
  //start play loop
  theUser->play(rooms[9],false,0,rooms[4]->getExit('e')->getExit('e')->getExit('e'));
}
