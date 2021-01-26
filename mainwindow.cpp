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

    connect(cameraDialog,&CameraDialog::sendSelectedCamera,[this](const QCameraInfo& info){

        int pos = findCamera(info);
        if(pos!=-1){
        }else{
            auto display = new SubWindow(info,this);
            allDisplay.push_back(display);
            ui->mdiArea->addSubWindow(display);
            display->show();
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

int MainWindow::findCamera(const QCameraInfo &info)
{
    for(int i = 0;i!=allDisplay.count();i++)
    {
        if(info.description() == allDisplay[i]->getCameraInfo().description()){
            return i;
        }
    }
    return -1;
}

