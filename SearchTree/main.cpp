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
int count(BNode<int>* head, int added, int = 0);
bool deleter(BNode<int>* head, int deleted);
int rightmost(BNode<int>* head);
void deleteRightmost(BNode<int>* head);

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
	head = new BNode<int>(added);
      } else {
	adder(head, added);
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
	  head = new BNode<int>(added);
	} else {
	  adder(head, added);
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
    deleter(head, check);
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
  if (added >= head->getValue()) {
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

bool deleter(BNode<int>* head, int deleted) {
  if (head == NULL) {
    return false;
  }
  if (head->getValue() == deleted) {
    if ((head->getRight()==NULL) || (head->getLeft()==NULL)) {
      return true;
    } else {
      head->setVal(rightmost(head->getLeft()));
      deleteRightmost(head->getLeft());
    }
  }

  BNode<int>* temp;
    
  if (head->getValue() < deleted) {
    if (deleter(head->getLeft(), deleted)) {
      temp = head->getLeft();
      if (temp->getLeft()==NULL) {
	head->setLeft(temp->getRight());
	delete temp;
      } else {
	head->setLeft(temp->getLeft());
	delete temp;
      }
    }
  } else {
    if (deleter(head->getRight(), deleted)) {
      temp = head->getRight();
      if (temp->getLeft()==NULL) {
	head->setRight(temp->getRight());
	delete temp;
      } else {
	head->setRight(temp->getLeft());
	delete temp;
      }
    }
  }
  return false;
}

int rightmost(BNode<int>* head) {
  if (head->getRight()==NULL) {
    return head->getValue();
  }
  return rightmost(head->getRight());
}

void deleteRightmost(BNode<int>* head) {
  if (head == NULL) {return;}
  if (head->getRight() == NULL) {return;}
  if (head->getRight()->getRight() == NULL) {
    delete head->getRight();
    head->setRight(NULL);
    return;
  }
  deleteRightmost(head->getRight());
}
