#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>
#include <QDebug>
#include <QPainter>
mypushbutton::mypushbutton(QString normalImg,QString pressImg)
{
    this->norpath=normalImg;
    this->presspath=pressImg;
    QPixmap pix;
    bool ret=pix.load(normalImg);
    if(!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}
void mypushbutton::zoom1()//向下
{
   QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
   animation->setDuration(200);
   animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
   animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
   animation->setEasingCurve(QEasingCurve::OutBounce);
   animation->start();
}
void mypushbutton::zoom2()//向上
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}
void mypushbutton::mousePressEvent(QMouseEvent *e)
{
    if(this->presspath != "")
    {
        QPixmap pix;
        bool ret=pix.load(this->presspath);
        if(!ret)
        {
            qDebug()<<"加载失败";
        }
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        QPainter painter(this);
    }
    return QPushButton::mousePressEvent(e);
}
void mypushbutton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->norpath!="")
    {
        QPixmap pix;
        bool ret=pix.load(this->norpath);
        if(!ret)
        {
            qDebug()<<"加载失败";
        }
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mouseReleaseEvent(e);
}
