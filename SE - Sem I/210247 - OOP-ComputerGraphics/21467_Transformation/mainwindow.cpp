#include "mainwindow.h"
#include "./ui_mainwindow.h"


QImage img(600,600,QImage::Format_RGB888);
QColor color = Qt::white;

//Static Object Cordinates
int num_c = 3;
int x_ver[] = {30,30,100};
int y_ver[] = {100,30,30};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    drawAxis();
    drawTriangle(x_ver,y_ver);
    ui->lbl_canvas->setPixmap(QPixmap::fromImage(img));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::plotPixel(int x, int y){
    img.setPixel(x,y,color.rgb());
}

void MainWindow::dda_line(float x1,float y1,float x2,float y2){
    float dx= x2-x1;
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
        plotPixel(x,y);
    }
}

void MainWindow::drawAxis(){
    dda_line(0,300,600,300);
    dda_line(300,0,300,600);
}


void MainWindow::drawTriangle(int xver[],int yver[]){
    dda_line(xver[0]+300,300-yver[0],xver[1]+300,300-yver[1]);
    dda_line(xver[1]+300,300-yver[1],xver[2]+300,300-yver[2]);
    dda_line(xver[0]+300,300-yver[0],xver[2]+300,300-yver[2]);
    ui->lbl_canvas->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::Translate(int tx, int ty){

    int tx_ver[num_c];
    int ty_ver[num_c];

    for(int i = 0;i<num_c;i++){
        tx_ver[i] = x_ver[i]+tx;
        ty_ver[i] = y_ver[i]+ty;
    }
    drawTriangle(tx_ver,ty_ver);
}

void MainWindow::Scale(int sx, int sy){

    int sx_ver[num_c];
    int sy_ver[num_c];

    for(int i = 0;i<num_c;i++){
        sx_ver[i] = x_ver[i]*sx;
        sy_ver[i] = y_ver[i]*sy;
    }
    drawTriangle(sx_ver,sy_ver);
}

void MainWindow::Rotate(float theta){
    int rx_ver[num_c];
    int ry_ver[num_c];

    theta = theta*3.14/180;
    for(int i=0;i<num_c;i++){
        float x = x_ver[i];
        float y = y_ver[i];

        rx_ver[i] = x*cos(theta)-y*sin(theta);
        ry_ver[i] = x*sin(theta)+y*cos(theta);

    }
    drawTriangle(rx_ver,ry_ver);
}
void MainWindow::on_btn_draw_obj_clicked()
{
    drawTriangle(x_ver,y_ver);
}


void MainWindow::on_btn_translate_clicked()
{
    float tx = ui->te_tx->toPlainText().toFloat();
    float ty = ui->te_ty->toPlainText().toFloat();

    Translate(tx,ty);
}


void MainWindow::on_btn_scale_clicked()
{
    float sx = ui->te_sx->toPlainText().toFloat();
    float sy = ui->te_sy->toPlainText().toFloat();

    Scale(sx,sy);
}


void MainWindow::on_btn_clear_clicked()
{
    img.fill(qRgb(0,0,0));

    drawAxis();
    drawTriangle(x_ver,y_ver);
}


void MainWindow::on_btn_rotate_clicked()
{
    float theta = ui->te_ra->toPlainText().toFloat();
    Rotate(theta);
}

