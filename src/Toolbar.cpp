#include "Toolbar.h"
#include "Enums.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/bobcat_ui.h>
using namespace bobcat;

void Toolbar::deselectAllTools(){
    pencilButton->color(FL_BACKGROUND_COLOR);
    eraserButton->color(FL_BACKGROUND_COLOR);
    circleButton->color(FL_BACKGROUND_COLOR);
    triangleButton->color(FL_BACKGROUND_COLOR);
    rectangleButton->color(FL_BACKGROUND_COLOR);
    polygonButton->color(FL_BACKGROUND_COLOR);
    mouseButton->color(FL_BACKGROUND_COLOR);
    paintBrushButton -> color (FL_BACKGROUND_COLOR);
    plusButton->color(FL_BACKGROUND_COLOR);
    minusButton->color(FL_BACKGROUND_COLOR);
    bringToFrontButton->color(FL_BACKGROUND_COLOR);
    sendToBackButton->color(FL_BACKGROUND_COLOR);
}

void Toolbar::visualizeSelectedTool(){
    if (tool == PENCIL){
        pencilButton -> color(FL_WHITE);
    }
    //else if (tool == BRUSH){ paintBrushButton -> color (FL_WHITE); }
    else if (tool == ERASER){
        eraserButton-> color(FL_WHITE);
    }
    else if (tool == CIRCLE){
        circleButton-> color(FL_WHITE);
    }
    else if (tool == TRIANGLE){
        triangleButton-> color(FL_WHITE);
    }
    else if (tool == RECTANGLE){
        rectangleButton-> color(FL_WHITE);
    }
    else if (tool == POLYGON){
        polygonButton-> color(FL_WHITE);
    }
}

void Toolbar::onClick(bobcat::Widget* sender){
    deselectAllTools();

    action = NONE;

    if (sender == pencilButton){
        tool = PENCIL;
    }
    //else if (sender == paintBrushButton){ tool = BRUSH; }
    else if (sender == eraserButton){
        tool = ERASER;
    }
    else if (sender == circleButton){
        tool = CIRCLE;
    }
    else if (sender == triangleButton){
        tool = TRIANGLE;
    }
    else if (sender == rectangleButton){
        tool = RECTANGLE;
    }
    else if (sender == polygonButton){
        tool = POLYGON;
    }
    else if (sender == mouseButton){
        tool = MOUSE;
    }
    else if (sender == clearButton){
        action = CLEAR;
    }
    else if (sender == plusButton){
        action = PLUS;
    }
    else if (sender == minusButton){
        action = MINUS;
    }
    else if (sender == bringToFrontButton){
        action = FRONT;
    }
    else if (sender == sendToBackButton){
        action = BACK;
    }
    
    
    if (onChangeCb){
        onChangeCb(this);
    }

    visualizeSelectedTool();
    redraw();

}

TOOL Toolbar::getTool() const{
    return tool;
}

ACTION Toolbar::getAction() const{
    return action;
}

Toolbar::Toolbar(int x, int y, int w, int h) : Group(x,y,w,h){
    pencilButton = new Image(x,y,25,25,"./assets/pencil.png");      
    // I think the pencil can be considered the paint brush tool
    // paintBrushButton = new Image (x,y + 525, 25 ,25 "./assets/paint-brush.png")
    eraserButton = new Image(x,y + 30, 25,25,"./assets/eraser.png");
    circleButton = new Image(x, y+60, 25,25, "./assets/circle.png");
    triangleButton = new Image(x, y+90, 25,25, "./assets/triangle.png");
    rectangleButton = new Image(x, y+120,25,25, "./assets/rectangle.png");
    polygonButton = new Image(x, y + 150,25,25, "./assets/polygon.png");
    mouseButton = new Image(x, y+180,25,25, "./assets/mouse.png");
    clearButton = new Image (x, y+210,25,25, "./assets/clear.png");
    plusButton = new Image (x, y+240,25,25, "./assets/plus.png");
    minusButton = new Image (x, y+270,25,25, "./assets/minus.png");
    bringToFrontButton = new Image (x, y+300,25,25, "./assets/bring-to-front.png");
    sendToBackButton = new Image (x, y+330,25,25, "./assets/send-to-back.png");


    tool = PENCIL;
    action = NONE;

    pencilButton -> box(FL_BORDER_BOX);
    eraserButton -> box(FL_BORDER_BOX);
    circleButton -> box(FL_BORDER_BOX);
    triangleButton -> box(FL_BORDER_BOX);
    rectangleButton -> box(FL_BORDER_BOX);
    polygonButton -> box(FL_BORDER_BOX);
    mouseButton -> box(FL_BORDER_BOX);
    clearButton -> box(FL_BORDER_BOX);
    plusButton -> box(FL_BORDER_BOX);
    minusButton -> box(FL_BORDER_BOX);
    bringToFrontButton -> box(FL_BORDER_BOX);
    sendToBackButton -> box(FL_BORDER_BOX);

    visualizeSelectedTool();
    
    ON_CLICK(pencilButton,Toolbar::onClick);        
    ON_CLICK(eraserButton,Toolbar::onClick);    
    ON_CLICK(circleButton,Toolbar::onClick);    
    ON_CLICK(triangleButton,Toolbar::onClick);    
    ON_CLICK(rectangleButton,Toolbar::onClick); 
    ON_CLICK(polygonButton, Toolbar::onClick);   
    ON_CLICK(mouseButton,Toolbar::onClick);    
    ON_CLICK(clearButton,Toolbar::onClick);    
    ON_CLICK(plusButton, Toolbar::onClick);
    ON_CLICK(minusButton, Toolbar::onClick);
    ON_CLICK(bringToFrontButton, Toolbar::onClick);
    ON_CLICK(sendToBackButton, Toolbar::onClick);
}