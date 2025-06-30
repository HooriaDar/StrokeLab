QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    brush.cpp \
    Canvas.cpp \
    Circle.cpp \
    ColorPicker.cpp \
    Eraser.cpp \
    FreehandStroke.cpp \
    Line.cpp \
    Rectangle.cpp \
    Shape.cpp \
    UndoRedoManager.cpp

HEADERS += \
    mainwindow.h \
    brush.h \
    Canvas.h \
    Circle.h \
    ColorPicker.h \
    Eraser.h \
    FreehandStroke.h \
    Line.h \
    Rectangle.h \
    Shape.h \
    UndoRedoManager.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../Downloads/MainWindow.ui.txt

