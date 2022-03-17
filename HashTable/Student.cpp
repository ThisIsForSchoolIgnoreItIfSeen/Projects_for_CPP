#include "Student.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <time.h>
using namespace std;

Student::Student(char fName[80],char lName[80],int stid,float stGPA) {
  strcpy(firstName,fName);
  strcpy(lastName,lName);
  id = stid;
  GPA = stGPA;
}

Student::Student(int stid) {
  id = stid;
  ifstream fReader ("First_Names.txt");
  int nameIndex = 0;
  int whichName = rand() % 326;
  while (fReader && nameIndex < whichName) {
    strcat(firstName,"");
    fReader.getline(firstName,80,',');
    nameIndex++;
  }
  ifstream lReader ("Last_Names.txt");
  nameIndex = 0;
  whichName = rand() % 26;
  while (lReader && nameIndex < whichName) {
    strcat(lastName,"");
    lReader.getline(lastName,80,',');
    nameIndex++;
  }
  GPA = (rand() % 400);
  GPA = GPA/100;
}

Student::Student() {
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

Student::~Student() {
  cout << "File for: " << firstName << ' ' << lastName << " Has been removed\n";
}

void Student::display() {
  cout << "Name: " << firstName << " " << lastName << "\nStudent ID: " << id << "\nWeighted GPA:" << GPA << "\nUnweighted GPA: ~" << round(GPA*100*0.987)/100 << '\n';
}
