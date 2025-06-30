#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QColor>
#include <QWidget>
#include <QColorDialog>

class ColorPicker {
public:
    static QColor selectColor(QWidget* parent = nullptr);
};

#endif
