#ifndef PLAYSCEN_H
#define PLAYSCEN_H
#include "mypushbutton.h"
#include <QMainWindow>
#include "myycon.h"

class playscen : public QMainWindow
{
    Q_OBJECT
public:
//    explicit playscen(QWidget *parent = nullptr);
    playscen(int a);
    int a;
    void paintEvent(QPaintEvent *);
    int arr[4][4];
    myycon *conbtn[4][4];
    bool sl;

signals:
    void chooseSceneBack1();

};

#endif // PLAYSCEN_H
