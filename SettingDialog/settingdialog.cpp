#include "settingdialog.h"
#include "ui_settingdialog.h"

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void SettingDialog::setAllCamera(const QMap<QString, QCameraInfo>& c)
{
    allCamera = c;
    QStandardItemModel* model = new QStandardItemModel(this);
    auto p = allCamera.begin();
    while(p!=allCamera.end()){
        QString name_tmp = (*p).description();
        QStandardItem* item = new QStandardItem(name_tmp);
        model->appendRow(item);
        p++;
    }
    ui->listView->setModel(model);
}

SettingDialog::~SettingDialog()
{
    delete ui;
}
