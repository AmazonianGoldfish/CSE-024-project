#include "Scribble.h"

Scribble::Scribble(float startX, float startY, float r, float g, float b) {
  x = startX;
  y = startY;
  this->r = r;
  this->g = g;
  this->b = b;
}

void Scribble::addPoint(float x, float y, float r, float g, float b, int size) {
  points.push_back(new Point(x - this->x, y - this->y, r, g, b, size));
}

void Scribble::draw() {
  //   for (unsigned int i = 0; i < points.size(); i++) {
  //     points[i]->draw();
  //   }

  glColor3f(r, g, b);

  glLineWidth(scale * 4.0f);

  glBegin(GL_POINTS);
  for (unsigned int i = 1; i < points.size(); i++) {
    glVertex2f(this->x + points[i]->getX() * scale, this->y + points[i]->getY() * scale);
  }
  glEnd();
}

Scribble::~Scribble() {
  for (unsigned int i = 0; i < points.size(); i++) {
    delete points[i];
  }
  points.clear();
}

float Scribble::getX() {
  float sum = 0.0f;

  for (unsigned int i = 1; i < points.size(); i++) {
    sum += this->x + points[i]->getX();
  }

  return sum / (float) points.size();
}

float Scribble::getY() {
  float sum = 0.0f;

  for (unsigned int i = 1; i < points.size(); i++) {
    sum += this->y + points[i]->getY();
  }

  return sum / (float) points.size();
}