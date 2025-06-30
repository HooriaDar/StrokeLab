#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include "Shape.h"
#include "UndoRedoManager.h"

const int MAX_SHAPES = 1000;  

class Canvas : public QWidget {
    Q_OBJECT

public:
    Canvas(QWidget* parent = nullptr);
    void setCurrentTool(QString tool);
    void setCurrentColor(QColor color);
    void setBrushSize(int size);
    void undo();
    void redo();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    Shape* shapes[MAX_SHAPES];  // Manual storage
    int shapeCount = 0;

    Shape* currentShape = nullptr;
    QString currentTool = "brush";
    QColor currentColor = Qt::black;
    int brushSize = 3;

    UndoRedoManager* historyManager;
};

#endif
