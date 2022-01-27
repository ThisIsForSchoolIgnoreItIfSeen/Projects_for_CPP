//Student List
/*
This Program compiles a list of students and and their information, it also allows the user to access the information and edit the list in a small amount of ways, excess functionality may be added as nessecary
*/
//Author: Kabir Vidyarthi
//Date: 10/1/21
#include <iostream>
#include "Node.h"
#include "Student.h"
#include <cmath>
using namespace std;


bool charComparer(char *f, char *s); //done
void loop(Node* head); //done
void remove(Node* n, int id); // done
void remove(Node* n, Node* p, int id);
void printr(Node* n); //done
void push_back(Node* n, Student* s); //done
float adder(Node* n, float f, int c);

int main() {
  loop(new Node());
  
  return(0);
}

void loop(Node* head) {
  char command[10] = "print";
  char commands[4][10] = {"add","delete","print","mean"};
  //get command
  cout << "Would you like to 'ADD', 'DELETE', 'PRINT', 'MEAN', or 'QUIT'?\n";
  cin.get(command,10,'\n');
  cin.ignore(80,'\n');
  //puts command in lowercase to prevent errors
  for (int i=0;i<10;i++) {
    if (command[i]==0||command[i]==10)
      break;
    command[i] = tolower(command[i]);
  }
  if (charComparer(command,commands[0])) {
    //adds
    push_back(head,new Student());
  } else if (charComparer(command,commands[1])) {
    //delete
    int id;
    cout << "Which student would you like to remove\nID:";
    cin >> id;
    cin.ignore(80,'\n');
    //recursive loop to get rid of the right student
    remove(head,id);
  } else if (charComparer(command,commands[2])) {
    //print
    printr(head);
  } else if (charComparer(command,commands[3])) {
    //average
    float count = adder(head,0,0);
    if (count>0)
      cout << "Average GPA:" << count << endl;
    else
      cout << "No Students in system";
  } else {
    return;
  }
  loop(head);
}

bool charComparer(char *f, char *s) {
  //something to compare the char arrays, bc we can't use strings
  while (*f&&*s) {
    if (*f!=*s) {
      return false;
    }
    f++;
    s++;
  }
  return true;
}

void printr(Node* n) {
  //recursive print
  if (n->getStudent()!=NULL)
    n->getStudent()->display();
  if (n->getNext()!=NULL)
    printr(n->getNext());
}

void push_back(Node* n, Student* s) {
  if (n->getStudent()==NULL) {
    n->setStudent(s);
    return;
  }
  if (n->getNext()==NULL)
    n->setNext(new Node());
  push_back(n->getNext(),s);
}

void remove(Node* n, int id) {
  if (n->getStudent()!=NULL&&n->getStudent()->id==id) {
    char conf;
    n->getStudent()->display();
    cout << "Delete(y/n):";
    cin >> conf;
    cin.ignore(80,'\n');
    if (conf != 'n') {
      delete n->getStudent();
      n->setStudent(NULL);
    }
  }
  if (n->getNext()!=NULL) {
    remove(n->getNext(),n,id);
  }
}

void remove(Node* n, Node* p, int id) {
  if (n->getStudent()!=NULL&&n->getStudent()->id==id) {
    char conf;
    n->getStudent()->display();
    cout << "Delete(y/n):";
    cin >> conf;
    cin.ignore(80,'\n');
    if (conf != 'n') {
      p->setNext(n->getNext());
      delete n;
      if (p->getNext()!=NULL) {
	remove(p->getNext(),p,id);
      }
      return;
    }
  }
  if (n->getNext()!=NULL) {
    remove(n->getNext(),n,id);
  }
}

float adder(Node* n, float i, int c) {
  if (n->getStudent()!=NULL) {
    i+=n->getStudent()->GPA;
    c++;
  }
  if (n->getNext()!=NULL) {
    return adder(n->getNext(), i, c);
  } else {
    if (c>0)
      return i/(float)c;
    else
      return (float)c;
  }
}
