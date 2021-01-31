#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QTimer>
#include <QImage>

#include "videoio/videoio.hpp"
#include "imgproc/types_c.h"
#include "imgproc/imgproc.hpp"

class Camera : public QObject
{
    Q_OBJECT
private:
    int id;
    cv::VideoCapture camera;
    QTimer* timer;
public:
    Camera(QObject* p=nullptr);
    Camera(int,QObject* p=nullptr);
    void open(int);
    int getID();

    void setTimer(int ms);
public slots:
    void start();
    void stop();

signals:
    void send(const cv::Mat&);
    void send(const QImage&);
};

#endif
