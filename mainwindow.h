#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include"commongraphics.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPainter painter;


    GShape *circle,*circle1,*fellipse;

    //user area
private:
    Ui::MainWindow *ui;
protected:
    void paintEvent(QPaintEvent*);
};

#endif // MAINWINDOW_H
