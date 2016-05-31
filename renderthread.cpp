#include "renderthread.h"


void RenderThread::run() Q_DECL_OVERRIDE
{
    int iterMax = 1000;
    QPainter p(a);
    p.setFont(QFont("Arial", 10));


    for(int h = 0;h<height;h++)
    {
        renderLine(h, width, &p, iterMax);
    }



    //Größen-Overlay (Debug)
    p.setPen(Qt::white);
    p.drawText(0, 20, QString("Größe: %1").arg(scroll));
    p.drawText(100, 20, QString("X: %1 Y: %2").arg(centerP.x()).arg(centerP.y()));
    emit resultReady(*a);
}

void RenderThread::renderLine(qint16 h, qint16 wid, QPainter *p, int iterations)
{
    for(int w = 0; w<wid; w++)
    {
        //double ax = absoluteOf(w,h).x();
        //double ay = absoluteOf(w,h).y();
        if(isMember(absoluteOf(w,h).x(),absoluteOf(w,h).y(),iterations))
        {
            p->drawPoint(w,h);
        }
    }
}

QPointF RenderThread::absoluteOf(int ax, int ay)
{
    double x = centerP.x() + (0.01f/std::pow(1.5,scroll+2) * (-0.5 * width + ax));
    double y = centerP.y() + (0.01f/std::pow(1.5,scroll+2) * (0.5 * height - ay));
    return QPointF(x, y);
}

bool RenderThread::isMember(double x, double y, int numIterations)
{
    if(std::abs(x*y)>2){return false;}
    if(((x+0.25)*(x+0.25)+y*y)<0.25){return true;}
    if(((x+1)*(x+1)+y*y)<0.0625){return true;}

    double point_real = x;
    double point_imag = y;
    double temp_real = x;
    double temp_imag = y;
    double temp;

    for(int iteration = 0; iteration < numIterations; iteration++)
    {
        temp = temp_real * temp_real - temp_imag * temp_imag + point_real;
        temp_imag = 2 * temp_real * temp_imag + point_imag;
        temp_real = temp;
        if(
           (temp_imag * temp_imag
           +temp_real * temp_real) > 16)
            {return false;}
    }
    return true;

}
