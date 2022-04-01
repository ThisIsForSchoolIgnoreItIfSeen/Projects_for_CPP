/*
sorts numbers into a heap, largest on top
Author: Kabir Vidyarthi
Date: 1/22
*/

#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
using namespace std;

void inputLoop(int heap[100], int adPos);
void printr(int heap[100], int pos);
void treePruner(int heap[100], int headPos);


int main() {
  int heap[100];
  for (int i = 0; i < 100; i++)
    heap[i] = 0;
  //enter nums manual or file
  inputLoop(heap, 0);
  cout << "Tree Format Print\n";
  printr(heap,1);
  cout << "Print in order\n";
  while (heap[0] != 0) {
    cout << heap[0] << ", ";
    for (int i = 0; i < 100; i++) {
      if (heap[i]==0) {
	heap[0] = heap[i-1];
	heap[i-1] = 0;
	i=101;
      } else if (i == 99) {
	heap[0] = heap[99];
	heap[99] = 0;
      }
    }
    treePruner(heap,1);
    //printr(heap, 1);
  }
  return 0;
}

void inputLoop(int heap[100], int adPos) {
  cout << "Would you like to 'P'rint the tree or input numbers 'M'anually or through a 'F'ile\n'P', 'M', or 'F':";
  char inputMethod;
  cin >> inputMethod;
  cin.ignore(80,'\n');
  if (inputMethod=='m'||inputMethod=='M') {
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
  } else if ((inputMethod == 'f') || (inputMethod == 'F')) {
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
  } else {
    //print
    printr(heap, 1);
  }

  //add more or leave
  cout << "Would you like to continue inputting numbers?\n'y' or 'n': ";
  cin >> inputMethod;
  cin.ignore(80,'\n');
  if ((inputMethod=='y'||inputMethod=='Y')&&(adPos<100)) {
    inputLoop(heap,adPos);
  }
}

void printr(int heap[100], int pos) {
  //print left
  if ((pos * 2 <= 100) && (heap[pos * 2 - 1] != 0)) {
    printr(heap, pos * 2);
  }
  //print this
  int numSpaces = (int)floor(log(pos)/log(2));
  for (int i = 0; i < numSpaces; i++) {
    cout << "          ";
  }
  cout << heap[pos-1] << '\n';
  //print right
  if ((pos * 2 + 1 <= 100) && (heap[pos * 2] != 0)) {
    printr(heap, pos * 2 + 1);
  }
}

void treePruner(int heap[100], int headPos) {
  //fixes tree to be top-heavy again
  int temp = heap[headPos-1];
  //left or right bigger
  if (headPos*2<=100) {
    //left child exists
    if ((headPos*2<100) && (heap[headPos*2]>heap[headPos*2-1])) {
      //right child exists and is larger than left child
      if (heap[headPos*2]>temp) {
	//right child is larger than head
	heap[headPos-1] = heap[headPos*2];
	heap[headPos*2] = temp;
	//fix child tree
	treePruner(heap,headPos*2+1);
      }
    } else {
      //no right child or left is bigger
      if (heap[headPos*2-1] > temp) {
	//left child is bigger than head
	heap[headPos-1] = heap[headPos*2-1];
	heap[headPos*2-1] = temp;
	//fix child tree
	treePruner(heap,headPos*2);
      }
    }
  }
}
