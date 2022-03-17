#ifndef STUDENT_H
#define STUDENT_H

class Student {
 public:
  char firstName[80];
  char lastName[80];
  int id;
  float GPA;
  Student(char fName[80],char lName[80],int stid,float stGPA);
  Student(int stid);
  Student();
  ~Student();
  //displays all the student's information
  void display();
};

#endif
