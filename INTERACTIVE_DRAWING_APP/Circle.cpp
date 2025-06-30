#include "Circle.h"
#include <QPainter>

Circle::Circle(const QString& color, int thickness) : Shape(color, thickness), center(0, 0), radius(0) {}

void Circle::draw(QPainter& painter) {
    QPen pen(color);  // Set the color from Shape's member
    pen.setWidth(thickness);  // Set the thickness from Shape's member
    painter.setPen(pen);
    
    // Draw the circle using the center and radius
    painter.drawEllipse(center, radius, radius);
}

void Circle::addPoint(const QPoint& point) {
    if (center == QPoint(0, 0)) {
        center = point;  // First click, set center point
    } else {
        radius = static_cast<int>(QLineF(center, point).length());  // Calculate radius based on distance from center
    }
}
