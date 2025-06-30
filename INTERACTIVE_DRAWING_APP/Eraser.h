#ifndef ERASER_H
#define ERASER_H

#include "Brush.h"
#include <QString>

class Eraser : public Brush {
public:
    Eraser(int size = 5);  // Default eraser size

    // Override to return a FreehandStroke with background color (e.g., Qt::white)
    FreehandStroke createStroke() override;
};

#endif
