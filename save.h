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

class Save : public QObject
{
    Q_OBJECT
public:
    Save();
    Save(Camera*);
    Save(Camera*,QString);
    void setPath(QString);
    void start();
    void stop();
private:
    bool working = false;
    QString path;
    cv::VideoWriter writer;
public slots:
    void outputVideo(const cv::Mat&);
};

#endif // SAVE_H
