#ifndef MYYCON_H
#define MYYCON_H

#include <QPushButton>
#include <QTimer>
class myycon : public QPushButton
{
    Q_OBJECT
public:
//    explicit myycon(QWidget *parent = nullptr);
    myycon(QString path);
    QString path;
    int dx;
    int dy;
    bool bz;
    void fanzhuan();
    QTimer* zff;
    QTimer* ffz;
    int min=1;
    int max=8;


signals:

};

#endif // MYYCON_H
