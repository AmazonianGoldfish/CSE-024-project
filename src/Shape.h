#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>
#include <GL/gl.h>

class Shape{

public:
    virtual void draw() = 0;

    virtual ~Shape(){}

};

#endif