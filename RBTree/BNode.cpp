#include "BNode.h"
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

char colorChar(colour c) {
  if (c == red) {
    return 'r';
  } else {
    return 'b';
  }
}

template <class T>
T BNode<T>::getValue() {
  return val;
}

template <class T>
BNode<T>* BNode<T>::getLeft() {
  return left;
}

template <class T>
BNode<T>* BNode<T>::getRight() {
  return right;
}

template <class T>
BNode<T>* BNode<T>::getParent() {
  return parent;
}

template <class T>
BNode<T>* BNode<T>::largestChild() {
  if (right == NULL) {
    return this;
  } else {
    return right->largestChild();
  }
}

template <class T>
void BNode<T>::setRight(BNode<T>* n) {
  right = n;
  if (n != NULL) {
    n->setParent(this);
  }
}

template <class T>
void BNode<T>::setLeft(BNode<T>* n) {
  left = n;
  if (n != NULL) {
    n->setParent(this);
  }
}

template <class T>
void BNode<T>::setParent(BNode<T>* n) {
  parent = n;
}

template <class T>
void BNode<T>::setVal(T n) {
  val = n;
}

template <class T>
void BNode<T>::searchAdd(T n) {
  if (n > val) {
    //right
    if (right == NULL) {
      right = new BNode(n, red);
      right->setParent(this);
      right->balance();
    } else {
      right->searchAdd(n);
    }
  } else {
    //left
    if (left == NULL) {
      left = new BNode(n, red);
      left->setParent(this);
      left->balance();
    } else {
      left->searchAdd(n);
    }
  }
}

template <class T>
void BNode<T>::searchAdd(BNode<T>* n) {
  if (n->getValue() > val) {
    //right
    if (right == NULL) {
      right = n;
      right->setParent(this);
      right->balance();
    } else {
      right->searchAdd(n);
    }
  } else {
    //left
    if (left == NULL) {
      left = n;
      left->setParent(this);
      left->balance();
    } else {
      left->searchAdd(n);
    }
  }
}

template <class T>
void BNode<T>::balance() {
  if ((parent == NULL) || (parent->color == black) || (color == black)) {
    return;
  }
  BNode<T>* grandp = parent->getParent();
  BNode<T>* unc;
  char side;
  char parSide;
  if (parent->getLeft()==this) {
    side = 'l';
  } else {
    side = 'r';
  }
  if (grandp == NULL) {
    parent->color = black;
    return;
  }

  if (grandp->getLeft() == parent) {
    parSide = 'l';
    unc = grandp->getRight();
  } else {
    parSide = 'r';
    unc = grandp->getLeft();
  }

  if ((unc != NULL) && (unc->color == red) && (parent->color == red)) {
    grandp->color = red;
    parent->color = black;
    unc->color = black;
    grandp->balance();
  } else {
    if (side == parSide) {
      //single rotation no re-balance
      if (side == 'l') {
	grandp->setLeft(parent->getRight());

	if (grandp->getParent() != NULL) {
	  if (grandp->getParent()->getLeft()==grandp) {
	    grandp->getParent()->setLeft(parent);
	  } else {
	    grandp->getParent()->setRight(parent);
	  }
	} else {
	  parent->setParent(NULL);
	}
	
	parent->setRight(grandp);
	parent->color = black;
	grandp->color = red;
      } else {
	grandp->setRight(parent->getLeft());

	if (grandp->getParent() != NULL) {
	  if (grandp->getParent()->getLeft()==grandp) {
	    grandp->getParent()->setLeft(parent);
	  } else {
	    grandp->getParent()->setRight(parent);
	  }
	} else {
	  parent->setParent(NULL);
	}
	
	parent->setLeft(grandp);
	parent->color = black;
	grandp->color = red;
      }
    } else {
      //child becomes parent, balance parent
      if (side == 'l') {
	parent->setLeft(right);
	setRight(parent);
	grandp->setRight(this);
	right->balance();
      } else {
	parent->setRight(left);
	setLeft(parent);
	grandp->setLeft(this);
	left->balance();
      }
    }
  }
}

template <class T>
void BNode<T>::printr(int sp) {
  if (left != NULL) {
    left->printr(sp + 1);
  }
  for (int i = 1; i < sp; i++) {
    cout << "     ";
  }
  if (sp > 0) {
    cout << "|----";
  }
  cout << val << colorChar(color) << endl;
  if (right != NULL) {
    right->printr(sp + 1);
  }
}

template <class T>
BNode<T>::BNode() {
  left = NULL;
  right = NULL;
  parent = NULL;
}

template <class T>
BNode<T>::BNode(T v) {
  val = v;
  left = NULL;
  right = NULL;
  parent = NULL;
}

template <class T>
BNode<T>::BNode(T v, colour c) {
  val = v;
  left = NULL;
  right = NULL;
  parent = NULL;
  color = c;
}

template class BNode<int>;
