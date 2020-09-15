#include "MainWindow.hxx"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStyleSheet("background-color: #111;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

