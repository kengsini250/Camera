#include "camera.h"

Camera::Camera(QObject* p):QObject(p)
{}

Camera::Camera(int i,QObject* p):id(i),QObject(p)
{
    open(i);
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, [&]{
        if(!camera.isOpened()){
            camera.open(id);
        }
        cv::Mat frame;
        camera>>frame;
        send(frame);
        if(!frame.empty()){
            cv::cvtColor(frame,frame,CV_BGR2RGB);
            QImage img((const unsigned char*)frame.data,frame.cols, frame.rows,QImage::Format_RGB888);
            send(img);
        }
    });

}

void Camera::open(int id)
{
    camera.open(id);
}

int Camera::getID()
{
    return id;
}

void Camera::setTimer(int ms)
{
    timer->start(ms);
}

void Camera::start()
{
    setTimer(1/15*1000);
}

void Camera::stop()
{
    camera.release();
}
