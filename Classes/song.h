#include "media.h"

#ifndef SONG_H
#define SONG_H
//just the song class
class song: public media {
public:
  //constructors for variables
  char artist[80];
  float length;
  song();
  //virtual function to simplify display of the various medias
  void disp();
  ~song();
};
#endif
