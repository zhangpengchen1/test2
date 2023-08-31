#include "chooselevelscene.h"
#include <QPainter>
#include <QMenuBar>
#include "mypushbutton.h"
#include <QDebug>
#include <QLabel>
#include "playscen.h"
//chooseLeveLScene::chooseLeveLScene(QWidget *parent) : QMainWindow(parent)
//{

//}
chooseLeveLScene::chooseLeveLScene()
{
    setFixedSize(320,580);
    setWindowIcon(QIcon(":/res/LevelIcon.png"));
    setWindowTitle("选择关卡场景");
    QMenuBar *bar=new QMenuBar(this);
    setMenuBar(bar);
    QMenu * st=bar->addMenu("开始");
    QAction * p= st->addAction("退出");
    connect(p,&QAction::triggered,[=](){
       this->close();
    });
    mypushbutton * startbtn=new mypushbutton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    startbtn->setParent(this);
    startbtn->move(this->width()-startbtn->width(),this->height()-startbtn->height());

    connect(startbtn,&QPushButton::clicked,[=](){
       emit this->chooseSceneBack();

    });
    for(int i=0;i<20;i++)
    {
        mypushbutton * menuBtn=new mypushbutton(":/res/Coin0008.png");
        menuBtn->setParent(this);
        menuBtn->move(25+i%4*70,120+i/4*70);
        QLabel* label=new QLabel(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25+i%4*70,130+i/4*70);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignHCenter);
        connect(menuBtn,&QPushButton::clicked,[=](){
            this->hide();
            pla=new playscen(i+1);
            pla->show();
            connect(pla,&playscen::chooseSceneBack1,[=](){
                this->show();
                delete pla;
                pla=NULL;
            });
        });
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }



}
void chooseLeveLScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);
    pix.load(":/res/BackButtonSelected.png");

}


