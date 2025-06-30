#include "brush.h"
#include "FreehandStroke.h"

Brush::Brush(const QColor& color, int size) : color(color), size(size) {}

FreehandStroke Brush::createStroke() {
    return FreehandStroke(color, size);  // Return a FreehandStroke object with current color and size
}
