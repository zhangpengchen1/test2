#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include <QPushButton>
class mypushbutton:public QPushButton
{
public:
    mypushbutton(QString normalImg,QString pressImg="");
    QString norpath;
    QString presspath;
    void zoom1();
    void zoom2();
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

};

#endif // MYPUSHBUTTON_H
