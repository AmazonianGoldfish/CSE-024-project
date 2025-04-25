#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
class Polygon: public Shape{
    float sides;
    float length;

public:
    Polygon();
    Polygon(float x, float y, int sides, float length, float r,float g, float b);

    void draw();
};

#endif