#include "myycon.h"

//myycon::myycon(QWidget *parent) : QMainWindow(parent)
//{

//}
 myycon::myycon(QString path)
 {
     this->path=path;
     //this->bz=false;
     QPixmap pix;
     pix.load(path);
     setFixedSize(pix.width(),pix.height());
     setStyleSheet("QPushButtom{border:0px;}");
     setIcon(pix);
     setIconSize(QSize(pix.width(),pix.height()));
     zff=new QTimer(this);
     ffz=new QTimer(this);
     connect(zff,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str=QString(":/res/Coin000%1.png").arg(this->min++);
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButtom{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(this->min>this->max)
        {
            this->min=1;
            zff->stop();
        }

     });
     connect(ffz,&QTimer::timeout,[=](){
         QPixmap pix;
         QString str=QString(":/res/Coin000%1.png").arg(this->max--);
         pix.load(str);
         this->setFixedSize(pix.width(),pix.height());
         this->setStyleSheet("QPushButtom{border:0px;}");
         this->setIcon(pix);
         this->setIconSize(QSize(pix.width(),pix.height()));
         if(this->max<this->min)
         {
             this->max=8;
             ffz->stop();
         }
     });
 }
void myycon::fanzhuan()
{
    if(this->bz==true)
    {
        zff->start(30);
        this->bz=false;
    }
    else
    {
        ffz->start(30);
        this->bz=true;
    }
}
