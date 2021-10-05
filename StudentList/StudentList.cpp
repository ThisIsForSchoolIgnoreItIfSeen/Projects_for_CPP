//Student List
//Author: Kabir Vidyarthi
//Date: 10/1/21
#include <iostream>
#include <vector>
using namespace std;


struct Student {
  char firstName[80];
  char lastName[80];
  int id;
  float GPA;

  Student(char F[],char L[],int I,float G) {
    //first name loop
    int i=0;
    while (*F) {
      firstName[i]=*F;
      i++;
      F++;
    }
    i=0;
    while (*L) {
      lastName[i]=*L;
      i++;
      L++;
    }
    id = I;
    GPA = G;
  }

  void display() {
    cout << "Name: " << firstName << " " << lastName << "\nStudent ID: " << id << "\nWeighted GPA:" << GPA << "\nUnweighted GPA: ~" << GPA*0.987 << '\n';
  }
};

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
int main() {
  vector<Student> ease;
  //code loop
  bool quit = false;
  char command[10] = "print";
  char commands[3][10] = {"add","delete","print"};
  //temp student values
  char first[80];
  char last[80];
  int id;
  float GPA;
  while (!quit) {
    //get command
    cout << "Would you like to 'ADD', 'DELETE', 'PRINT', or 'QUIT'?\n";
    cin.get(command,10,'\n');
    cin.ignore(80,'\n');
    //puts command in lowercase to prevent errors
    for (int i=0;i<10;i++) {
      if (command[i]==0||command[i]==10)
	break;
      command[i] = tolower(command[i]);
    }
    if (charComparer(command,commands[0])) {
      cout << "First name:\n";
      cin.get(first,80,'\n');
      cin.ignore(80,'\n');
      cout << "Last name:\n";
      cin.get(last,80,'\n');
      cin.ignore(80,'\n');
      cout << "ID:\n";
      cin >> id;
      cout << "GPA:\n";
      cin >> GPA;
      cin.ignore(80,'\n');
      ease.push_back(Student(first,last,id,GPA));
    } else if (charComparer(command,commands[1])) {
      cout << "Which student would you like to remove\nID:";
      cin >> id;
      cin.ignore(80,'\n');
      //for loop to get rid of the right student
      for (int i=0;i<ease.size();++i)
	if (ease[i].id==id)
	  ease.erase(ease.begin()+i);
    } else if (charComparer(command,commands[2])) {
      for (unsigned i=0;i<ease.size();++i) {
	ease[i].display();
      }
    } else {
      quit=true;
      break;
    }
  }
  
  return(0);
}
