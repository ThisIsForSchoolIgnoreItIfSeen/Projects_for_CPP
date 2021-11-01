#include "media.h"
#include "song.h"
#include <iostream>
using namespace std;

song::song() { cout << "Song Created\n"; }
void song::disp() {
  //implementation of disp for song
  cout << "Name: " << name << "\nPlayed by: " << artist << "\nPublished by: " << publisher << "\nPublished in: " << year << "\nDura\
tion: " << length << " units of time\n";
}
song::~song() {delete this;}
