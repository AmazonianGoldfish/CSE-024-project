#include "Application.h"
#include "Enums.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/bobcat_ui.h>

using namespace bobcat;
using namespace std;

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my){
    
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL){
        canvas->startScribble(mx, my, color);
        canvas->redraw();
    }
    else if (tool == ERASER){
        canvas->eraseShape(mx, my);
        canvas->redraw();
    }
    else if (tool == RECTANGLE){
        canvas->addRectangle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == CIRCLE){
        canvas->addCircle(mx, my, 0.1,color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == TRIANGLE){
        canvas->addTriangle(mx, my, 0.2,0.2,color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == POLYGON){
        canvas->addPolygon(mx, my, 6,0.1,color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == MOUSE){
        canvas->mouse(mx, my);
        canvas->redraw();
    }
}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my){
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL){
        canvas->updateScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER){
        canvas->eraseShape(mx, my);
        canvas->redraw();
    }
    else if (tool == MOUSE){
        canvas->dragShape(mx, my);
        canvas->redraw();
    }
}

void Application::onCanvasMouseUp(bobcat::Widget* sender, float mx, float my) {
    if (toolbar->getTool() == PENCIL) {
        canvas->endScribble();
        canvas->redraw();
    }
}

void Application::onToolbarChange(bobcat::Widget* sender){
    TOOL tool = toolbar->getTool();
    ACTION action = toolbar->getAction();

    if (tool != MOUSE) {
        canvas->deselectAll();
    }

    if (action == CLEAR){
        canvas->deselectAll();
        canvas->clear();
        canvas->redraw();
    }
    else if (action == PLUS){
        canvas->plus();
        canvas->redraw();
    }
    else if (action == MINUS){
        canvas->minus();
        canvas->redraw();
    }
    else if (action == FRONT){
        canvas->bringToFront();
        canvas->redraw();
    }
    else if (action == BACK){
        canvas->sendToBack();
        canvas->redraw();
    }

}

Application::Application() {
    window = new Window(100, 100, 400, 400, "Paint Application");
    toolbar = new Toolbar(0,0,50,350);
    canvas = new Canvas(25,0,375,350);
    colorSelector = new ColorSelector(50,350,350,50,canvas);
    colorSelector -> box(FL_BORDER_BOX);

    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_MOUSE_UP(canvas, Application::onCanvasMouseUp);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);

    window->show();
}