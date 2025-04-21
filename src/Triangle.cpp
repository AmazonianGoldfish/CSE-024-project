#include "Triangle.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

Triangle::Triangle(){
    x = 0.0;
    y = 0.0;
    base = 0.2;
    height = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Triangle::Triangle(float x, float y, float base, float height, float r, float g, float b){
    this -> x = x;
    this -> y = y;
    this -> base = base;
    this -> height = height;
    this -> r = r;
    this -> g = g;
    this -> b = b;
}

void Triangle::draw(){
    glColor3f(r,g,b);

    glBegin(GL_POLYGON);
        glVertex2f(x - base/2, y - height/2);
        glVertex2f(x, y + height/2);
        glVertex2f(x + base/2, y - height/2);
    glEnd();
}