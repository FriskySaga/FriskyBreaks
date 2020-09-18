#include "MainWindow.hxx"

#include <QApplication>
#include <QFile>
#include <QString>

#include <iostream>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  // Use one stylesheet for everything
  QFile styleFile(":/Style.qss");
  styleFile.open(QFile::ReadOnly);
  QString styleSheet(styleFile.readAll());
  app.setStyleSheet(styleSheet);

  MainWindow win;
  win.show();
  return app.exec();
}

