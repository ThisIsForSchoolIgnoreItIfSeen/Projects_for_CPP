#include "media.h"
#include "videoGame.h"
#include <iostream>
using namespace std;

videoGame::videoGame() { cout << "Videogame created\n";}
void videoGame::disp() {
  //videogame implementation of disp function
  cout << "Name: " << name << "\nReleased: " << year << "\nMade by: " << publisher << "\nRated at " << rating << " out of 5 stars\n";
  }
  videoGame::~videoGame() {delete this;}
