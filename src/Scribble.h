#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include "Shape.h"
#include "Point.h"
#include <vector>

class Scribble : public Shape{
    std::vector <Point*> points;

public:

    void addPoint(float x, float y, float r, float g, float b, int size);

    void draw();

    ~Scribble();

};
#endif