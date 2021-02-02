#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cameraDialog = new CameraDialog(this);
    connect(ui->actionNew, &QAction::triggered, [this] {
        if (!cameraDialog) {
            cameraDialog = new CameraDialog(this);
        }
        cameraDialog->updateCamera();
        cameraDialog->show();
        cameraDialog->activateWindow();
    });

    connect(cameraDialog,&CameraDialog::sendSelectedCamera,[this](int id,const QCameraInfo& info){
        auto pos = allDisplay.find(info.description());
        if(pos!=allDisplay.end()){
            pos.value()->show();
        }else{
            qDebug()<<id;
            auto display = new SubWindow(id,info,this);
            allDisplay.insert(info.description(),display);
            ui->mdiArea->addSubWindow(display);
            display->show();
            connect(display,&SubWindow::sendCameraInfo,[this](const QCameraInfo& info){
                allDisplay.remove(info.description());
            });
        }
    });

    settingDialog = new SettingDialog(this);
    connect(ui->actionSetting,&QAction::triggered,[this]{
       if (!settingDialog){
            settingDialog = new SettingDialog(this);
       }
       settingDialog->setAllCamera(cameraDialog->getAllCamera());
       settingDialog->show();
       settingDialog->activateWindow();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
