#include "LNode.h"
#include "Student.h"
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

template <class T>
T LNode<T>::getValue() {
  return val;
}

template <class T>
LNode<T>* LNode<T>::getNext() {
  return next;
}

template <class T>
LNode<T>* LNode<T>::getLast() {
  if (next==NULL) {
      return this;
  }
  return next->getLast();
}

template <class T>
int LNode<T>::getLength() {
  if (next==NULL) {
    return 1;
  }
  return next->getLength() + 1;
}

template <class T>
LNode<T>* LNode<T>::getCertain(int pos) {
  if ((pos==0)||(next==NULL)) {
    return this;
  }
  return next->getCertain(pos-1);
}

template <class T>
void LNode<T>::setNext(LNode<T>* n) {
  next=n;
}

template <class T>
void LNode<T>::setValue(T n) {
  val = n;
}

template <class T>
void LNode<T>::append(LNode<T>* n) {
  if (next==NULL) {
    next = n;
  } else {
    next->append(n);
  }
}

template <class T>
void LNode<T>::append(T n) {
  if (next==NULL) {
    next = new LNode<T>(n);
  } else {
    next->append(n);
  }
}


template <class T>
LNode<T>::LNode() {
  next = NULL;
}

template <class T>
LNode<T>::LNode(T v) {
  val = v;
  next = NULL;
}

template <class T>
LNode<T>::LNode(LNode<T>* n) {
  next = n;
}

template <class T>
LNode<T>::LNode(T v, LNode<T>* n) {
  val = v;
  next = n;
}

template <class T>
LNode<T>::~LNode() {
  delete val;
}

template class LNode<Student*>;
