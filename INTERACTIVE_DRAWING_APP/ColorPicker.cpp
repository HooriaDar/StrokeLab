#include "ColorPicker.h"

QColor ColorPicker::selectColor(QWidget* parent) {
    QColor color = QColorDialog::getColor(Qt::black, parent, "Select Color");
    return color;
}
