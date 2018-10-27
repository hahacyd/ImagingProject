#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    circle = new GCircle(&painter);
    circle1 = new GCircle(&painter);
    fellipse = new GEllipse(&painter);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent*){
    painter.begin(this);
    painter.setPen(QPen(Qt::blue));
    circle->drawItem(300,300,150);
    circle1->drawItem(400,400,100);
    fellipse->drawItem(150,200,100,80);
    painter.end();
}
