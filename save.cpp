#include "save.h"

Save::Save()
{

}

Save::Save(QCamera *camera)
{
    save = new QMediaRecorder(camera);
}

Save::Save(QCamera *camera,QString savePath)
{
    save = new QMediaRecorder(camera);
    setPath(savePath);
}

void Save::setPath(QString savePath)
{
    save->setOutputLocation(QUrl(savePath));
}

void Save::start()
{
    save->record();
}

void Save::stop()
{
    save->stop();
}
