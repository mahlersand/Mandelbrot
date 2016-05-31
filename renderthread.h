#ifndef RENDERTHREAD_H
#define RENDERTHREAD_H

#include <QThread>
#include <QImage>
#include <QPointF>
#include <QPainter>
#include <cmath>
#include <QWidget>
#include <math.h>

class RenderThread : public QThread
{
    Q_OBJECT
public:
    void run();
    QImage *a;
    qint16 width;
    qint16 height;
    qint8 scroll;
    QPointF centerP;
    void renderLine(qint16 h, qint16 wid, QPainter *p, int iterations);
    QPointF absoluteOf(int ax, int ay);
    bool isMember(double x, double y, int numIterations);
signals:
    void resultReady(QImage result);
};

#endif // RENDERTHREAD_H
