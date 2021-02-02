#ifndef SAVE_H
#define SAVE_H

#include <QDebug>
#include <QString>
#include <QDir>
#include <QImage>

#include "camera.h"
#include "opencv2/videoio.hpp"
#include "imgproc/types_c.h"
#include "imgproc/imgproc.hpp"
#include <iostream>

#include "date.h"

class Save : public QObject
{
    Q_OBJECT
public:
    Save();
    Save(Camera *,QString,QString,QString);
    void setPath(QString);
    void start();
    void stop();
private:
    bool working = false;
    Date date;
    QString path,name,format;
    QString currTime;
    cv::VideoWriter writer;
public slots:
    void outputVideo(const cv::Mat&);
};

#endif // SAVE_H
