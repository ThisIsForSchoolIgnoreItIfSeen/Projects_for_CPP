#include <vector>
#ifndef ROOM_H
#define ROOM_H
using namespace std;

class Room {
  //this will need a lot
 public:
  char description[80];
  vector<Item*> items;
  vector<tuple<char,Room*>>;
  Item key;
  bool locked;
  Room(char desc[80]);
  ~Room();
};

#endif

//item is too simple for class, including the struct definition in here for sake of simplicity
#ifndef ITEM_S
#define ITEM_S

struct Item {
  char name[20];
  char description[80];

  Item(char n[20],char d[80]);
}

#endif
