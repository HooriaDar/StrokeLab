#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <QPoint>
#include <QPainter>

class Rectangle : public Shape {
private:
    QPoint startPoint;
    QPoint endPoint;

public:
    Rectangle(const QString& color = "black", int thickness = 1);
    
    // Override the draw method
    void draw(QPainter& painter) override;

    // Capture start and end points of the rectangle
    void addPoint(const QPoint& point) override;
};

#endif
