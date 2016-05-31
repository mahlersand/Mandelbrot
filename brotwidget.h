#ifndef BROTWIDGET_H
#define BROTWIDGET_H

#include <QWidget>
#include <QWheelEvent>
#include <QPainter>
#include <QFont>
#include <QBrush>
#include <QPen>
#include <QPaintEvent>
#include <QPixmap>
#include <complex>
#include <math.h>
#include <QDebug>
#include <QPointF>
#include <QMenuBar>
#include <vector>
#include "renderthread.h"


class Brotwidget : public QWidget
{
    Q_OBJECT
public:
    explicit Brotwidget(QWidget *parent = 0);
    void changeScroll(QPoint changes);
    void setCenterRelative(QPoint newCenter);
    void setCenterDirect(QPointF newCenter);
    void resetAll();
    QPointF absoluteOf(int ax, int ay);
    void renderLine(qint16 h, qint16 wid, QPainter *p, int iterations);
signals:

public slots:
    void setSize(QSize s);
    void renderIteration(QImage m);
private:
    int scroll = 0;
    bool isMember(double x, double y, int numIterations);
    float pixelfactor = 0.01;
    QPointF centerP;
    bool newRender = 1;
    QImage *image;
protected:
    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent *event);
};

#endif // BROTWIDGET_H
