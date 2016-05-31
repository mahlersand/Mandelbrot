#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollBar>
#include "brotwidget.h"
#include <QGridLayout>
#include <QMenuBar>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
    QGridLayout *l;
    QScrollBar *sx;
    QScrollBar *sy;
    Brotwidget *w;

private:
    void setup();
signals:
    void sizeChanged(QSize newSize);
protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
