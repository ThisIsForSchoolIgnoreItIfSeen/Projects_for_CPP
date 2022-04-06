/*
things are going on, you alone must decipher, the comments are dark, nonexistent
*/
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include "BNode.h"
using namespace std;

void loop();

int main() {
  
}

void loop() {
  cout << "Would you like to 'P'rint the tree, 'I'nput numbers, 'R'emove numbers, 'C'heck for numbers, or 'Q'uit\n'P', 'I', 'R', 'C', or 'Q':";
  char input;
  cin >> input;
  cin.ignore(80,'\n');
  if (input=='i'||input=='I') {
    cout << "Would you like to input numbers 'M'anually or through a 'F'ile?\n";
    cin >> input;
    if (input=='m'||input=='M') {
      //manual input
      cout << "Enter Number:";
      cin >> heap[adPos];
      int j = adPos + 1;
      while (j>1) {
	if (heap[j-1]>heap[(int)floor(j/2)-1]) {
	  int temp = heap[(int)floor(j/2)-1];
	  heap[(int)floor(j/2)-1] = heap[j-1];
	  heap[j-1] = temp;
	}
	j = (int)floor(j/2);
      }
      adPos++;
    } else if ((input == 'f') || (input == 'F')) {
      //file input
      char fileName[80];
      cout << "Which file? ";
      cin.get(fileName, 80, '\n');
      ifstream reader(fileName);
      while ((adPos < 100) && (reader >> heap[adPos])) {
	int j = adPos + 1;
	while (j>1) {
	  if (heap[j-1]>heap[(int)floor(j/2)-1]) {
	    int temp = heap[(int)floor(j/2)-1];
	    heap[(int)floor(j/2)-1] = heap[j-1];
	    heap[j-1] = temp;
	  }
	  j = (int)floor(j/2);
	}
	adPos++;
      }
    }
  } else {
    //print
    printr(heap, 1);
  }
  loop(head);
}
