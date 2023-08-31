#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playscen.h"
class chooseLeveLScene : public QMainWindow
{
    Q_OBJECT
public:
//    explicit chooseLeveLScene(QWidget *parent = nullptr);
    chooseLeveLScene();
    void paintEvent(QPaintEvent *);
    playscen *pla=NULL;


signals:
    void chooseSceneBack();
};

#endif // CHOOSELEVELSCENE_H
