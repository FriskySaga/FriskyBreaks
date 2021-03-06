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
  void setNextPhase();
  void setPausedIcon();
  void setPhaseIcon();
  void setTimer();
  void startTimer();
  void stopTimer();

private slots:
  void toggleTimer();
  void updateCountdown();

private:
  Ui::MainWindow* ui;

  QTime* time;
  QTimer* timer;

  bool isRunning;
  PhaseEnum phase;

  QIcon* pausedIcon;
  QIcon* shortBreakIcon;
  QIcon* longBreakIcon;
  QIcon* workIcon;
};
#endif // MAINWINDOW_HXX

