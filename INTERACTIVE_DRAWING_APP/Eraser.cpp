#include "Eraser.h"
#include "FreehandStroke.h"
#include <QString>
#include <QColor>

Eraser::Eraser(int size) : Brush("white", size) {}  // Eraser is always white by default

FreehandStroke Eraser::createStroke() {
    return FreehandStroke("white", 5);  // Return a white stroke (eraser)
}
