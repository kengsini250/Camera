#ifndef CAMERADIALOG_H
#define CAMERADIALOG_H

#include <QDialog>
#include <QCameraInfo>

#include <QMap>
#include <QList>
#include <QString>
#include <QStandardItemModel>
#include <QStandardItem>

namespace Ui {
class CameraDialog;
}

class CameraDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CameraDialog(QWidget *parent = nullptr);
    ~CameraDialog();

    void updateCamera();
    QMap<QString,QCameraInfo> getAllCamera();

private:
    Ui::CameraDialog *ui;
    QMap<QString,QCameraInfo> allCamera;

    /**
     * @brief findCamera
     * @return 不重复返回true
     */
    bool findCamera(QString);

private slots:
    void selectedCamera();
signals:
    void sendSelectedCamera(const QCameraInfo&);
};

#endif // CAMERADIALOG_H
