#include "save.h"

Save::Save()
{

}

Save::Save(QCamera *camera)
{

}

Save::Save(QCamera *camera,QString savePath)
{
    probe = new QVideoProbe;
    probe->setSource(camera);
    setPath(savePath);

    writer.open(path.toStdString(),
                cv::VideoWriter::fourcc('M', 'P', '4', '2'),
                60,cv::Size(640, 480));

    connect(probe, SIGNAL(videoFrameProbed(QVideoFrame)), this, SLOT(makeVideo(QVideoFrame)));
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

void Save::makeVideo(const QVideoFrame &frame)
{
    QVideoFrame copy = frame;
    if (copy.map(QAbstractVideoBuffer::ReadOnly)) {
        const cv::Mat mat(copy.height(), copy.width(), CV_8UC3,
                          copy.bits(),copy.bytesPerLine());
        cv::Mat result;
        cvtColor(mat, result,CV_BGR2RGB);
        writer<<result;
    }else{
        copy.map(QAbstractVideoBuffer::ReadOnly);
        const cv::Mat mat(copy.height(), copy.width(), CV_8UC3,
                          copy.bits(),copy.bytesPerLine());
        cv::Mat result;
        cvtColor(mat, result,CV_BGR2RGB);
        writer<<result;
    }
    copy.unmap();
}
