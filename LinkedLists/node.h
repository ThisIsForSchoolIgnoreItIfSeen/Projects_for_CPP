#ifndef NODE_H
#define NODE_H

class student {
 public:
  char firstName[80];
  char lastName[80];
  int id;
  float GPA;
  student(char fName[80],char lName[80],int stid,float stGPA);
  student();
  ~student();
  //displays all the student's information
  void display();
};

class node {
 public:
  //these two are too simple, literally just give you the pointers to the corresponding values btw get certain is 0-indexing
  student* getStudent();
  node* getNext();
  node* getLast();
  node* getCertain(int i);
  //prints all the students in the linked list after current point
  void printAll();
  //appends a node to end of linked list
  void setNext(node* n);
  //use this before destroying a node if you don't want to destroy everything after the node
  void removeNext();
  //initilizes nodes with corresponding values
  node();
  node(student* v);
  node(node* n);
  node(student* v, node* n);
  //destroys value
  ~node();
 private:
  student* val;
  node* next;
};

#endif
