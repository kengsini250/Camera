#ifndef SAVE_H
#define SAVE_H

#include <QString>
#include <QDir>
#include <QUrl>
#include <QCamera>
#include <QMediaRecorder>

#define QT_MULTIMEDIA_PREFERRED_PLUGINS

class Save
{
public:
    Save();
    Save(QCamera*);
    Save(QCamera*,QString);
    void setPath(QString);
    void start();
    void stop();
private:
    bool working = false;
    QMediaRecorder* save;
};

#endif // SAVE_H
