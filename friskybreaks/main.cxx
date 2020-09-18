#include "MainWindow.hxx"

#include <QApplication>
#include <QFile>
#include <QString>

int main(int argc, char *argv[])
{ 
  QApplication app(argc, argv);
  app.setApplicationName("FriskyBreaks");

  // Use one stylesheet for everything
  QFile styleFile(":/Style.qss");
  styleFile.open(QFile::ReadOnly);
  QString styleSheet(styleFile.readAll());
  app.setStyleSheet(styleSheet);

  MainWindow win;
  win.show();
  return app.exec();
}

