#include "Canvas.h"
#include "Circle.h"
#include "Enums.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Scribble.h"
#include "Triangle.h"
#include <GL/freeglut.h>
#include <bobcat_ui/image.h>
#include <cstdlib>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
  currentScribble = nullptr;

  selected = -1;
}

void Canvas::addPoint(float x, float y, float r, float g, float b, int size) {
  shapes.push_back(new Point(x, y, r, g, b, size));
}

void Canvas::addRectangle(float x, float y, float r, float g, float b) {
  shapes.push_back(new Rectangle(x, y, r, g, b));
}

void Canvas::addCircle(float x, float y, float radius, float r, float g, float b) {
  shapes.push_back(new Circle(x, y, radius, r, g, b));
}

void Canvas::addTriangle(float x, float y, float base, float height, float r, float g, float b) {
  shapes.push_back(new Triangle(x, y, base, height, r, g, b));
}

void Canvas::addPolygon(float x, float y, int sides, float length, float r, float g, float b) {
  shapes.push_back(new Polygon(x, y, sides, length, r, g, b));
}

void Canvas::clear() {
  for (unsigned int i = 0; i < shapes.size(); i++) {
    delete shapes[i];
  }
  shapes.clear();

  for (unsigned int i = 0; i < points.size(); i++) {
    delete points[i];
  }

  points.clear();
}

void Canvas::mouse(float mouseX, float mouseY) {
    Shape *shape;

    float nearestDistance = 1000.0f;

    for (unsigned int i = 0; i < shapes.size(); i++) {
        shape = shapes[i];

        float distance = sqrt(pow(mouseX - shape->getX(), 2) + pow(mouseY - shape->getY(), 2));

        if (distance < nearestDistance)
        {
            selected = i;

            nearestDistance = distance;
        }
    }

    // std::cout << "Selected: " << selected << " (Distance: " << bobcat::roundFloat(nearestDistance) << ")" << std::endl;
}

void Canvas::plus() {
    if (selected > -1) {
        shapes[selected]->changeScale(0.1f);
    }
}

void Canvas::minus() {
    if (selected > -1) {
        shapes[selected]->changeScale(-0.1f);
    }
}

void Canvas::bringToFront() {
    if (selected > -1 && selected < shapes.size()) {
        Shape* shape = shapes[selected];
        shapes.erase(shapes.begin() + selected);
        shapes.push_back(shape);
        selected = shapes.size() - 1;
    }
}

void Canvas::sendToBack() {
  if (selected > -1 && selected < shapes.size()) {
    Shape* shape = shapes[selected];
        shapes.erase(shapes.begin() + selected);
        shapes.insert(shapes.begin(), shape);
        selected = 0;
  }
}

void Canvas::undo() {
  for (unsigned int i; i < shapes.size(); i++) {
    shapes.pop_back();
  }
}

void Canvas::render() {
  for (unsigned int i = 0; i < shapes.size(); i++) {
    shapes[i]->draw();
  }

  if (currentScribble) {
    currentScribble->draw();
  }
}

void Canvas::startScribble(float startX, float startY, Color color) { currentScribble = new Scribble(startX, startY, color.getR(), color.getG(), color.getB()); }

void Canvas::updateScribble(float x, float y, float r, float g, float b, int size) {
  currentScribble->addPoint(x, y, r, g, b, size);
}

void Canvas::endScribble() {
  if (currentScribble != nullptr) {
    shapes.push_back(currentScribble);

    currentScribble = nullptr;
  }
}

int Canvas::getSelected() {
    return selected;
}

void Canvas::dragShape(float mouseX, float mouseY) {
    if (selected > -1) {
        shapes[selected]->setX(mouseX);
        shapes[selected]->setY(mouseY);
    }
}

void Canvas::eraseShape(float mouseX, float mouseY) {
    Shape *shape = nullptr;

    float nearestDistance = 1000.0f;
    float maxDistance = 0.2f;

    int target = -1;

    for (unsigned int i = 0; i < shapes.size(); i++) {
        shape = shapes[i];

        float distance = sqrt(pow(mouseX - shape->getX(), 2) + pow(mouseY - shape->getY(), 2));

        if (distance < nearestDistance && distance < maxDistance)
        {
            target = i;

            nearestDistance = distance;
        }
    }

    if (target > -1) {
        shapes.erase(shapes.begin() + target);
    }
}

void Canvas::recolorShape(Color color) {
    if (selected > -1) {
        shapes[selected]->setColor(color);

        redraw();
    }
}

void Canvas::deselectAll() {
    selected = -1;
}