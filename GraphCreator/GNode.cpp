#include "GNode.h"
#include <utility>
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

template class LNode<GNode*>;

void graph::addNode(char* a) {
  GNode* g = new GNode();
  strcpy(g->name, a);
  int i = getHash(a);
  if (nodes[i] == NULL) {
    nodes[i] = new LNode<GNode*>(g);
  } else {
    nodes[i]->append(g);
  }
}

void graph::addVertex() {
  return;
}

int graph::getHash(char* w) {
  int hashVal = 0;
  while (*w) {
    hashVal += *w;
    hashVal = hashVal % 20;
    w++;
  }
  return hashVal;
}

GNode* graph::getNode(char* n) {
  int h = getHash(n);
  bool exists = false;
  for (LNode<GNode*>* i = nodes[h]; i != NULL; i = i->getNext()) {
    if (strcmp(i->getValue()->name,n) == 0) {
      return i->getValue();
    }
  }
  return NULL;
}

vector<GNode*> graph::listNodes() {
  vector<GNode*> e;
  for (int i = 0; i < 20; i++) {
    for (LNode<GNode*>* j = nodes[i]; j != NULL; j = j->getNext()) {
      e.push_back(j->getValue());
    }
  }
  return e;
}

void graph::printTable() {
  vector<GNode*> n = listNodes();
  cout << "     ";
  for (int i = 0; i < n.size(); i++) {
    cout << n[i]->name << ",  ";
  }
  cout << endl;
  for (int i = 0; i < n.size(); i++) {
    cout << n[i]->name << "   ";
    for (int j = 0; j < n.size(); j++) {
      if (i == j) {
	cout << "  0  ";
      } else {
	bool connected = false;
	for (auto k = n[i]->connections.begin(); k != n[i]->connections.end(); ++k) {
	  if (k->first == n[j]) {
	    connected = true;
	    cout << " " << k->second << " ";
	  }
	}
	if (!connected) {
	  cout << " -1  ";
	}
      }
    }
    cout << endl;
  }
}

graph::graph() {
  for (int i = 0; i < 20; i++) {
    nodes[i] = NULL;
  }
}

graph::~graph() {
  for (int i = 0; i < 20; i++) {
    LNode<GNode*>* j  = nodes[i];
    while (j!=NULL) {
      LNode<GNode*>* t = j;
      j = t->getNext();
      delete t;
    }
  }
}
    
