#include "date.h"

QString Date::time1 = "yyyy_MM_dd_hh_mm_ss";

Date::Date()
{

}

QString Date::getCurr(const QString& formart)
{
    return QDateTime::currentDateTime().toString(formart);
}

void Date::changeName(const QString &name,QString curr,QString format)
{
    QString name_tmp = name.left(name.count()-format.count());
    QString newName = name_tmp+"-"+curr+"-"+getCurr(time1)+format;
    QFile file(name);
    if(file.isOpen()){
        file.close();
    }
    file.rename(newName);

}
