/*
things are going on, you alone must decipher, the comments are dark, nonexistent
*/
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include "BNode.h"
using namespace std;

void loop(BNode<int>* head);
void adder(BNode<int>* head, int added);

int main() {
  BNode<int>* head = NULL;
  loop(head);
  
  return 0;
}

void loop(BNode<int>* head) {
  cout << "Would you like to 'P'rint the tree, 'I'nput numbers, 'R'emove numbers, 'C'heck for numbers, or 'Q'uit\n'P', 'I', 'R', 'C', or 'Q':";
  char input;
  cin >> input;
  cin.ignore(80,'\n');
  
  if (input=='i'||input=='I') {
    cout << "Would you like to input numbers 'M'anually or through a 'F'ile?\n";
    cin >> input;
    
    if (input=='m'||input=='M') {
      //manual input
      int added;
      cout << "Enter Number:";
      cin >> added;
      if (head == NULL) {
	head = new BNode<int>(added);
      } else {
	adder(head, added);
      }
    } else if ((input == 'f') || (input == 'F')) {
      //file input
      char fileName[80];
      cin.ignore(100,'\n');
      cout << "Which file? ";
      cin.get(fileName, 80, '\n');
      ifstream reader(fileName);
      int added;
      while (reader >> added) {
	if (head == NULL) {
	  head = new BNode<int>(added);
	} else {
	  adder(head, added);
	}
      }
    }
  } else if ((input == 'p') || (input == 'P')) {
    //print
    head->printr(0);
  } else if ((input == 'q') || (input == 'Q')) {
    return;
  }
  loop(head);
}

void adder(BNode<int>* head, int added) {
  if (head == NULL) {
    head = new BNode<int>(added);
    return;
  }
  if (added > head->getValue()) {
    if (head->getLeft()==NULL) {
      head->setLeft(new BNode<int>(added));
    } else {
      adder(head->getLeft(),added);
    }
  } else {
    if (head->getRight()==NULL) {
      head->setRight(new BNode<int>(added));
    } else {
      adder(head->getRight(),added);
    }
  }
}
