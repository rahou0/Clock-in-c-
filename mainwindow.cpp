#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<QDateTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(MyTimerSlot()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
double tab[60]={M_PI/2,14*M_PI/30,13*M_PI/30,12*M_PI/30,11*M_PI/30,10*M_PI/30,9*M_PI/30,8*M_PI/30,7*M_PI/30,6*M_PI/30,5*M_PI/30,4*M_PI/30,3*M_PI/30
                ,2*M_PI/30,M_PI/30,0
                ,59*M_PI/30,58*M_PI/30,57*M_PI/30,56*M_PI/30,55*M_PI/30,54*M_PI/30,53*M_PI/30,52*M_PI/30,51*M_PI/30,50*M_PI/30,49*M_PI/30,48*M_PI/30
                ,47*M_PI/30,46*M_PI/30
                ,3*M_PI/2
                ,44*M_PI/30,43*M_PI/30,42*M_PI/30,41*M_PI/30,40*M_PI/30,39*M_PI/30,38*M_PI/30,37*M_PI/30,36*M_PI/30,35*M_PI/30,34*M_PI/30,33*M_PI/30
                ,32*M_PI/30,31*M_PI/30
                ,M_PI
                ,29*M_PI/30,28*M_PI/30,27*M_PI/30,26*M_PI/30,25*M_PI/30,24*M_PI/30,23*M_PI/30,22*M_PI/30,21*M_PI/30,20*M_PI/30,19*M_PI/30,18*M_PI/30
                ,17*M_PI/30,16*M_PI/30};
double hours[24]={M_PI/2,10*M_PI/30,5*M_PI/30,0,55*M_PI/30,50*M_PI/30,3*M_PI/2,40*M_PI/3,35*M_PI/300,M_PI,25*M_PI/30,20*M_PI/30
                 ,M_PI/2,10*M_PI/30,5*M_PI/30,0,55*M_PI/30,50*M_PI/30,3*M_PI/2,40*M_PI/3,35*M_PI/300,M_PI,25*M_PI/30,20*M_PI/30};
void MainWindow::paintEvent(QPaintEvent *event){
    QDateTime currentateTime = QDateTime::currentDateTime();
    int min=currentateTime.toString("mm ap").toInt();
    int hour=currentateTime.toString("hh ap").toInt();
    int sec=currentateTime.toString("ss ap").toInt();
    QPainter p(this);
    //draw the big circle
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(QPen(QColor(20, 37, 80)));
    p.setBrush(QBrush(QColor(20, 37, 80)));
    QRect bigBlueCircle(100,500,900,900);
    bigBlueCircle.moveCenter(QPoint(500,500));
    p.drawEllipse(bigBlueCircle);
    //draw the inner circle
    p.setPen(QPen(QColor(34, 51, 93)));
    p.setBrush(QBrush(QColor(34, 51, 93)));
    QRect innerCircle(100,500,700,700);
    innerCircle.moveCenter(QPoint(500,500));
    p.drawEllipse(innerCircle);
    //3a9Arib sa3a
    p.setPen(QPen(QColor(216, 31, 114),5));
    p.drawLine(500, 500, 500+375*cos(tab[sec]), 500-375*sin(tab[sec]));
    p.drawLine(500, 500, 500-75*cos(tab[sec]), 500+75*sin(tab[sec]));
    //new create new painter for the mostatilat
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(1000 / 2, 1000 / 2);
    painter.scale(900 / 200.0, 900 / 200.0);
    painter.setPen(QPen(Qt::white, 1));
    //
    for (int i = 0; i < 12; ++i) {
        painter.drawLine(90, 0, 96, 0);
            painter.rotate(30.0);
        }
    painter.save();
    //
    for (int j = 0; j < 60; ++j) {
        painter.setPen(QPen(QBrush(QColor(72, 85, 119)), 0.8));
            if ((j % 5) != 0){
                painter.drawLine(92, 0, 96, 0);
                if(sec>15){
                    if(sec-15==j){
                        painter.setPen(QPen(QBrush(QColor(216, 31, 114)), 0.8));
                        painter.drawLine(92, 0, 96, 0);
                    }
                }else{
                    if(sec==j-45){
                        painter.setPen(QPen(QBrush(QColor(216, 31, 114)), 0.8));
                        painter.drawLine(92, 0, 96, 0);
                    }
                }
            }
            painter.rotate(6.0);
    }
    painter.save();
    //
    painter.setPen(QPen(QBrush(Qt::white), 2));
    for (int i = 0; i < 4; ++i){
    painter.drawLine(88, 0, 96, 0);
        painter.rotate(90.0);
    }
    QPainter painter2(this);
    painter2.setRenderHint(QPainter::Antialiasing);
    painter2.translate(1000 / 2, 1000 / 2);
    painter2.scale(900 / 200.0, 900 / 200.0);
    painter2.setPen(QPen(Qt::white, 3));

        if(hour>3){
            painter2.rotate(30*hour-3*30);
                       painter2.drawLine(0, 0, 50, 0);
                       painter2.drawLine(0, 0, -13, 0);
        }else{
            painter2.rotate(30*hour+9*30);
                      painter2.drawLine(0, 0, 50, 0);
                      painter2.drawLine(0, 0, -13, 0);
        }
        painter2.save();
        QPainter painter3(this);
        painter3.setRenderHint(QPainter::Antialiasing);
        painter3.translate(1000 / 2, 1000 / 2);
        painter3.scale(900 / 200.0, 900 / 200.0);
        painter3.setPen(QPen(QColor(159, 167, 188), 3));

            if(min>15){
                painter3.rotate(6*min-15*6);
                           painter3.drawLine(0, 0, 65, 0);
                           painter3.drawLine(0, 0, -16, 0);
            }else{
                painter3.rotate(6*min+45*6);
                          painter3.drawLine(0, 0, 65, 0);
                          painter3.drawLine(0, 0, -16, 0);
            }
            painter3.save();
        QPainter painter1(this);
        painter1.setRenderHint(QPainter::Antialiasing);
        painter1.setPen(QPen(QColor(216, 31, 114)));
        painter1.setBrush(QColor(216, 31, 114));
        QRect h88(0,0,30,30);
        h88.moveCenter(QPoint(500,500));
        painter1.drawEllipse(h88);
        painter1.setBrush(QColor(20, 37, 80));
        QRect h888(0,0,10,10);
        h888.moveCenter(QPoint(500,500));
        painter1.drawEllipse(h888);

}
void MainWindow::MyTimerSlot(){
     this->repaint();
}
