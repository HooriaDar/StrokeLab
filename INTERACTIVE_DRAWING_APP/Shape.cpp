#include "Shape.h"
#include <iostream>
using namespace std;

Shape::Shape() : color("black"), thickness(1) {}

Shape::Shape(const QColor& c, int t) : color(c), thickness(t) {}

void Shape::addPoint(const QPoint& point) {
    Q_UNUSED(point);
    cout << "Default addPoint called in Shape. Ignored." << endl;
}

Shape::~Shape() {}
