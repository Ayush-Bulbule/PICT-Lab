#include "mainwindow.h"
#include "./ui_mainwindow.h"

QImage img(500,500,QImage::Format_RGB888);


float x_,y_,r;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->lbl_canvas->setPixmap(QPixmap::fromImage(img));
//    dda_line(50,50,300,300);
//    BCircle(200,200,100);


}

MainWindow::~MainWindow()
{
    delete ui;
}

//Method 1: Plot Pixel
void MainWindow::plotPixel(int x,int y){
   img.setPixel(x,y,qRgb(0,255,0));
}
//DDALine
void MainWindow::dda_line(float x1,float y1,float x2, float y2){
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
        plotPixel(x,y);
        x = x+xinc;
        y = y+yinc;
    }
}

//Bresenham Circle
void MainWindow::BCircle(float p, float q, float r){
    float d,x,y;

    d = 3-2*r;

    x = 0;
    y = r;

    while(x<y){
        img.setPixel(x+p, y+q,qRgb(255,0,0));
        img.setPixel(y+p, x+q,qRgb(0,255,0));
        img.setPixel(-y+p, x+q,qRgb(0,0,255));
        img.setPixel(-x+p, y+q,qRgb(0,255,0));
        img.setPixel(-x+p, -y+q,qRgb(255,0,0));
        img.setPixel(-y+p, -x+q,qRgb(0,255,0));
        img.setPixel(y+p, -x+q,qRgb(0,0,255));
        img.setPixel(x+p, q-y,qRgb(0,255,0));


        if(d<0){
            d = d + 4*x+6;
            x = x+1;
        }else{
            d = d+4*(x-y)+10;
            x = x+1;
            y = y-1;
        }
    }


    ui->lbl_canvas->setPixmap(QPixmap::fromImage(img));
}
//Clear Function
void MainWindow::clearCanvas(){
    img.fill(qRgb(0,0,0));
}

//Triangle Cordinates
void MainWindow::Triangle(float x1, float y1,float x2, float y2,float x3, float y3){
    dda_line(x1,y1,x2,y2);
    dda_line(x2,y2,x3,y3);
    dda_line(x1,y1,x3,y3);

    ui->lbl_canvas->setPixmap(QPixmap::fromImage(img));
}


//Button CLicks
void MainWindow::on_btn_circle_clicked()
{
    r = ui->te_r->toPlainText().toFloat();
    x_ = ui->te_x->toPlainText().toFloat();

    y_ = ui->te_y->toPlainText().toFloat();

    BCircle(x_,y_,r);

}

void MainWindow::on_btn_triangle_clicked()
{
    // Formula for calculating the side of equilateral triangle inscribed in triangle
       int side = sqrt(3)*r;

       int ty1 = y_ - r;

       int ty2 = y_+(r/2);

       //to get lower-right coordinate of triangle
       int tx2 = x_+(side/2);

       //to get lower-left coordinate of triangle
       int tx3 = x_-(side/2);


       Triangle(x_,ty1,tx2,ty2,tx3,ty2);
}



void MainWindow::on_btn_incircle_clicked()
{
     BCircle(x_,y_,(r/2));
}


void MainWindow::on_btn_clear_clicked()
{
    clearCanvas();
}

