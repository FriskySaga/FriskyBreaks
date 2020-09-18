#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include "PhaseEnum.hxx"

#include <QMainWindow>

class QIcon;
class QTime;
class QTimer;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private:
  void setPhase(PhaseEnum phase);
  void startTimer();
  void stopTimer();
  void updateCountdown();

  Ui::MainWindow* ui;
  QTime* time;
  QTimer* timer;

  PhaseEnum phase;
  QIcon* pausedIcon;
  QIcon* shortBreakIcon;
  QIcon* longBreakIcon;
  QIcon* workingIcon;
};
#endif // MAINWINDOW_HXX

