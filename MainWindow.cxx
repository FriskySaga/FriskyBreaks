#include "MainWindow.hxx"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent),
    ui(new Ui::MainWindow),
    time(new QTime(00, 50, 00)),
    timer(new QTimer)
{
  ui->setupUi(this);

  // Start countdown from 50 minutes
  ui->timerLabel->setText(time->toString("m:ss"));
  connect(timer, &QTimer::timeout, this, &MainWindow::updateCountdown);
  startTimer();
}

MainWindow::~MainWindow()
{
  delete time;
  delete timer;
  delete ui;
}

void MainWindow::startTimer()
{
  timer->start(1000);
}

void MainWindow::stopTimer()
{
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

