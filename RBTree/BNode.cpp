#include "BNode.h"
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

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
void BNode<T>::setRight(BNode<T>* n) {
  right = n;
  n->setParent(this);
}

template <class T>
void BNode<T>::setLeft(BNode<T>* n) {
  left = n;
  n->setParent(this);
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
  
}

template <class T>
void BNode<T>::searchAdd(BNode<T>* n) {
}

template <class T>
void BNode<T>::balance() {
  BNode<T> grandp = parent->getParent();
  BNode<T> unc;
  if (grandp->getLeft() == parent) {
    unc = grandp->getRight();
  } else {
    unc = grandp->getLeft();
  }
}

template <class T>
void BNode<T>::printr(int sp) {
  if (left != NULL) {
    left->printr(sp + 1);
  }
  for (int i = 0; i < sp; i++) {
    cout << "     ";
  }
  cout << val << endl;
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
