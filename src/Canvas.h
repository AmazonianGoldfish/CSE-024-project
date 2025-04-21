#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <vector>
#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Shape.h"
#include "Scribble.h"
#include "Enums.h"

class Canvas : public bobcat::Canvas_{
    std::vector <Shape*> shapes;
    std::vector <Point*> points;
    std::vector <TOOL> shape;

    Scribble* curr;

public:
    Canvas (int x, int y, int w, int h);

    void addPoint(float x, float y, float r, float g, float b, int size);

    void addRectangle(float x, float y, float r, float g, float b);

    void addCircle (float x, float y, float radius,float r, float g, float b);

    void addTriangle(float x, float y, float base, float height, float r, float g, float b);

    void addPolygon(float x, float y, int sides, float length, float r, float g, float b);

    void undo();

    void clear();

    void mouse();

    void plus();
    
    void minus();

    void bringToFront();

    void sendToBack();

    void startScribble();

    void updateScribble(float x, float y, float r, float g,  float b, int size);

    void endScribble();

    void render();
};

#endif


