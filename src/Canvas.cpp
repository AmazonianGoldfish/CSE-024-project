#include "Canvas.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Scribble.h"
#include <GL/freeglut.h>
#include <cstdlib>
#include "Enums.h"
#include "Triangle.h"

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x,y,w,h){
    curr = nullptr;
}

void Canvas::addPoint(float x, float y, float r, float g, float b, int size){
    shapes.push_back(new Point(x,y,r,g,b,size));
}

void Canvas::addRectangle(float x, float y,  float r, float g, float b){
    shapes.push_back(new Rectangle(x,y,r,g,b));
}

void Canvas::addCircle(float x, float y, float radius,float r,float g, float b){
    shapes.push_back(new Circle(x,y,radius,r,g,b));
}

void Canvas::addTriangle(float x, float y, float base, float height, float r, float g, float b){
    shapes.push_back(new Triangle(x,y,base,height,r,g,b));
}

void Canvas::addPolygon(float x, float y, int sides, float length, float r, float g, float b){
    shapes.push_back(new Polygon(x,y,sides,length,r,g,b));
}

void Canvas::clear(){
    for (unsigned int i = 0; i < shapes.size(); i++){
        delete shapes[i];
    }
    shapes.clear();
    for (unsigned int i = 0; i < points.size(); i ++){
        delete points[i];
    }
    points.clear();
}

void Canvas::mouse(){
    //something
}

void Canvas::plus(){
    for (unsigned int i = 0; i < points.size(); i++){
        points[i]++;
    }
}

void Canvas::minus(){
    for (unsigned int i = 0; i < points.size(); i++){
        points[i]--;
    }
}

void Canvas::bringToFront(){
    //something
}

void Canvas::sendToBack(){
    //something
}

void Canvas::undo(){
    for (unsigned int i; i < shapes.size(); i++){
        shapes.pop_back();
    }
}


void Canvas::render(){
    for(unsigned int i = 0; i < shapes.size(); i++ ){
        shapes[i]->draw();
    }

    if(curr){
        curr->draw();
    }
}
void Canvas::startScribble(){

}

void Canvas::updateScribble(float x, float y, float r, float g, float b, int size){
    
}

void Canvas::endScribble(){
    if(curr){
        shapes.push_back(curr);
        curr = nullptr;
    }
}