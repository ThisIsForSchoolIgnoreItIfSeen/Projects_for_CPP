#include "media.h"

#ifndef VIDEOGAME_H
#define VIDEOGAME_H
class videoGame: public media {
public:
  float rating;
  videoGame();
  void disp();
  ~videoGame();
};
#endif
