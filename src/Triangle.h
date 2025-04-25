#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
class Triangle: public Shape{
    float base;
    float height;

public:
    Triangle();
    Triangle(float x, float y, float base, float height, float r, float g, float b);
    
    void draw();


};

#endif