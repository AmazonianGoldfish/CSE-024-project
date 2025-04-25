#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
  float width;
  float height;

public:
  Rectangle();
  Rectangle(float x, float y, float r, float g, float b);
  void draw();
};

#endif