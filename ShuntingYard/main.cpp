#include "BNode.h"
#include "LNode.h"
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

void pop(LNode<char>* n);
void push(LNode<char>* n, LNode<char>* p);
LNode<char>* peek();
//enqueue
void backAdd();
//dequeue
void frontRemove();
void printr(LNode<char>* n);

int main() {
  LNode<char>* input;
  LNode<char>* ops;
  cout << "input";
  char temp;
  cin.get(temp);
  input = new LNode<char>(temp);
  while (temp != 0 && temp != 10 && temp != '\n' && temp != '\0') {
    cin.get(temp);
    input->append(temp);
  }
  printr(input);
  cout << "AAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHH";
  return 0;
}

void pop(LNode<char>* n) {
  delete n->getLast();
  n->getLast()->setNext(NULL);
}

void push(LNode<char>* n, LNode<char>* p) {
  n->append(p);
}

LNode<char> peek(LNode<char>* n) {
  return n->getLast();
}

void printr(LNode<char>* n) {
  cout << n->getValue();
  if (n->getNext()==NULL) {
    cout << endl;
  } else {
    printr(n->getNext());
  }
}
