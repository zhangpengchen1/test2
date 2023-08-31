#ifndef SHUZU_H
#define SHUZU_H
#include <QMap>
#include <QVector>
#include <QObject>

class shuzu : public QObject
{
    Q_OBJECT
public:
    explicit shuzu(QObject *parent = nullptr);
    QMap<int,QVector<QVector <int>>>mData;

signals:

};

#endif // SHUZU_H
