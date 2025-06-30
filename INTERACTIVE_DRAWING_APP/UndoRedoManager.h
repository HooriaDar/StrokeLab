#ifndef UNDOREDOMANAGER_H
#define UNDOREDOMANAGER_H

#include "Shape.h"
#include <QList>

class UndoRedoManager {
private:
    Shape* undoStack[100];  // Fixed-size stack for undo (100 shapes max)
    Shape* redoStack[100];  // Fixed-size stack for redo (100 shapes max)
    int undoTop;  // Keeps track of the top of undo stack
    int redoTop;  // Keeps track of the top of redo stack

public:
    UndoRedoManager();

    void pushShape(Shape* shape);
    Shape* undo();
    Shape* redo();
};

#endif
