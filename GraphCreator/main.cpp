/*
basic graph creator implementing algorithms for transversal
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include "GNode.h"
using namespace std;

void loop(graph g);


int main() {
  graph g;
  for (int i = 0; i < 20; i++) {
    g.nodes[i] = NULL;
  }
  loop(g);
  return 0;
}

void loop(graph g) {
  char input;
  cout << "Do you want to add, delete, measure, print or quit?\n'a' 'd' 'm' 'p' or 'q': ";
  cin >> input;
  input = tolower(input);
  char name[20];
  switch (input) {
  case 'a':
    //add node or vertex
    cout << "Do you want to add a node or a vertex?\n'n' or 'v'";
    cin >> input;
    input = tolower(input);
    switch (input) {
    case 'n':
      cout << "what will you name the node?\n";
      cin.ignore(20, '\n');
      cin.get(name, 20, '\n');
      cin.ignore(20, '\n');
      for (int i = 0; i < 20; i++) {
	name[i] = tolower(name[i]);
      }
      g.addNode(name);
      break;
    case 'v':
      g.addVertex();
      break;
    }
    break;
  case 'd':
    //delete node or vertex
    cout << "Do you want to remove a node or a vertex?\n'n' or 'v'";
    cin >> input;
    input = tolower(input);
    switch (input) {
    case 'n':
      cout << "Which Node do you want to delete?\n";
      cin.ignore(20, '\n');
      cin.get(name, 20, '\n');
      cin.ignore(20, '\n');
      for (int i = 0; i < 20; i++) {
	name[i] = tolower(name[i]);
      }
      g.delNode(name);
      break;
    case 'v':
      g.removeVertex();
      break;
    }
    break;
  case 'm':
    //get two nodes and find shortest path, drijka algorithm
    g.printPath();
    break;
  case 'q':
    return;
    break;
  default:
    //print
    g.printTable();
    break;
  }
  loop(g);
}
