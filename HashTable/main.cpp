//hash table
/*
This Program compiles a list of students and and their information, it also allows the user to access the information and edit the list in a small amount of ways, excess functionality may be added as nessecary
*/
//Author: Kabir Vidyarthi
//Date: 1/31/21
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool charComparer(char *f, char *s);
void loop(Student* students[100]);

int main() {
  Student* students[100];
  //code loop
  loop(students);
  
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

void loop(Student* students) {
  char command[10] = "print";
  char commands[3][10] = {"add","delete","print"};
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
    students.push_back(new Student());
  } else if (charComparer(command,commands[1])) {
    //deletes
    int id;
    cout << "Which student would you like to remove\nID:";
    cin >> id;
    cin.ignore(80,'\n');
      //for loop to get rid of the right student
      for (auto i=students.begin();i!=students.end();++i)
	if ((*i)->id==id) {
	  char confirm;
	  cout << "Are you sure you want to remove " << (*i)->firstName << ' ' << (*i)->lastName << "?\n'y' or 'n':";
	  cin >> confirm;
	  cin.ignore(80,'\n');
	  if (confirm =='y')
	    students.erase(i--);
	}
    } else if (charComparer(command,commands[2])) {
    //print
    for (unsigned i=0;i<students.size();++i) {
      students[i]->display();
    }
    } else {
      quit=true;
      break;
    }
  }
}
