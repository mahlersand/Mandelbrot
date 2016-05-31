#include "mainwindow.h"

MainWindow::MainWindow()
{
    setup();
    setMinimumSize(400, 300);

}

MainWindow::~MainWindow()
{

}

void MainWindow::setup()
{
    //Setup the Layout
    l = new QGridLayout(this);
    l->setMargin(0);



    //Setup the Brotwidget
    w = new Brotwidget(this);
    l->addWidget(w, 1, 0);
    //MainWindow::connect(this, &MainWindow::sizeChanged,
    //                    w, &Brotwidget::setSize);


    /*
    //Setup the ScrollBarX (Horizontal)
    sx = new QScrollBar(Qt::Horizontal, this);
    QScrollBar::connect(sx, &QScrollBar::sliderMoved,
                        w, &Brotwidget::setScrollValueX);
    sx->setMaximum(1000000);
    sx->setMinimum(0);
    l->addWidget(sx,1,0,Qt::AlignBottom);

    //Setup the ScrollBarY (Vertical)
    sy = new QScrollBar(Qt::Vertical, this);
    //QScrollBar::connect(&sy, &QScrollBar::sliderMoved,
    //                    &w, &Brotwidget::setScrollValueY);
    //sy.setMaximum(1000000);
    //sy.setMinimum(0);
    l->addWidget(sy,0,1,Qt::AlignRight);
    */



    setLayout(l);



}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //emit sizeChanged(size());
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->text() == QString("r"))
    {
        w->resetAll();
    }
    else if(event->text() == QString("w"))
    {
        w->setCenterRelative(QPoint(w->width()/2,w->height()/4));
        w->repaint();
    }
    else if(event->text() == QString("a"))
    {
        w->setCenterRelative(QPoint(w->width()/4,w->height()/2));
        w->repaint();
    }
    else if(event->text() == QString("s"))
    {
        w->setCenterRelative(QPoint(w->width()/2,w->height()/4*3));
        w->repaint();
    }
    else if(event->text() == QString("d"))
    {
        w->setCenterRelative(QPoint(w->width()/4*3,w->height()/2));
        w->repaint();
    }
}
