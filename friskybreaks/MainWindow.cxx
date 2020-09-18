#include "MainWindow.hxx"
#include "ui_MainWindow.h"

#include <QIcon>
#include <QTime>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent),
    ui(new Ui::MainWindow),
    time(new QTime(00, 01, 00)),
    timer(new QTimer),
    isRunning(false),
    phase(PhaseEnum::WORK_1),
    pausedIcon(new QIcon(":/icons/Paused.ico")),
    shortBreakIcon(new QIcon(":/icons/ShortBreak.ico")),
    longBreakIcon(new QIcon(":/icons/LongBreak.ico")),
    workIcon(new QIcon(":/icons/Work.ico"))
{
  ui->setupUi(this);

  setWindowTitle("FriskyBreaks");
  setFixedSize(size());

  // Application starts without timer running
  setPausedIcon();

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
  delete workIcon;

  delete time;
  delete timer;

  delete ui;
}

void MainWindow::setNextPhase()
{
  switch (phase)
  {
  case WORK_1:
    phase = PhaseEnum::SHORT_BREAK;
    break;
  case SHORT_BREAK:
    phase = PhaseEnum::WORK_2;
    break;
  case WORK_2:
    phase = PhaseEnum::LONG_BREAK;
    break;
  case LONG_BREAK:
    phase = PhaseEnum::WORK_1;
    break;
  }
}

void MainWindow::setPausedIcon()
{
  setWindowIcon(*pausedIcon);
}

void MainWindow::setPhaseIcon()
{
  switch (phase)
  {
  case WORK_1:
  case WORK_2:
    setWindowIcon(*workIcon);
    break;
  case SHORT_BREAK:
    setWindowIcon(*shortBreakIcon);
    break;
  case LONG_BREAK:
    setWindowIcon(*longBreakIcon);
    break;
  }
}

void MainWindow::setTimer()
{
  switch (phase)
  {
  case WORK_1:
  case WORK_2:
    time->setHMS(0, 50, 0);
    break;
  case SHORT_BREAK:
    time->setHMS(0, 5, 0);
    break;
  case LONG_BREAK:
    time->setHMS(0, 20, 0);
    break;
  }
}

void MainWindow::startTimer()
{
  setPhaseIcon();
  timer->start(1000);
}

void MainWindow::stopTimer()
{
  setPausedIcon();
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

  // End of timer
  if (time->minute() == 0 && time->second() == 0 && time->hour() == 0)
  {
    stopTimer();
    setNextPhase();
    setTimer();
    startTimer();
  }
}

