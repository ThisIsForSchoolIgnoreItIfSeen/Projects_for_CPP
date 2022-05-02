/*
Kabir Vidyarthi
4/28/22
Red black tree
inputs  numbers into a red-black tree, not everything has been fixed yet
*/
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include "BNode.h"
using namespace std;

void loop(BNode<int>* head);
int count(BNode<int>* head, int added, int = 0);

const colour R = red;
const colour B = black;

int main() {
  BNode<int>* head = NULL;
  loop(head);
  
  return 0;
}

void loop(BNode<int>* head) {
  cout << "Would you like to 'P'rint the tree, 'I'nput numbers, 'D'elete numbers, 'C'heck for numbers, or 'Q'uit\n'P', 'I', 'D', 'C', or 'Q': ";
  char input;
  cin >> input;
  cin.ignore(80,'\n');
  
  if (input=='i'||input=='I') {
    cout << "Would you like to input numbers 'M'anually or through a 'F'ile?\n";
    cin >> input;
    
    if (input=='m'||input=='M') {
      int added;
      cout << "Enter Number:";
      cin >> added;
      if (head == NULL) {
	head = new BNode<int>(added, B);
      } else {
	head->searchAdd(added);
      }
      while (head->getParent() != NULL) {
	head = head->getParent();
      }
      if (head->color == R) {
	head->color = B;
      }
    } else if ((input == 'f') || (input == 'F')) {
      char fileName[80];
      cin.ignore(100,'\n');
      cout << "Which file? ";
      cin.get(fileName, 80, '\n');
      ifstream reader(fileName);
      int added;
      while (reader >> added) {
	if (head == NULL) {
	  head = new BNode<int>(added, B);
	} else {
	  head->searchAdd(added);
	  while (head->getParent() != NULL) {
	    head = head->getParent();
	  }
	  if (head->color == R) {
	    head->color = B;
	  }
	}
      }
    }
  } else if ((input == 'c') || (input == 'C')) {
    cout << "What number would you like to check is in the binary tree?\n";
    int check;
    cin >> check;
    cout << "The number you gave appears " << count(head, check) << " time(s) in the binary tree\n";
  } else if ((input == 'p') || (input == 'P')) {
    head->printr(0);
  } else if ((input == 'd') || (input =='D')) {
    cout << "What number would you like to delete from the binary tree?\n";
    int check;
    cin >> check;
  } else if ((input == 'q') || (input == 'Q')) {
    return;
  }
  loop(head);
}

int count(BNode<int>* head, int check, int counter) {
  if (head == NULL) {
    return counter;
  }
  if (head->getValue() == check) {
    counter++;
  }
  if (head->getValue() <= check) {
    counter = count(head->getLeft(), check, counter);
  } else {
    counter = count(head->getRight(), check, counter);
  }
  return counter;
}
