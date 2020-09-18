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
    isRunning(false),
    pausedIcon(new QIcon(":/icons/Paused.ico")),
    shortBreakIcon(new QIcon(":/icons/ShortBreak.ico")),
//    longBreakIcon(new QIcon(":/icons/LongBreak.ico")), TODO
    workingIcon(new QIcon(":/icons/Working.ico"))
{
  ui->setupUi(this);

  setWindowTitle("FriskyBreaks");
  setFixedSize(size());

  // Application starts without timer running
  setPhase(PhaseEnum::PAUSED);

  // Set initial countdown from 50 minutes
  ui->timerButton->setText(time->toString("m:ss"));
  connect(ui->timerButton, SIGNAL(released()), this, SLOT(toggleTimer()));
  connect(timer, SIGNAL(timeout()), this, SLOT(updateCountdown()));
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

void MainWindow::toggleTimer()
{
  isRunning = !isRunning;
  if (isRunning)
  {
    startTimer();
  }
  else
  {
    stopTimer();
  }
}

void MainWindow::updateCountdown()
{
  *time = time->addSecs(-1);
  ui->timerButton->setText(time->toString("m:ss"));
  if (time->minute() == 0 && time->second() == 0 && time->hour() == 0)
  {
    stopTimer();
  }
}

