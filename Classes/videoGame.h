#include "media.h"

#ifndef VIDEOGAME_H
#define VIDEOGAME_H
class videoGame: public media {
public:
  //just constructors for the variables and functions
  float rating;
  videoGame();
  //virtual function to display the media for simplicity
  void disp();
  ~videoGame();
};
#endif
