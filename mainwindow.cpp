#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include "mypushbutton.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(320,580);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("翻金币");
    connect(ui->actiontui,&QAction::triggered,[=](){
       this->close();
    });
    pa =new chooseLeveLScene;

    mypushbutton* startbtn=new mypushbutton(":/res/MenuSceneStartButton.png");
    startbtn->setParent(this);
    startbtn->move(this->width()*0.5-startbtn->width()*0.5,this->height()*0.7);
    connect(startbtn,&QPushButton::clicked,[=](){
        qDebug()<<"点击";
        startbtn->zoom1();
        startbtn->zoom2();
        QTimer::singleShot(500,this,[=](){
            this->hide();
            pa->show();
        });

    });
    connect(pa,&chooseLeveLScene::chooseSceneBack,[=](){
        pa->hide();
        this->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix);

}

