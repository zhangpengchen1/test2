#ifndef MYCON_H
#define MYCON_H

#include <QMainWindow>
#include <QPushButton>
class mycon : public QPushButton
{
    Q_OBJECT
public:
//    explicit mycon(QWidget *parent = nullptr);
    mycon(QString path);
    QString path;

signals:

};

#endif // MYCON_H
