#include "FreehandStroke.h"
#include <QPainter>

FreehandStroke::FreehandStroke(const QColor& color, int thickness)
    : Shape(color, thickness), pathSize(0) {}


void FreehandStroke::draw(QPainter& painter) {
    QPen pen(color);
    pen.setWidth(thickness);
    painter.setPen(pen);
    
    // Draw lines between consecutive points in path
    for (int i = 0; i < pathSize - 1; ++i) {
        painter.drawLine(path[i], path[i + 1]);
    }
}

void FreehandStroke::addPoint(const QPoint& point) {
    if (pathSize < 1000) {
        path[pathSize++] = point;  // Store the point and increment pathSize
    }
}
