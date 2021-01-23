#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QtAlgorithms>

#include "CameraDialog/cameradialog.h"
#include "SettingDialog/settingdialog.h"
#include "subwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    CameraDialog* cameraDialog;
    SettingDialog* settingDialog;
    QList<SubWindow*> allDisplay;

    /**
     * @brief findCamera
     * @param info
     * @return 不重复返回-1
     */
    int findCamera(const QCameraInfo& info);
};
#endif // MAINWINDOW_H
