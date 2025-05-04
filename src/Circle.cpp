#include "Circle.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cmath>
#include <iostream>

Circle::Circle() {
  x = 0.0;
  y = 0.0;
  radius = 0.1f;
  r = 0.0;
  g = 0.0;
  b = 0.0;
}

Circle::Circle(float x, float y, float radius, float r, float g, float b) {
  this->x = x;
  this->y = y;
  this->radius = 0.1f;
  this->r = r;
  this->g = g;
  this->b = b;
}

void Circle ::draw() {
  glColor3f(r, g, b);

  float inc = M_PI / 32.0;
  glBegin(GL_POLYGON);
  for (float theta = 0; theta <= 2 * M_PI; theta += inc) {
    glVertex2d(x + cos(theta) * scale * radius, y + sin(theta) * scale * radius);
  }
  glEnd();
}