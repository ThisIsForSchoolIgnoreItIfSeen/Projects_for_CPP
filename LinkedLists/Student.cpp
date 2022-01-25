#include "Student.h"
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

Student::Student(char fName[80],char lName[80],int stid,float stGPA) {
  strcpy(firstName,fName);
  strcpy(lastName,lName);
  id = stid;
  GPA = stGPA;
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
