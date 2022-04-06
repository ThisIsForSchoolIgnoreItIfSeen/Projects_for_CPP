//hash table
/*
This Program compiles a list of students and and their information, it also allows the user to access the information and edit the list in a small amount of ways, excess functionality may be added as nessecary
*/
//Author: Kabir Vidyarthi
//Date: 1/31/21
#include "LNode.h"
#include "Student.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
using namespace std;

bool charComparer(char *f, char *s);
void loop(LNode<Student*>** students, int num, int SIZE);
void printr(LNode<Student*>* student);

int main() {
  srand(time(NULL));
  LNode<Student*>* students[100];
  for (int i = 0; i < 100; i++) {
    students[i] = NULL;
  }
  //code loop
  loop(students, 1, 100);
  
  return(0);
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

void loop(LNode<Student*>** students, int num, int SIZE) {
  char command[10] = "print";
  char commands[3][10] = {"add","delete","print"};
  //get command
  cout << "Would you like to 'ADD', 'DELETE', 'PRINT', or 'QUIT'?\n";
  cin.get(command,10,'\n');
  cin.ignore(80,'\n');
  //puts command in lowercase to prevent errors
  for (int i=0;i<10;i++) {
    if (command[i]==0||command[i]==10) {
      break;
    }
    command[i] = tolower(command[i]);
  }
  if (charComparer(command,commands[0])) {
    //adds
    int amnt = rand() % 36 + 1;
    for (int i=0;i < amnt; i++) {
      if (students[num%SIZE]==NULL) {
	students[num%SIZE] = new LNode<Student*>(new Student(num));
      } else {
	students[num%SIZE]->append(new Student(num));
      }
      //check to rehash
      if (students[num%SIZE]->getLength()>3) {
	cout << "Too many students, rehashing...";
	//rehash
	LNode<Student*>* nStudents[SIZE*2];
	for (int i = 0; i < SIZE*2; i++) {
	  nStudents[i]=NULL;
	}
	for (int i = 0; i < SIZE; i++) {
	  //loops through array
	  if (students[i]==NULL) {
	    continue;
	  }
	  LNode<Student*>* j = students[i];
	  LNode<Student*>* temp = j->getNext();
	  while (j!=NULL) {
	    //loops through linked lists
	    j->setNext(NULL);
	    if (nStudents[j->getValue()->id%(SIZE*2)]==NULL) {
	      nStudents[j->getValue()->id%(SIZE*2)] = j;
	    } else {
	      nStudents[j->getValue()->id%(SIZE*2)]->append(j);
	    }
	    j = temp;
	    if (j!=NULL) {
	      temp = j->getNext();
	    }
	  }
	}
	SIZE *= 2;
	students = nStudents;
      }
      num++;
    }
  } else if (charComparer(command,commands[1])) {
    //deletes
    int id;
    cout << "Which student would you like to remove\nID:";
    cin >> id;
    cin.ignore(80,'\n');
    //for loop to get rid of the right student
    if (students[id%SIZE]!=NULL && students[id%SIZE]->getValue()->id==id) {
      char confirm;
      LNode<Student*>* temp = students[id%SIZE];
      cout << "Are you sure you want to remove " << temp->getValue()->firstName << ' ' << temp->getValue()->lastName << "?\n'y' or 'n':";
      cin >> confirm;
      cin.ignore(80,'\n');
      if (confirm == 'y' || confirm == 'Y') {
	students[id%SIZE] = temp->getNext();
	delete temp;
      }
    } else {
      for (LNode<Student*>* j=students[id%100];j!=NULL;j=j->getNext()) {
	LNode<Student*>* i = j->getNext();
	if (i->getValue()->id==id) {
	  char confirm;
	  cout << "Are you sure you want to remove " << (i)->getValue()->firstName << ' ' << i->getValue()->lastName << "?\n'y' or 'n':";
	  cin >> confirm;
	  cin.ignore(80,'\n');
	  if (confirm == 'y' || confirm == 'Y') {
	    j->setNext(i->getNext());
	    delete i;
	  }
	}
      }
    }
  } else if (charComparer(command,commands[2])) {
    //print
    for (unsigned i=0;i<SIZE;++i) {
      if (students[i]!=NULL) {
	printr(students[i]);
      }
    }
  } else {
    //quit
    return;
  }
  loop(students,num,SIZE);
}

void printr(LNode<Student*>* student) {
  if (student!=NULL) {
    student->getValue()->display();
    if (student->getNext()!=NULL) {
      printr(student->getNext());
    }
  }
}
