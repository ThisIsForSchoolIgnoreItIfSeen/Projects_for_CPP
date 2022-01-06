#include "node.h"
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

student::student(char fName[80],char lName[80],int stid,float stGPA) {
  strcpy(firstName,fName);
  strcpy(lastName,lName);
  id = stid;
  GPA = stGPA;
}

student::student() {
  cout << "First name:\n";
  cin.get(firstName,80,'\n');
  cin.ignore(80,'\n');
  cout << "Last name:\n";
  cin.get(lastName,80,'\n');
  cin.ignore(80,'\n');
  cout << "ID:\n";
  cin >> id;
  cout << "GPA:\n";
  cin >> GPA;
  GPA = round(GPA*100)/100;
  cin.ignore(80,'\n');
}

student::~student() {
  cout << "File for: " << firstName << ' ' << lastName << " Has been removed\n";
}

void student::display() {
  cout << "Name: " << firstName << " " << lastName << "\nStudent ID: " << id << "\nWeighted GPA:" << GPA << "\nUnweighted GPA: ~" << round(GPA*100*0.987)/100 << '\n';
}

student* node::getStudent() {
  return val;
}

node* node::getNext() {
  if (next==NULL) {
      return this;
    }
  return next;
}

node* node::getLast() {
  if (next==NULL) {
      return this;
    }
  return next->getLast();
}

node* node::getCertain(int i) {
  if ((i==0)||(next==NULL)) {
    return this;
  }
  return next->getCertain(i-1);
}

void node::printAll() {
  val->display();
  if (next != NULL) {
      next->printAll();
    }
}

void node::setNext(node* n) {
  if (next == NULL) {
      next = n;
    } else {
    next->setNext(n);
  }
}

void node::removeNext() {
  next = NULL;
}

node::node() {
  next = NULL;
}

node::node(student* v) {
  val = v;
  next = NULL;
}

node::node(node* n) {
  next = n;
}

node::node(student* v, node* n) {
  val = v;
  next = n;
}

node::~node() {
  delete val;
}
