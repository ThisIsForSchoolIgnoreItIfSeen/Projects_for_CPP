#include <vector>
#include <utility>

//item is too simple for class, including the struct definition in here for sake of simplicity
#ifndef ITEM_S
#define ITEM_S
using namespace std;


struct Item {
  char name[20];
  char description[80];
  //item methods are defined in header because they are giving me trouble when I put them separately
  Item(char n[20],char d[80]);
  Item();
  ~Item();
};

class Room {
  //this will need a lot
 public:
  Item key;
  bool locked;
  char description[120];
  void removeExit(char dir);
  void setExit(char dir, Room* location);
  void setPrev(Room* prev);
  void printExits();
  Room* getExit(char key);
  void rPrev();
  Room(char desc[80]);
  ~Room();
private:
  vector<Item*> items;
  vector<pair<char,Room*>> exits;
};

class node {
public:
  int value;
  node* next;
  void append(int value);
  node();
  node(int a);
  ~node();
};

struct player {
  vector<Item*> items;
  void displayItems();
  void play(Room* current, bool hallway, int rounds, Room* winRoom);
  player();
  ~player();
};

#endif
