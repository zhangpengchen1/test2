#include "playscen.h"
#include <QPainter>
#include <QMenuBar>
#include <QLabel>
#include "myycon.h"
#include <QDebug>
#include "shuzu.h"
#include <QPropertyAnimation>
//playscen::playscen(QWidget *parent) : QMainWindow(parent)
//{

//}
playscen::playscen(int a)
{
    this->a=a;
    setFixedSize(320,580);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("关卡");
    QMenuBar *bar=new QMenuBar(this);
    setMenuBar(bar);
    QMenu* par=bar->addMenu("开始");
    QAction* tar= par->addAction("关闭");
    connect(tar,&QAction::triggered,[=](){
      this->close();
    });

    mypushbutton *btn=new mypushbutton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    btn->setParent(this);
    btn->move(this->width()-btn->width(),this->height()-btn->height());
    connect(btn,&QPushButton::clicked,[=](){
       emit this->chooseSceneBack1();
    });
    QLabel* label=new QLabel(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    QString str=QString("第%1关").arg(this->a);
    label->setText(str);
    label->setGeometry(30,this->height()-50,120,50);
    shuzu pxt;
    QLabel* anmation=new QLabel;
    QPixmap pix1;
    pix1.load(":/res/LevelCompletedDialogBg.png");
    anmation->setGeometry(0,0,pix1.width(),pix1.height());
    anmation->setPixmap(pix1);
    anmation->setParent(this);
    anmation->move((this->width()-pix1.width())*0.5,-pix1.height());

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            this->arr[i][j]=pxt.mData[this->a][i][j];
        }
    }
    for(int x=0;x<4;x++)
    {
        for(int y=0;y<4;y++)
        {
           QPixmap pix=QPixmap(":/res/BoardNode.png");
           QLabel* label2=new QLabel(this);
           label2->setGeometry(0,0,pix.width(),pix.height());
           label2->setPixmap(pix);
           label2->move(57+x*50,200+y*50);
           QString str;
           if(this->arr[x][y]==1)
           {
               str=":/res/Coin0001.png";

           }
           else
           {
                str=":/res/Coin0008.png";
           }
           myycon* con=new myycon(str);
           con->setParent(this);
           con->move(57+x*50,200+y*50);
           con->dx=x;
           con->dy=y;
           con->bz=this->arr[x][y];
           this->conbtn[x][y]=con;
           connect(con,&myycon::clicked,[=](){
               con->fanzhuan();
               if(con->dx+1<=3)
               {
                   conbtn[con->dx+1][con->dy]->fanzhuan();
               }
               if(con->dx-1>=0)
               {
                   conbtn[con->dx-1][con->dy]->fanzhuan();
               }
               if(con->dy+1<=3)
               {
                   conbtn[con->dx][con->dy+1]->fanzhuan();
               }
               if(con->dy-1>=0)
               {
                   conbtn[con->dx][con->dy-1]->fanzhuan();
               }
               this->sl=true;
               for(int x=0;x<4;x++)
               {
                   for(int y=0;y<4;y++)
                   {
                       if(conbtn[x][y]->bz==false)
                       {
                           this->sl=false;
                           break;
                       }
                   }
               }
               if(this->sl==true)
               {
                   //qDebug()<<"胜利";
                   QPropertyAnimation *donghua=new QPropertyAnimation(anmation,"geometry");
                   donghua->setDuration(1000);
                   donghua->setStartValue(QRect(anmation->x(),anmation->y(),anmation->width(),anmation->height()));
                   donghua->setEndValue(QRect(anmation->x(),anmation->y()+114,anmation->width(),anmation->height()));
                   donghua->setEasingCurve(QEasingCurve::OutBounce);
                   donghua->start();
               }
           });
        }
    }
}
void playscen::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);
}
