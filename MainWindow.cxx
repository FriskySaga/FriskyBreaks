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
  ui->timerLabel->setText("50:00");
  connect(timer, &QTimer::timeout, this, &MainWindow::updateCountdown);
  timer->start(1000);
}

MainWindow::~MainWindow()
{
  delete time;
  delete timer;
  delete ui;
}

void MainWindow::updateCountdown()
{
  *time = time->addSecs(-1);
  ui->timerLabel->setText(time->toString("m:ss"));
}

