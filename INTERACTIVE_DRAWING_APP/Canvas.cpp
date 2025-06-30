#include "Canvas.h"
#include <QPainter>
#include <QMouseEvent>
#include "Line.h"
#include "FreehandStroke.h"

Canvas::Canvas(QWidget* parent) : QWidget(parent) {
    setFixedSize(800, 600);
    historyManager = new UndoRedoManager();
}

void Canvas::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    for (Shape* shape : shapes) {
        shape->draw(painter);
    }
    if (currentShape) {
        currentShape->draw(painter);
    }
}

void Canvas::mousePressEvent(QMouseEvent* event) {
    if (currentTool == "brush") {
        currentShape = new FreehandStroke(currentColor, brushSize);
    } else if (currentTool == "eraser") {
        currentShape = new FreehandStroke(Qt::white, brushSize);
    } else if (currentTool == "line") {
        currentShape = new Line(currentColor, brushSize);
    }
    if (currentShape) {
        currentShape->addPoint(event->pos());
    }
}

void Canvas::mouseMoveEvent(QMouseEvent* event) {
    if (currentShape && event->buttons() & Qt::LeftButton) {
        currentShape->addPoint(event->pos());
        update();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent* event) {
    if (currentShape) {
        currentShape->addPoint(event->pos());
        if (shapeCount < MAX_SHAPES) {
            shapes[shapeCount++] = currentShape;
            historyManager->pushShape(currentShape);
        }
        currentShape = nullptr;
        update();
    }
}


void Canvas::setCurrentTool(QString tool) {
    currentTool = tool;
}

void Canvas::setCurrentColor(QColor color) {
    currentColor = color;
}

void Canvas::setBrushSize(int size) {
    brushSize = size;
}

void Canvas::undo() {
    Shape* shape = historyManager->undo();  // Pops from undoStack and pushes to redoStack
    if (shapeCount > 0 && shape != nullptr) {
        --shapeCount;  // Remove shape from canvas
        update();
    }
}

void Canvas::redo() {
    Shape* shape = historyManager->redo();  // Pops from redoStack and pushes to undoStack
    if (shape != nullptr && shapeCount < 1000) {
        shapes[shapeCount++] = shape;       // Add shape back to canvas
        update();
    }
}

