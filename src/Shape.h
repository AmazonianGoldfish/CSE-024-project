#ifndef SHAPE_H
#define SHAPE_H

#include "Color.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <algorithm>
#include <iostream>

class Shape {
protected:
  float x;
  float y;
  float r;
  float g;
  float b;
  float scale = 1.0f;

public:
  virtual void draw() = 0;

  virtual ~Shape() {}

  virtual float getX() { return x; }

  virtual float getY() { return y; }

  void setX(float value) { x = value; }

  void setY(float value) { y = value; }

  void changeScale(float amount) { scale += amount; }

  void setColor(Color color) {
    r = color.getR();
    g = color.getG();
    b = color.getB();
  }
};

#endif