#include "Point.h"
#include <GL/freeglut.h>

Point::Point() {
  x = 0.0;
  y = 0.0;
  r = 0.0;
  g = 0.0;
  b = 0.0;
  size = 7;
}

Point::Point(float x, float y) : Point() {
  this->x = x;
  this->y = y;
}

Point::Point(float x, float y, float r, float g, float b) : Point(x, y) {
  this->r = r;
  this->g = g;
  this->b = b;
}

Point::Point(float x, float y, float r, float g, float b, int size)
    : Point(x, y, r, g, b) {
  this->size = size;
}

void Point::draw() {
  glColor3f(r, g, b);
  glPointSize(size);

  glBegin(GL_POINTS);
  glVertex2f(x, y);
  glEnd();
}

float Point::getX() const { return x; }

float Point::getY() const { return y; }

float Point::getR() const { return r; }

float Point::getG() const { return g; }

float Point::getB() const { return b; }

int Point::getSize() const { return size; }