#ifndef FREEHANDSTROKE_H
#define FREEHANDSTROKE_H

#include "Shape.h"
#include <QPoint>
#include <QPainter>

class FreehandStroke : public Shape {
private:
    QPoint path[1000];  // Using a fixed-size array
    int pathSize;  // To keep track of how many points are in the path

public:
    FreehandStroke(const QColor& color = Qt::black, int thickness = 1);
    
    // Override the draw method
    void draw(QPainter& painter) override;

    // Capture points for freehand drawing
    void addPoint(const QPoint& point) override;
};

#endif
