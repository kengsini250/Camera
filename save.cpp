#include "save.h"

Save::Save()
{

}

Save::Save(Camera *c)
{

}

Save::Save(Camera *camera,QString savePath)
{
    writer.open(savePath.toStdString(),
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
    working = true;
}

void Save::stop()
{
    working = false;
    writer.release();
}

void Save::outputVideo(const cv::Mat& frame)
{
    if(writer.isOpened()){
        writer<<frame;
    }
}
