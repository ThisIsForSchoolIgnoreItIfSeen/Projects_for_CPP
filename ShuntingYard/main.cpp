#include "BNode.h"
#include "LNode.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include "patterns.hpp"
using namespace std;
using namespace mpark::patterns;

void shuntInput(LNode<char>* output, char parser);
void pop(LNode<char>* n);
//will usually use append method as its simpler and gives problems less often
void push(LNode<char>* n, LNode<char>* p);
//will usually use getlast method as its simpler
LNode<char>* peek(LNode<char>* n);
//enqueue
void backAdd();
//dequeue
void frontRemove();
void printr(LNode<char>* n);

const bool testing = true;

int main() {
  LNode<char>* output = NULL;
  cout << "input equation:\n";
  char parser;
  cin.get(parser);
  shuntInput(output, parser);
  printr(output);
  cout << "AAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHH";
  return 0;
}

void shuntInput(LNode<char>* output, char parser) {
  LNode<char>* ops = NULL;
  while (parser != 0 && parser != 10 && parser != '\n' && parser != '\0' && parser != ')') {
    cout << parser << endl;
    if (parser == ' ') {
      if (testing) {
	cout << "space\n";
      }
    } else if (parser == '(') {
      cin.get(parser);
      shuntInput(output,parser);
    } else if (parser >= '0' && parser <= '9') {
      if (testing)
	cout << "num\n";
      if (output != NULL)
	output->append(parser);
      else
	output = new LNode<char>(parser);
    } else {
      if (testing)
	cout << "operator\n";
      if (ops != NULL)
	ops->append(parser);
      else
	ops = new LNode(parser);
    }
    cin.get(parser);
  }
  output->append(ops);
}

void pop(LNode<char>* n) {
  delete n->getLast();
  n->getLast()->setNext(NULL);
}

void push(LNode<char>* n, LNode<char>* p) {
  n->append(p);
}

LNode<char>* peek(LNode<char>* n) {
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
