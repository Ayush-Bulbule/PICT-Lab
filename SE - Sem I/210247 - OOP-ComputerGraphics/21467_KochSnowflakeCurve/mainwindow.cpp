#include "mainwindow.h"
#include "./ui_mainwindow.h"


QImage img(500,500,QImage::Format_RGB888);
QColor color = Qt::yellow;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::plotpixel(int x, int y){
    img.setPixel(x,y,color.rgb());
}


void MainWindow::dda_line(float x1, float y1, float x2, float y2){
    float dx = x2-x1;
    float dy = y2-y1;

    float steps = abs(dx);
    if(abs(dy)>abs(dx)){
        steps = abs(dy);
    }
    float xinc = dx/steps;
    float yinc = dy/steps;

    float x = x1;
    float y = y1;

    for(int i = 0;i<steps;i++){
        x = x+xinc;
        y = y+yinc;
        plotpixel(x,y);
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::koch(int it, int x1,int y1, int x5,int y5){
    int x2,y2,x3,y3,x4,y4;
    int dx,dy;

    if(it == 0){
        dda_line(x1,y1,x5,y5);

    }else{
        dx = (x5-x1)/3;
        dy = (y5-y1)/3;

        x2 = x1+dx;
        y2 = y1+dy;

        x3 = (int) (0.5*(x1+x5) + sqrt(3)*(y1-y5)/6);
        y3 = (int)(0.5*(y1+y5)+sqrt(3)*(x5-x1)/6);

        x4 = 2*dx+x1;
        y4 = 2*dy+y1;

        qDebug()<<x1<<y1<<x2<<y2<<x3<<y3<<x4<<y4<<x5<<y5;
        koch(it-1,x1,y1,x2,y2);
        koch(it-1,x2,y2,x3,y3);
        koch(it-1,x3,y3,x4,y4);
        koch(it-1,x4,y4,x5,y5);
    }
}

void MainWindow::on_pushButton_clicked()
{
    int it = ui->textEdit->toPlainText().toInt();

    koch(it,150,20,20,280);
    koch(it,280,280,150,20);
    koch(it,20,280,280,280);


    ui->label->setPixmap(QPixmap::fromImage(img));
}

