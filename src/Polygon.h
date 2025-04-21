#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
class Polygon: public Shape{
    float x; 
    float y;
    float sides;
    float length;
    float r;
    float g; 
    float b;

public:

    Polygon();
    Polygon(float x, float y, int sides, float length, float r,float g, float b);

    void draw();



};

#endif