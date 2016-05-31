#include "brotwidget.h"

Brotwidget::Brotwidget(QWidget *parent) :
    QWidget(parent)
{

}


void Brotwidget::paintEvent(QPaintEvent *event)
{
    /*if(!newRender)
    {
        RenderThread *t = new RenderThread(this);
        connect(t, SIGNAL(resultReady(QImage)),
                this, SLOT(renderIteration(QImage)));
        t.start();
    }
    else
    {
        QPainter p(this);
        p.drawImage(0, 0, *image);

        newRender = 0;
    }*/



    int iterMax = 1000;
    QPainter p(this);
    p.setFont(QFont("Arial", 10));
    qint16 wid = width();
    qint16 hig = height();


    for(int h = 0;h<hig;h++)
    {
        renderLine(h, wid, &p, iterMax);
    }



    //Größen-Overlay (Debug)
    p.setPen(Qt::white);
    p.drawText(0, 20, QString("Größe: %1").arg(scroll));
    p.drawText(100, 20, QString("X: %1 Y: %2").arg(centerP.x()).arg(centerP.y()));


    /*
    p.setPen(Qt::black);
    p.setPen(QPen(QBrush(),5));
    QVector<QPoint> v;
    v.append(QPoint(width()/2-10,height()/2-10));
    v.append(QPoint(width()/2-10,height()/2+10));
    v.append(QPoint(width()/2+10,height()/2-10));
    v.append(QPoint(width()/2+10,height()/2+10));
    p.drawPolyline(QPolygon(v));*/

}


void Brotwidget::setSize(QSize s)
{
    setFixedSize(QSize(s.width(), s.height()));
}


void Brotwidget::wheelEvent(QWheelEvent *event)
{
    setCenterRelative(event->pos());
    changeScroll(event->angleDelta());
}


void Brotwidget::changeScroll(QPoint changes)
{
    scroll = scroll + (changes.y()/120);
    repaint();
}


bool Brotwidget::isMember(double x, double y, int numIterations)
{
    if(std::abs(x*y)>2){return false;}
    if(((x+0.25)*(x+0.25)+y*y)<0.25){return true;}
    if(((x+1)*(x+1)+y*y)<0.0625){return true;}
    /*std::complex<double> point(x, y);
    std::complex<double> temp(point);
    for(int iteration = 0; iteration < numIterations; iteration++)
    {
        temp = (temp * temp) + point;
        if(std::sqrt(
            temp.imag() * temp.imag()
           +temp.real() * temp.real()) > 4)
            {return false;}
    }
    return true;*/

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


void Brotwidget::setCenterRelative(QPoint newCenter)
{
    centerP = absoluteOf(newCenter.x(),newCenter.y());
    //new x
    //double x = centerP.x() + (1.0/std::pow(10.0,scroll+2) * (-0.5 * (double)width() + (double)newCenter.x()));
    //centerP.setX(x);

    //new y
    //double y = centerP.y() + (1.0/std::pow(10.0,scroll+2) * (0.5 * (double)height() - (double)newCenter.y()));
    //centerP.setY(y);
}


void Brotwidget::renderIteration(QImage m)
{
    image = &m;
    newRender = true;
    repaint();
}


void Brotwidget::setCenterDirect(QPointF newCenter)
{
    centerP = newCenter;
    repaint();
}


void Brotwidget::resetAll()
{
    scroll = 0;
    setCenterDirect(QPointF(0.0,0.0));
    repaint();
}

QPointF Brotwidget::absoluteOf(int ax, int ay)
{
    double x = centerP.x() + (0.01f/std::pow(1.5,scroll+2) * (-0.5 * width() + ax));
    double y = centerP.y() + (0.01f/std::pow(1.5,scroll+2) * (0.5 * height() - ay));
    return QPointF(x, y);
}

void Brotwidget::renderLine(qint16 h, qint16 wid, QPainter *p, int iterations)
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
