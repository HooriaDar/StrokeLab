#include "Line.h"
#include <QPainter>

Line::Line(const QColor& color, int thickness) : Shape(color, thickness), startPoint(0, 0), endPoint(0, 0) {}

void Line::draw(QPainter& painter) {
    QPen pen(color);  // Set the color from Shape's member
    pen.setWidth(thickness);  // Set the thickness from Shape's member
    painter.setPen(pen);
    painter.drawLine(startPoint, endPoint);  // Draw the line between start and end points
}

void Line::addPoint(const QPoint& point) {
    if (startPoint == QPoint(0, 0)) {
        startPoint = point;  // First click, set start point
    } else {
        endPoint = point;  // Second click, set end point and ready to draw
    }
}
