#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QMdiSubWindow>
#include <QCameraInfo>
#include <QLabel>

#include "camera.h"
#include "save.h"

class SubWindow : public QMdiSubWindow
{
    Q_OBJECT
private:
    int x,y,w,h;
    int id=-1;
    bool working = false;
    QLabel* display;
    QCameraInfo info;
    Camera* camera;

    Save* save;
public:
    SubWindow(QWidget* p = nullptr);
    SubWindow(int,const QCameraInfo& info, QWidget* p = nullptr);
    ~SubWindow();
    bool isWorking();
    void setPosSize(int x,int y,int w,int h);
    void setCameraInfo(const QCameraInfo& info);
    QCameraInfo& getCameraInfo();
    void stop();
};

#endif // SUBWINDOW_H
