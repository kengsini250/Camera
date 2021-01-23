#include "cameradialog.h"
#include "ui_cameradialog.h"

CameraDialog::CameraDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CameraDialog)
{
    ui->setupUi(this);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->buttonBox,&QDialogButtonBox::accepted,this,&CameraDialog::selectedCamera);
    connect(ui->listView,&QListView::doubleClicked,this,&CameraDialog::selectedCamera);
}

CameraDialog::~CameraDialog()
{
    delete ui;
}

void CameraDialog::updateCamera()
{
    auto temp = QCameraInfo::availableCameras();
    QStandardItemModel* model = new QStandardItemModel(this);
    auto p = temp.begin();
    while(p!=temp.end()){
        QString name_tmp = (*p).description();
        if(findCamera(name_tmp)){
            allCamera.insert(name_tmp,*p);
        }
        QStandardItem* item = new QStandardItem(name_tmp);
        model->appendRow(item);
        p++;
    }
    ui->listView->setModel(model);
    ui->labelCount->setText(QString::number(allCamera.size()));
}

QMap<QString, QCameraInfo> CameraDialog::getAllCamera()
{
    return allCamera;
}

bool CameraDialog::findCamera(QString name)
{
    auto p = allCamera.find(name);
    if(p!=allCamera.end()){
        return false;
    }else{
        return true;
    }
}

void CameraDialog::selectedCamera()
{
    auto t = ui->listView->currentIndex();
    auto temp = allCamera.find(t.data().toString());
    if(temp!=allCamera.end())
        emit sendSelectedCamera(temp.value());
    this->close();
}
