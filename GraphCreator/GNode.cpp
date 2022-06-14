#include "GNode.h"
#include <utility>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

template <class T>
void LNode<T>::setNext(LNode<T>* n) {
  next = n;
  if (n != NULL) {
    n->prev = this;
  }
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
    next->prev = this;
  } else {
    next->append(n);
  }
}


template <class T>
LNode<T>::LNode() {
  next = NULL;
  prev = NULL;
}

template <class T>
LNode<T>::LNode(T v) {
  val = v;
  next = NULL;
  prev = NULL;
}

template <class T>
LNode<T>::LNode(LNode<T>* n) {
  next = n;
  n->prev = this;
}

template <class T>
LNode<T>::LNode(T v, LNode<T>* n) {
  val = v;
  next = n;
  n->prev = this;
}

template <class T>
LNode<T>::~LNode() {
  if (val != NULL)
    delete val;
}

template class LNode<GNode*>;

GNode::GNode(char* a) {
  strcpy(name, a);
  
}

void graph::addNode(char* a) {
  int i = getHash(a);
  if (nodes[i] == NULL) {
    nodes[i] = new LNode<GNode*>(new GNode(a));
  } else {
    nodes[i]->append(new GNode(a));
  }
}

void graph::addVertex() {
  char name[20];
  GNode* start = NULL;
  while (start == NULL) {
    cout << "Where will the vertex start?\n";
    cin.ignore(20, '\n');
    cin.get(name, 20, '\n');
    cin.ignore(20,'\n');
    for (int i = 0; i < 20; i++) {
      name[i] = tolower(name[i]);
    }
    start = getNode(name);
    if (start == NULL) {
      cout << "cannot find node, please keep in mind that names are case sensitive\n";
    }
  }
  GNode* end = NULL;
  while (end == NULL) {
    cout << "Where will the vertex end?\n";
    cin.get(name, 20, '\n');
    cin.ignore(20,'\n');
    for (int i = 0; i < 20; i++) {
      name[i] = tolower(name[i]);
    }
    end = getNode(name);
    if (end == NULL) {
      cout << "cannot find node, please keep in mind that names are case sensitive\n";
    }
  }
  int weight;
  cout << "what is the weight of the vector?\n";
  cin >> weight;
  for (auto i = start->connections.begin(); i != start->connections.end(); i++) {
    if (i->first == end) {
      start->connections.erase(i);
    }
  }
  start->connections.push_back(make_pair(end, weight));
  return;
}

void graph::removeVertex() {
  char name[20];
  GNode* start = NULL;
  while (start == NULL) {
    cout << "Where does the vertex start?\n";
    cin.ignore(20, '\n');
    cin.get(name, 20, '\n');
    cin.ignore(20,'\n');
    for (int i = 0; i < 20; i++) {
      name[i] = tolower(name[i]);
    }
    start = getNode(name);
    if (start == NULL) {
      cout << "cannot find node, please keep in mind that names are case sensitive\n";
    }
  }
  GNode* end = NULL;
  while (end == NULL) {
    cout << "Where does the vertex end?\n";
    cin.get(name, 20, '\n');
    cin.ignore(20,'\n');
    for (int i = 0; i < 20; i++) {
      name[i] = tolower(name[i]);
    }
    end = getNode(name);
    if (end == NULL) {
      cout << "cannot find node, please keep in mind that names are case sensitive\n";
    }
  }
  for (auto i = start->connections.begin(); i != start->connections.end(); i++) {
    if (i->first == end) {
      start->connections.erase(i--);
    }
  }
  return;
}

void graph::delNode(char* a) {
  GNode* temp = getNode(a);
  for (int i = 0; i < 20; i++) {
    for (LNode<GNode*>* n = nodes[i]; n != NULL; n = n->next) {
      if (n->val == temp) {
	if (n->prev == NULL) {
	  nodes[i] = n->next;
	  if (n->next != NULL) {
	    n->next->prev = NULL;
	  }
	} else {
	  n->prev->setNext(n->next);
	}
      }
      for (auto j = n->val->connections.begin(); j != n->val->connections.end(); j++) {
	if (j->first == temp) {
	  n->val->connections.erase(j--);
	}
      }
    }
  }
  delete temp;
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
  for (LNode<GNode*>* i = nodes[h]; i != NULL; i = i->next) {
    if (strcmp(i->val->name,n) == 0) {
      return i->val;
    }
  }
  return NULL;
}

vector<GNode*> graph::listNodes() {
  vector<GNode*> e;
  for (int i = 0; i < 20; i++) {
    for (LNode<GNode*>* j = nodes[i]; j != NULL; j = j->next) {
      e.push_back(j->val);
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

bool compPairs(pair<GNode*, int> a, pair<GNode*, int> b) {
  return ((a.second < b.second) && (a.second != -1)) || (b.second == -1);
}

void graph::printPath() {
  char name[20];
  GNode* start = NULL;
  while (start == NULL) {
    cout << "Where do you want to start?\n";
    cin.ignore(20, '\n');
    cin.get(name, 20, '\n');
    cin.ignore(20,'\n');
    for (int i = 0; i < 20; i++) {
      name[i] = tolower(name[i]);
    }
    start = getNode(name);
    if (start == NULL) {
      cout << "cannot find node, please keep in mind that names are case sensitive\n";
    }
  }
  GNode* end = NULL;
  while (end == NULL) {
    cout << "Where do you want to measure to?\n";
    cin.get(name, 20, '\n');
    cin.ignore(20,'\n');
    for (int i = 0; i < 20; i++) {
      name[i] = tolower(name[i]);
    }
    end = getNode(name);
    if (end == NULL) {
      cout << "cannot find node, please keep in mind that names are case sensitive\n";
    }
  }
  //drajaka logic
  vector<pair<GNode*, int>> costs;
  for (int i = 0; i < 20; i++) {
    for (LNode<GNode*>* j = nodes[i]; j != NULL; j = j->next) {
      if (j->val == start) {
	cout << "At least this worked cur: " << j->val->name << endl;
	costs.push_back(make_pair(j->val, 0));
      } else {
	cout << "This is iterating " << j->val->name << endl;
	costs.push_back(make_pair(j->val, -1));
      }
    }
  }
  //find costs and move them where needed in vector
  for (int i = 0; i < costs.size(); i++) {
    sort(costs.begin()+i, costs.end(), compPairs);
    if (costs[i].second == -1) {
      //this node and all subsequent are disconnected from start node
      break;
    }
    //cur is the current pair
    pair<GNode*, int> cur = costs[i];
    for (auto j : cur.first->connections) {
      //going through connections of current node, if any are weighted less they will placed in costs
      for (int k = 0; k < costs.size(); k++) {
	//k is recorded cost j is the recoded direct dist
	if (costs[k].first == j.first) {
	  if ((costs[k].second == -1) || (costs[k].second > cur.second + j.second)) {
	    //going through cur node is either first possible dist or shroter than prev recorded
	    costs[k].second  = cur.second + j.second;
	  }
	  break;
	}
      }
    }
  }
  //print path
  for (int i = 0; i < costs.size(); i++) {
    if (costs[i].first == end) {
      cout << "distance is " << costs[i].second << " units\nPath is:\n";
      break;
    }
  }
  return;
}

graph::graph() {
  for (int i = 0; i < 20; i++) {
    nodes[i] = NULL;
  }
}

graph::~graph() {
  for (int i = 0; i < 20; i++) {
    for (LNode<GNode*>* j = nodes[i]; j != NULL; j = j->next) {
      if ((j != NULL) && (j->prev != NULL)) {
	delete j->prev;
	j->prev = NULL;
      }
    }
  }
}
    
