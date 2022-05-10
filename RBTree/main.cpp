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
void remove(BNode<int>* head, int removed);

const colour R = red;
const colour B = black;

int main() {
  BNode<int>* head = NULL;
  //starts loop
  loop(head);
  
  return 0;
}

void loop(BNode<int>* head) {
  cout << "Would you like to 'P'rint the tree, 'I'nput numbers, 'D'elete numbers, 'C'heck for numbers, or 'Q'uit\n'P', 'I', 'D', 'C', or 'Q': ";
  char input;
  cin >> input;
  input = tolower(input);
  cin.ignore(80,'\n');
  int check;
  switch (input) {
  case 'i':
    //input
    cout << "Would you like to input numbers 'M'anually or through a 'F'ile?\n";
    cin >> input;
    input  = tolower(input);
    int added;
    switch (input) {
    case 'm':
      //manual
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
      break;
    default:
      //file
      char fileName[80];
      cin.ignore(100,'\n');
      cout << "Which file? ";
      cin.get(fileName, 80, '\n');
      ifstream reader(fileName);
      while (reader >> added) {
	//adds each #
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
      break;
    }
    break;
  case 'c':
    //search
    cout << "What number would you like to check is in the binary tree?\n";
    cin >> check;
    cout << "The number you gave appears " << count(head, check) << " time(s) in the binary tree\n";
    break;
  case 'p':
    //print
    if (head == NULL) {
      cout << "The tree is empty";
    } else {
      head->printr(0);
    }
    break;
  case 'd':
    //deletion
    cout << "What number would you like to delete from the binary tree?\n";
    cin >> check;

    remove(head, check);
    break;
  case 'q':
    return;
    break;
  }
  loop(head);
}

int count(BNode<int>* head, int check, int counter) {
  //check func
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

void remove(BNode<int>* head, int removed) {
  if (head == NULL) {
    return;
  } else if (head->getValue() < removed) {
    if (head->getLeft() != NULL) {
      remove(head->getLeft(), removed);
    }
    return;
  } else if (head->getValue() > removed) {
    if (head->getRight() != NULL) {
      remove(head->getRight(), removed);
    }
    return;
  }
  //already know this is the right node time for pain
  if (head->color == R) {
    //easier
    if (head->getLeft() != NULL) {
      if (head->getRight() != NULL) {
	//two children

      } else {
	//one child

      }
    } else if (head->getRight() != NULL) {
      //only one child, pull it up
      
    } else {
      //no children

    }
  } else {
    //harder
    if (head->getLeft() != NULL) {
      if (head->getRight() != NULL) {
	//two children

      } else {
	//one child

      }
    } else if (head->getRight() != NULL) {
      //only one child, pull it up
      
    } else {
      //no children

    }
  }
}
 
