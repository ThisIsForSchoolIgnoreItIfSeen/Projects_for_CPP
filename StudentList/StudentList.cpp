//Student List
/*
This Program compiles a list of students and and their information, it also allows the user to access the information and edit the list in a small amount of ways, excess functionality may be added as nessecary
*/
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

  Student() {
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
    cin.ignore(80,'\n');
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
  vector<Student*> ease;
  //code loop
  bool quit = false;
  char command[10] = "print";
  char commands[3][10] = {"add","delete","print"};
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
      //adds
      ease.push_back(new Student());
    } else if (charComparer(command,commands[1])) {
      int id;
      cout << "Which student would you like to remove\nID:";
      cin >> id;
      cin.ignore(80,'\n');
      //for loop to get rid of the right student
      for (auto i=ease.begin();i!=ease.end();++i)
	if ((*i)->id==id)
	  ease.erase(i);
    } else if (charComparer(command,commands[2])) {
      for (unsigned i=0;i<ease.size();++i) {
	ease[i]->display();
      }
    } else {
      quit=true;
      break;
    }
  }
  
  return(0);
}
