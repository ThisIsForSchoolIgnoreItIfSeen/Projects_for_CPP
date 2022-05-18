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
void remove(BNode<int>* &head, BNode<int>* rid, int removed);
void removeBalance(BNode<int>* &head, BNode<int>* db);


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

    remove(head, head, check);
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

void remove(BNode<int>* &head, BNode<int>* rid, int removed) {
  if (rid == NULL) {
    return;
  } else if (rid->getValue() < removed) {
    if (rid->getLeft() != NULL) {
      remove(head, rid->getLeft(), removed);
    }
    return;
  } else if (rid->getValue() > removed) {
    if (rid->getRight() != NULL) {
      remove(head, rid->getRight(), removed);
    }
    return;
  }

  
  BNode<int>* par = rid->getParent();
  //already know this is the right node time for pain
  if (rid->color == R) {
    //easier
    if (rid->getLeft() != NULL) {
      if (rid->getRight() != NULL) {
	//two children
	BNode<int>* n = rid->getLeft()->largestChild();
	rid->setVaue(n->getValue());
	n->setValue(removed);
	remove(head, n, removed);
      } else {
	//one child
	if (head != rid) {
	  if (par->getLeft() == rid) {
	    par->setLeft(rid->getLeft());
	    delete rid;
	    rid = par->getLeft();
	  } else {
	    par->setRight(rid->getLeft());
	    delete rid;
	    rid = par->getLeft();
	  }
	} else {
	  head = rid->getLeft();
	  delete rid;
	  head->setParent(NULL);
	}
      }
    } else if (rid->getRight() != NULL) {
      //only one child, pull it up
      if (head != rid) {
	if (par->getLeft() == rid) {
	  par->setLeft(rid->getRight());
	  delete rid;
	  rid = par->getLeft();
	} else {
	  par->setRight(rid->getRight());
	  delete rid;
	  rid = par->getLeft();
	}
      } else {
	head = rid->getRight();
	delete rid;
	head->setParent(NULL);
      }
    } else {
      //no children
      if (rid != head) {
	if (par->getLeft() == rid) {
	  par->setLeft(NULL);
	} else {
	  par->setRight(NULL);
	}
	delete rid;
      } else {
	head = NULL;
	delete rid;
      }
    }
  } else {
    //harder
    if (rid->getLeft() != NULL) {
      if (rid->getRight() != NULL) {
	//two children
	BNode<int>* n = rid->getLeft()->largestChild();
	rid->setVaue(n->getValue());
	n->setValue(removed);
	remove(head, n, removed);
      } else {
	//one child
	if (head != rid) {
	  if (par->getLeft() == rid) {
	    par->setLeft(rid->getLeft());
	    delete rid;
	    rid = par->getLeft();
	  } else {
	    par->setRight(rid->getLeft());
	    delete rid;
	    rid = par->getLeft();
	  }
	  
	  if (rid->color == R) {
	    rid->color = B;
	  } else {
	    removeBalance(head, rid);
	  }
	  
	} else {
	  head = rid->getLeft();
	  delete rid;
	  head->setParent(NULL);
	}
      }
    } else if (rid->getRight() != NULL) {
      //only one child, pull it up
      if (head != rid) {
	if (par->getLeft() == rid) {
	  par->setLeft(rid->getRight());
	  delete rid;
	  rid = par->getLeft();
	} else {
	  par->setRight(rid->getRight());
	  delete rid;
	  rid = par->getLeft();
	}
	
	if (rid->color == R) {
	  rid->color = B;
	} else {
	  removeBalance(head, rid);
	}
	
      } else {
	head = rid->getRight();
	delete rid;
	head->setParent(NULL);
      }
    } else {
      //no children
      if (par != NULL) {
	removeBalance(head, rid);
	if (par->getLeft() == rid) {
	  par->setLeft(NULL);
	} else {
	  par->setRight(NULL);
	}
	delete rid;
      } else {
	head = NULL;
	delete rid;
      }
    }
  }
}

void removeBalance(BNode<int>* &head, BNode<int>* db) {
  if (db == head) {
    return;
  }

  char side;
  BNode<int>* sib;
  BNode<int>* par = db->getParent();

  if (par->getLeft == db) {
    side = 'l';
    sib = par->getRight();
  } else {
    side = 'r';
    sib = par->getLeft();
  }

  if (sib == NULL || sib->color == B) {
    //rotations on sibling
  } else {
    //rotations on parent to make sibling black
    if (side = 'l') {
      par->setRight(sib->getLeft());

      if (par == head) {
	head = sib;
	head->setParent(NULL);
	head->setLeft(par);
      } else {
	BNode<int> grandp = par->getParent();
	sib->setLeft(par);
	if (grandp->getLeft() == par) {
	  grandp->setLeft(sib);
	} else {
	  grandp->setRight(sib);
	}
      }
    } else {
      par->setLeft(sib->getRight());

      if (par == head) {
	head = sib;
	head->setParent(NULL);
	head->setRight(par);
      } else {
	BNode<int> grandp = par->getParent();
	sib->setRight(par);
	if (grandp->getLeft() == par) {
	  grandp->setLeft(sib);
	} else {
	  grandp->setRight(sib);
	}
      }
    }
    sib->color = B;
    par->color = R;
    removeBalance(head, db);
  }
}
