#include "save.h"

Save::Save()
{

}

Save::Save(Camera *camera,QString savePath,QString n,QString f)
{
    setPath(savePath);
    this->name=n+f;
    currTime=QDateTime::currentDateTime().toString(Date::time1);
    this->format = f;

    writer.open(
                name.toStdString(),
//                cv::VideoWriter::fourcc('M', 'P', '4', 'S'),
//                cv::VideoWriter::fourcc('M', 'J', 'P', 'G'),
                cv::VideoWriter::fourcc('X', 'V', 'I', 'D'),
                15,cv::Size(640, 480));
    connect(camera,QOverload<const cv::Mat&>::of(&Camera::send),this,&Save::outputVideo);
}

void Save::setPath(QString savePath)
{
    path=savePath;
}

void Save::start()
{
    working=true;
}

void Save::stop()
{
    working=false;
    writer.release();
    date.changeName(name,currTime,format);
}

void Save::outputVideo(const cv::Mat& frame)
{
    if(writer.isOpened() && working){
//    if(writer.isOpened()){
        writer<<frame;
    }
}
