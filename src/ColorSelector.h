#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include "Canvas.h"
#include "Color.h"
#include "Enums.h"
#include <bobcat_ui/all.h>

class ColorSelector : public bobcat::Group {
  bobcat::Button *redButton;
  bobcat::Button *orangeButton;
  bobcat::Button *yellowButton;
  bobcat::Button *greenButton;
  bobcat::Button *blueButton;
  bobcat::Button *indigoButton;
  bobcat::Button *violetButton;

  Canvas *connectedCanvas;

  COLOR color;
  void deselectAllColors();
  void visualizeSelectedColor();
  void onClick(bobcat::Widget *sender);

public:
  ColorSelector(int x, int y, int w, int h, Canvas *canvas);

  Color getColor() const;
};

#endif