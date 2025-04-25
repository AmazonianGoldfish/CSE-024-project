#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include "Point.h"
#include "Shape.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <vector>

class Scribble : public Shape {
  std::vector<Point *> points;

public:
  Scribble(float startX, float startY, float r, float g, float b);

  void addPoint(float x, float y, float r, float g, float b, int size);

  void draw() override;

  ~Scribble();

  float getX() override;

  float getY() override;
};
#endif