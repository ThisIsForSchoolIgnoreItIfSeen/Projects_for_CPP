#include "media.h"
#include <iostream>
using namespace std;

media::media() { cout << "Media Created\n"; }
void media::disp() {
  //disp virtual function so that I have a universal thing
  cout << "Name: " << name << "\nRelease: " << year << "\nMade by: " << publisher;
}
media::~media() { delete this;}
