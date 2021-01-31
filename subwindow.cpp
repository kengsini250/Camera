#include "subwindow.h"

SubWindow::SubWindow(QWidget* p):QMdiSubWindow(p),x(20),y(20),w(200),h(200)
{}

SubWindow::SubWindow(int i,const QCameraInfo &info, QWidget *p):QMdiSubWindow(p),x(20),y(20),w(200),h(200),id(i)
{
    setAttribute(Qt::WA_DeleteOnClose);
    resize(w,h);
    display = new QLabel(this);
    display->resize(w,h);
    setWidget(display);
    setCameraInfo(info);

    camera = new Camera(0,this);
    connect(camera,QOverload<const QImage&>::of(&Camera::send),[this](const QImage&img){
        display->setPixmap(QPixmap::fromImage(img));
    });

    save = new Save(camera,QDir::currentPath()+"/test.avi");

    camera->start();
    save->start();

    working = true;
}

SubWindow::~SubWindow()
{
    stop();
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

void SubWindow::stop()
{
    camera->stop();
    save->stop();
    working=false;
}
