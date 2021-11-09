#ifndef MEDIA_H
#define MEDIA_H

class media {
  //just the media class
public:
  //list of variables used in media class
  char name[80];
  int year;
  char publisher[80];
  //constructor destructor and a small function allowing me to display the various media
  media();
  virtual void disp();
  virtual ~media();
};

#endif
