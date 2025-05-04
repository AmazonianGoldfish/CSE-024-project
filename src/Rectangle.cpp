#include "Rectangle.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

Rectangle ::Rectangle() {
  x = 0.0;
  y = 0.0;
  width = 0.2f;
  height = 0.2f;
  r = 0.0;
  g = 0.0;
  b = 0.0;
}

Rectangle ::Rectangle(float x, float y, float r, float g, float b) {
  this->x = x;
  this->y = y;
  width = 0.2f;
  height = 0.2f;
  this->r = r;
  this->g = g;
  this->b = b;
}

void Rectangle::draw() {
  glColor3f(r, g, b);

  glBegin(GL_POLYGON);
  glVertex2f(x - (width / 2) * scale, y + (height / 2) * scale);
  glVertex2f(x + (width / 2) * scale, y + (height / 2) * scale);
  glVertex2f(x + (width / 2) * scale, y - (height / 2) * scale);
  glVertex2f(x - (width / 2) * scale, y - (height / 2) * scale);
  glEnd();
}