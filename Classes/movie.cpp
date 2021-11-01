#include "media.h"
#include "movie.h"
#include <iostream>
using namespace std;

movie::movie() { cout << "Movie Created\n";}
void movie::disp() {
  //just the display function implementation for movie
  cout << "Name: " << name << "\nDirected by: " << publisher << "\nMade in: " << year << "\nLasts: " << duration << " units of time\nRated " << rating << " out of 5 stars\n";
}
movie::~movie() {delete this;}
