#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Canvas.h"
#include "Brush.h"
#include "UndoRedoManager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Canvas* canvas;
    Brush* brush;
    UndoRedoManager* undoRedoManager;
};

#endif // MAINWINDOW_H

