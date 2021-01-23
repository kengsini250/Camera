#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QCameraInfo>
#include <QString>
#include <QStandardItemModel>
#include <QStandardItem>

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = nullptr);
    void setAllCamera(const QMap<QString, QCameraInfo>&);
    ~SettingDialog();

private:
    Ui::SettingDialog *ui;
    QMap<QString, QCameraInfo> allCamera;
};

#endif // SETTINGDIALOG_H
