#ifndef MEDIA_H
#define MEDIA_H

class media {
  //just the media class
public:
  char name[80];
  int year;
  char publisher[80];
  media();
  virtual void disp();
  virtual ~media();
};

#endif
