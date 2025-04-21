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
        canvas->addPoint(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER){
        canvas->addPoint(mx, my, 1.0, 1.0, 1.0, 14);
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
        //something
    }
}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my){
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL){
        canvas->addPoint(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER){
        canvas->addPoint(mx, my, 1.0, 1.0, 1.0, 14);
        canvas->undo();
        canvas->redraw();
    }
    else if (tool == MOUSE){
        //something
    }
}

void Application::onToolbarChange(bobcat::Widget* sender){
    ACTION action = toolbar->getAction();

    if (action == CLEAR){
        canvas->clear();
        canvas->redraw();
    }
    else if (action == PLUS){
        //something
    }
    else if (action == MINUS){
        //something
    }
    else if (action == FRONT){
        //something
    }
    else if (action == BACK){
        //something
    }

}

Application::Application() {
    window = new Window(100, 100, 400, 400, "Pain Application");
    toolbar = new Toolbar(0,0,50,350);
    canvas = new Canvas(25,0,375,350);
    colorSelector = new ColorSelector(50,350,350,50);
    colorSelector -> box(FL_BORDER_BOX);

    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);

    window->show();
}