#include "Rectangle.h"
#include <QPainter>

Rectangle::Rectangle(const QString& color, int thickness) : Shape(color, thickness), startPoint(0, 0), endPoint(0, 0) {}

void Rectangle::draw(QPainter& painter) {
    QPen pen(color);  // Set the color from Shape's member
    pen.setWidth(thickness);  // Set the thickness from Shape's member
    painter.setPen(pen);
    
    // Draw a rectangle between startPoint and endPoint
    QRect rect(startPoint, endPoint);
    painter.drawRect(rect);
}

void Rectangle::addPoint(const QPoint& point) {
    if (startPoint == QPoint(0, 0)) {
        startPoint = point;  // First click, set start point
    } else {
        endPoint = point;  // Second click, set end point and ready to draw
    }
}
