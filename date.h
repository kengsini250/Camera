#ifndef DATE_H
#define DATE_H

#include <QDateTime>
#include <QString>
#include <QFile>
#include <QDir>
#include <QDebug>

class Date
{
public:
    Date();
    QString getCurr(const QString& formart);
    void changeName(const QString &name,QString,QString);
    static QString time1;
private:
};


#endif // DATE_H
