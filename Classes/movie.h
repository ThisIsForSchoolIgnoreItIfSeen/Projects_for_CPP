#include "media.h"

#ifndef MOVIE_H
#define MOVIE_H
//movie subclass
class movie: public media {
public:
  //constructor for variables
  float duration;
  float rating;
  movie();
  //vitual function to make display easy
  void disp();
  ~movie();
};
#endif
