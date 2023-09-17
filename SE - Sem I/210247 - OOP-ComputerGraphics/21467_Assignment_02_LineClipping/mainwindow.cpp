#include "mainwindow.h"
#include "./ui_mainwindow.h"

QImage img(500,500,QImage::Format_RGB888);

//Window Coordinates

int Xmin = 125;
int Ymin = 100;
int Xmax = 350;
int Ymax = 250;

//Region Codes:

const int INSIDE = 0;
const int TOP = 8;
const int BOT = 4;
const int RIGHT = 2;
const int LEFT = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    drawWindow();
    ui->lbl_canvas->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//plotpixel
void MainWindow:: plotPixel(int x,int y){
    img.setPixel(x,y,qRgb(0,255,0));
}
//dda line
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
        y = y+ yinc;

        plotPixel(x,y);
    }
}

//
void MainWindow::drawWindow(){
    dda_line(Xmin,Ymin,Xmin,Ymax);
    dda_line(Xmin,Ymin,Xmax,Ymin);
    dda_line(Xmax,Ymin,Xmax,Ymax);
    dda_line(Xmin,Ymax,Xmax,Ymax);
}
int MainWindow::compute_code(int x,int y){
    int code = INSIDE;

    if(x<Xmin){
        code |= LEFT;
    }
    if(x>Xmax){
        code |= RIGHT;
    }
    if(y<Ymin){
        code |=TOP;
    }
    if(y>Ymax){
        code |= BOT;
    }

    return code;
}

void MainWindow::on_btn_drawline_clicked()
{
    float x1 = ui->te_x1->toPlainText().toFloat();
    float y1 = ui->te_y1->toPlainText().toFloat();
    float x2 = ui->te_x2->toPlainText().toFloat();
    float y2 = ui->te_y2->toPlainText().toFloat();

    dda_line(x1,y1,x2,y2);
    ui->lbl_canvas->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::clearCanvas(){
    img.fill(qRgb(0,0,0));
    drawWindow();
    ui->lbl_canvas->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::cohenSutherlandLineClip(float x1, float y1, float x2, float y2){
    //Calculate code for boath endpoint
    int code1 = compute_code(x1,y1);
    int code2 = compute_code(x2,y2);

    qDebug()<<"C1"<<code1<<"C2"<<code2;

    //Declare aa flag
    bool accept = false;

    while(true){
        if((code1==0)&&(code2==0)){
            accept = true;
            break; //Line is inside
        }else if(code1 & code2){
            break; //As line is outside
        }else{
            //Now line is partially inside select otside poit

            int out_code;
            int x,y;

            if(code1!=0){
                out_code = code1;
            }else{
                out_code = code2;
            }

            qDebug()<<out_code;

            //Now find the intersection points

            if(out_code & TOP){
                y = Ymin;
                x = x1 +(x2-x1)*(y-y1)/(y2-y1);
            }else if(out_code & BOT){
                y = Ymax;
                x = x1 +(x2-x1)*(y-y1)/(y2-y1);
            }else if(out_code & RIGHT){
                x = Xmax;
                y = y1+(y2-y1)*(x-x1)/(x2-x1);
            }else if(out_code & LEFT){
                x = Xmin;
                y = y1+(y2-y1)*(x-x1)/(x2-x1);
            }

            if(out_code==code1){
                x1 = x;
                y1 = y;
                code1 = compute_code(x1,y1);
            }else{
                x2 = x;
                y2 = y;
                code2 = compute_code(x2,y2);
            }
        }
    }

    if(accept){
        clearCanvas();
        qDebug()<<x1<<y1<<x2<<y2<<"CoOrdinate";
        dda_line(x1,y1,x2,y2);
        ui->lbl_canvas->setPixmap(QPixmap::fromImage(img));
    }


}

void MainWindow::on_btn_clipline_clicked()
{
    float x1 = ui->te_x1->toPlainText().toFloat();
    float y1 = ui->te_y1->toPlainText().toFloat();
    float x2 = ui->te_x2->toPlainText().toFloat();
    float y2 = ui->te_y2->toPlainText().toFloat();

    cohenSutherlandLineClip(x1, y1, x2, y2);
}


void MainWindow::on_btn_clear_clicked()
{
    clearCanvas();
}

