#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include <QMainWindow>
#include <QTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

  void startTimer();
  void stopTimer();
private:
  void updateCountdown();

  Ui::MainWindow* ui;
  QTime* time;
  QTimer* timer;
};
#endif // MAINWINDOW_HXX
