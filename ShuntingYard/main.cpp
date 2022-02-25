#include "BNode.h"
#include "LNode.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include "patterns.hpp"
using namespace std;
using namespace mpark::patterns;

void shuntInput(LNode<char>* &output, char parser);
LNode<char>* pop(LNode<char>* n);
LNode<char>* popD(LNode<char>* n);
//will usually use append method as its simpler and gives problems less often
void push(LNode<char>* n, LNode<char>* p);
char peek(LNode<char>* n);
//enqueue
void backAdd();
//dequeue
void frontRemove();
void printr(LNode<char>* n);
bool isHigher(char a, char b);
void growsTrees(BNode<char>* &tree, LNode<char>* &stuff);
void printPre(BNode<char>* tree);
void printIn(BNode<char>* tree);
void printPost(BNode<char>* tree);

const bool testing = true;

int main() {
  LNode<char>* output = NULL;
  BNode<char>* tree = NULL;
  cout << "input equation:\n";
  char parser;
  cin.get(parser);
  //gets the postfix
  shuntInput(output, parser);
  //prints out postfix
  cout << "Shunted Print\n";
  printr(output);
  //makes tree
  growsTrees(tree, output);
  //prints
  cout << "\nPrefix notation\n";
  printPre(tree);
  cout << "\nInfix notation\n";
  printIn(tree);
  cout << "\nPostfix notationn\n";
  printPost(tree);
  //displays my state of mind
  cout << "\nAAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHH";
  return 0;
}

void shuntInput(LNode<char>* &output, char parser) {
  LNode<char>* ops = NULL;
  //makes sure to end the damn thing eventually
  while (parser != 0 && parser != 10 && parser != '\n' && parser != '\0' && parser != ')') {
    //somehow works, makes it so that the expressions within parenthesis are read correctly
    if (parser == '(') {
      cin.get(parser);
      shuntInput(output,parser);
    } else if (parser >= '0' && parser <= '9') {
      //puts numbers at the end of the queue
      if (output != NULL) {
	output->append(new LNode(parser));
      } else {
	output = new LNode<char>(parser);
      }
    } else if (parser != ' ') {
      //this is why I included my state of mind earlier
      if (ops != NULL) {
	//handles operations when there are multiple
	if (isHigher(peek(ops),parser)) {
	  output->append(ops->getLast());
	  ops = pop(ops);
	}
	//this if/else block has somehow caused the most problems out of EVERYTHING in this program
	if (ops!=NULL) {
	  ops->append(parser);
	} else {
	  ops = new LNode(parser);
	}
      } else {
	//I like this code block, BECAUSE ITS THE ONLY SIMPLE THING ABOUT OPERATORS IN THIS HELLSCAPE
	ops = new LNode(parser);
      }
    }
    cin.get(parser);
  }
  if (testing) {
    printr(ops);
  }
  //places remaining operators from stack onto queue
  while (ops!=NULL) {
    output->append(ops->getLast());
    ops = pop(ops);
  }
}

LNode<char>* pop(LNode<char>* n) {
  //sets last node to NULL
  if ((n==NULL)||(n->getNext()==NULL)) {return NULL;}
  n->setNext(pop(n->getNext()));
  return n;
}

LNode<char>* popD(LNode<char>* n) {
  //same as pop, but it deletes the last node so it doesn't clutter memory
  if (n==NULL) {
    return NULL;
  }
  if (n->getNext()==NULL) {
    delete n;
    return NULL;
  }
  n->setNext(pop(n->getNext()));
  return n;
}

void push(LNode<char>* n, LNode<char>* p) {
  n->append(p);
}

char peek(LNode<char>* n) {
  return n->getLast()->getValue();
}

void printr(LNode<char>* n) {
  //prints out linked lists
  if (n==NULL) {
    cout << "passed NULL Node\n";
    return;
  }
  char a = n->getValue();
  cout << a;
  if (n->getNext()==NULL) {
    cout << endl;
  } else {
    cout << ' ';
    printr(n->getNext());
  }
}

bool isHigher(char a, char b) {
  //checks which operation has higher precedence
  if ((a == b) && (a != '^')) {
    return true;
  }
  if ((a == '^') && (b != '^')) {
    return true;
  }
  if (((a == '*') || (a == '/')) && (b != '^')) {
    return true;
  }
  if (((a == '+') || (a == '-')) && ((b == '+') || (b == '-'))) {
    return true;
  }
  return false;    
}

void growsTrees(BNode<char>* &tree, LNode<char>* &stuff) {
  if (tree==NULL) {
    if (stuff == NULL) {
      return;
    }
    tree = new BNode(stuff->getLast()->getValue());
    stuff = popD(stuff);
  }
  if (!(tree->getValue() > '0' && tree->getValue() < '9')) {
    BNode<char>* left = tree->getLeft();
    BNode<char>* right = tree->getRight();
    growsTrees(left, stuff);
    growsTrees(right,stuff);
  }
}

void printPre(BNode<char>* tree) {
  if (tree == NULL) {
    return;
  }
  cout << tree->getValue();
  printPre(tree->getLeft());
  printPre(tree->getRight());
}

void printIn(BNode<char>* tree) {
  if (tree == NULL) {
    return;
  }
  printIn(tree->getLeft());
  cout << tree->getValue();
  printIn(tree->getRight());
}

void printPost(BNode<char>* tree) {
  if (tree == NULL) {
    return;
  }
  printPost(tree->getLeft());
  printPost(tree->getRight());
  cout << tree->getValue();
}
