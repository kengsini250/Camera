#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
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
    QMap<QString,SubWindow*> allDisplay;

    CameraDialog* cameraDialog;
    SettingDialog* settingDialog;
};
#endif // MAINWINDOW_H
