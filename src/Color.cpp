#include "Color.h"

Color:: Color(){
    r = 0.0;
    g = 0.0;
    b = 0.0;
}
Color::Color(float r, float g, float b){
    this -> r = r;
    this -> g = g;
    this -> b = b;    
}

float Color::getR() const{
    return r;
}

float Color::getG() const{
    return g;
}

float Color::getB() const{
    return b;
}