#ifndef SHAPE_H
#define SHAPE_H

#include <QColor>
#include <QPainter>
#include <QPoint>
#include <iostream>
using namespace std;

class Shape{
    protected:
    QColor color;
    int thickness;

    public:
    Shape();

    Shape(const QColor& c, int t);

    virtual void draw(QPainter& painter) = 0;

    virtual void addPoint(const QPoint& point);

    virtual ~Shape();
};




#endif
