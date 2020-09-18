#include "MainWindow.hxx"
#include "ui_MainWindow.h"

#include <QIcon>
#include <QTime>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent),
    ui(new Ui::MainWindow),
    time(new QTime(00, 50, 00)),
    timer(new QTimer),
    pausedIcon(new QIcon(":/icons/Paused.ico")),
    shortBreakIcon(new QIcon(":/icons/ShortBreak.ico")),
//    longBreakIcon(new QIcon(":/icons/LongBreak.ico")), TODO
    workingIcon(new QIcon(":/icons/Working.ico"))
{
  ui->setupUi(this);

  // Application starts without timer running
  setPhase(PhaseEnum::PAUSED);

  // Start countdown from 50 minutes
  ui->timerLabel->setText(time->toString("m:ss"));
  connect(timer, &QTimer::timeout, this, &MainWindow::updateCountdown);
//  startTimer(); TODO
}

MainWindow::~MainWindow()
{
  delete pausedIcon;
  delete shortBreakIcon;
  delete longBreakIcon;
  delete workingIcon;

  delete time;
  delete timer;

  delete ui;
}

void MainWindow::setPhase(PhaseEnum phase)
{
  this->phase = phase;
  switch (phase)
  {
  case PAUSED:
    setWindowIcon(QIcon(":/icons/Paused.ico"));
    break;
  case SHORT_BREAK:
    setWindowIcon(QIcon(":/icons/ShortBreak.ico"));
    break;
  case LONG_BREAK:
    break; // TODO
  case WORKING:
    setWindowIcon(QIcon(":/icons/Working.ico"));
    break;
  }
}

void MainWindow::startTimer()
{
  timer->start(1000);
}

void MainWindow::stopTimer()
{
  setPhase(PhaseEnum::PAUSED);
  timer->stop();
}

void MainWindow::updateCountdown()
{
  *time = time->addSecs(-1);
  ui->timerLabel->setText(time->toString("m:ss"));
  if (time->minute() == 0 && time->second() == 0 && time->hour() == 0)
  {
    stopTimer();
  }
}

