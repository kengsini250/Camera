#ifndef SAVE_H
#define SAVE_H

#include <QString>
#include <QDir>
#include <QCamera>
#include <QVideoProbe>

#include "opencv2/videoio.hpp"
#include "imgproc/types_c.h"
#include "imgproc/imgproc.hpp"

class Save : public QObject
{
    Q_OBJECT
public:
    Save();
    Save(QCamera*);
    Save(QCamera*,QString);
    void setPath(QString);
    void start();
    void stop();
private:
    bool working = false;
    QString path;
    QVideoProbe* probe;
    cv::VideoWriter writer;

private slots:
    void makeVideo(const QVideoFrame&);
};

#endif // SAVE_H
