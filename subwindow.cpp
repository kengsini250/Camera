#include "subwindow.h"

SubWindow::SubWindow(QWidget* p):QMdiSubWindow(p),x(20),y(20),w(200),h(200)
{}

SubWindow::SubWindow(const QCameraInfo &info, QWidget *p):QMdiSubWindow(p),x(20),y(20),w(200),h(200)
{
    setAttribute(Qt::WA_DeleteOnClose);
    display = new QCameraViewfinder;
    setWidget(display);
    setCameraInfo(info);
    camera = new QCamera(info);
    camera->setViewfinder(display);
    camera->start();
}

bool SubWindow::isWorking()
{
    return working;
}

void SubWindow::setPosSize(int x, int y, int w, int h)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    setGeometry(x,y,w,h);
}

void SubWindow::setCameraInfo(const QCameraInfo& info)
{
    this->info = info;
}

QCameraInfo &SubWindow::getCameraInfo()
{
    return info;
}

QCameraViewfinder* SubWindow::getDisplay()
{
    return display;
}

void SubWindow::stop()
{
    camera->stop();
}
