#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QMdiSubWindow>
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QCamera>

class SubWindow : public QMdiSubWindow
{
private:
    int x,y,w,h;
    bool working = false;
    QCameraViewfinder* display;
    QCameraInfo info;
    QCamera* camera;
public:
    SubWindow(QWidget* p = nullptr);
    SubWindow(const QCameraInfo& info, QWidget* p = nullptr);
    bool isWorking();
    void setPosSize(int x,int y,int w,int h);
    void setCameraInfo(const QCameraInfo& info);
    QCameraInfo& getCameraInfo();
    QCameraViewfinder *getDisplay();
    void stop();
};

#endif // SUBWINDOW_H
