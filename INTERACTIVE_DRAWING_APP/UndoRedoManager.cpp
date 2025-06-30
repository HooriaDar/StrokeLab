#include "UndoRedoManager.h"
#include <iostream>

UndoRedoManager::UndoRedoManager() : undoTop(-1), redoTop(-1) {}

void UndoRedoManager::pushShape(Shape* shape) {
    if (undoTop < 99) {
        undoStack[++undoTop] = shape;  // Push the shape onto undo stack
    } else {
        std::cout << "Undo stack is full!" << std::endl;
    }
}

Shape* UndoRedoManager::undo() {
    if (undoTop >= 0) {
        Shape* shape = undoStack[undoTop--];  // Pop from undo stack
        if (redoTop < 99) {
            redoStack[++redoTop] = shape;  // Push onto redo stack
        }
        return shape;
    }
    return nullptr;  // No more items to undo
}

Shape* UndoRedoManager::redo() {
    if (redoTop >= 0) {
        Shape* shape = redoStack[redoTop--];  // Pop from redo stack
        if (undoTop < 99) {
            undoStack[++undoTop] = shape;  // Push back onto undo stack
        }
        return shape;
    }
    return nullptr;  // No more items to redo
}
