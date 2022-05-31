/*
basic graph creator implementing algorithms for transversal
*/

#include <iostream>
#include <cmath>
#include <cstring>
#include "LNode.h"
#include "GNode.h"
using namespace std;

void loop(LNode<GNode> rNodes[20]);
int getHash(char* w);


int main() {
  LNode<GNode> rNodes[20];
  for (int i = 0; i < 20; i++) {
    rNodes[i] = NULL;
  }
  loop(rNodes);
  return 0;
}

void loop(LNode<GNode> rNodes[20]) {
  char input;
  cout << "Do you want to add, delete, measure, print or quit?\n'a' 'd' 'm' 'p' or 'q': ";
  cin >> input;
  input = tolower(input);
  switch (input) {
  case 'a':
    //add node or vertex
    break;
  case 'd':
    //delete node or vertex
    break;
  case 'm':
    //get two nodes and find shortest path, drijka algorithm
    break;
  case 'q':
    return;
    break;
  default:
    //print
    break;
  }
  loop(rNodes);
}

int getHash(char *w) {
  int hashVal = 0;
  while (*w) {
    hashVal += *w;
    hashVal = hashVal % 20;
    w++;
  }
  return hashVal;
}
