#ifndef BRUSH_H
#define BRUSH_H

#include "FreehandStroke.h"
#include <QColor>

class Brush {
private:
    QColor color;
    int size;

public:
    Brush(const QColor& color = "black", int size = 5);

    // Creates a new FreehandStroke with the brush properties
    virtual FreehandStroke createStroke();
};

#endif // BRUSH_H
