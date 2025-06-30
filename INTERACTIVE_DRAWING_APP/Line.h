#ifndef LINE_H
#define LINE_H

#include "Shape.h"
#include <QPoint>
#include <QPainter>

class Line : public Shape {
private:
    QPoint startPoint;
    QPoint endPoint;

public:
    Line(const QColor& color = Qt::black, int thickness = 1);
    
    // Override the draw method
    void draw(QPainter& painter) override;

    // Capture start and end points of the line
    void addPoint(const QPoint& point) override;
};

#endif
