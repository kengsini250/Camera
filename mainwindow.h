#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QtAlgorithms>

#include "CameraDialog/cameradialog.h"
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
    QList<SubWindow*> allDisplay;

    int findCamera(const QCameraInfo& info);
};
#endif // MAINWINDOW_H
