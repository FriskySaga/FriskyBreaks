#include "MainWindow.hxx"

#include <QApplication>
#include <QPainter>

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow win;
    win.show();
    return app.exec();
}

