#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include<QMouseEvent>
#include<QColorDialog>

QImage img(500,500,QImage::Format_RGB888);
QColor color = Qt::yellow;

int verticesX[20];
int verticesY[20];
int numVerticesIndex = 0;
int numvertices;
float slopes[20];

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

void MainWindow::plotPixel(int x,int y){
    img.setPixel(x,y,color.rgb());

}

//void
void MainWindow::dda_line(float x1, float y1, float x2,float y2){
    float dx = x2-x1;
    float dy = y2-y1;

    float steps = abs(dx);
    if(abs(dy)>abs(dx)){
        steps = abs(dy);
    }

    float xinc = dx/steps;
    float yinc = dy/steps;

    float x = x1;
    float y=y1;

    for(int i = 0;i<steps;i++){
        x = x+xinc;
        y = y+yinc;
        plotPixel(x,y);
    }
    ui->label->setPixmap(QPixmap::fromImage(img));

}

//Mouse Eventr
void MainWindow::mousePressEvent(QMouseEvent* e){
    int x = e->pos().x();
    int y = e->pos().y();

    plotPixel(x,y);
    qDebug()<<x<<y;

    if(x>500||y>500){
        return;
    }

    if(e->button()==Qt::RightButton){
        verticesX[numVerticesIndex] = verticesX[0];
        verticesY[numVerticesIndex] = verticesY[0];

        dda_line(verticesX[numVerticesIndex-1],verticesY[numVerticesIndex-1],verticesX[0],verticesY[0]);

        numvertices = numVerticesIndex;
    }else{
        verticesX[numVerticesIndex] = x;
        verticesY[numVerticesIndex] = y;

        if(numVerticesIndex>0){
            dda_line(verticesX[numVerticesIndex-1],verticesY[numVerticesIndex-1],x,y);
        }
        numVerticesIndex++;
    }


    ui->label->setPixmap(QPixmap::fromImage(img));
}



void MainWindow::on_pushButton_clicked()
{

    //calculate ymin
    float ymin = 10000.0f;
    for(int i=0;i<numvertices;i++){

        if(verticesY[i]<ymin){
            ymin = verticesY[i];
        }

    }

    //calculate ymax
    float ymax = 0.f;
    for(int i=0;i<numvertices;i++){

        if(verticesY[i]>ymax){
            ymax = verticesY[i];
        }

    }

    qDebug()<<ymin<<ymax;
    //calculate slopes
    for(int i = 0;i<numvertices;i++){
        float dx = verticesX[i+1] - verticesX[i];
        float dy = verticesY[i+1] - verticesY[i];

        if(dx==0){
            slopes[i] = 1.0f;
        }else{
            slopes[i] = dy/dx;
        }
    }

    //check cordinates
    for(int i =0;i<numvertices;i++){
        qDebug()<<verticesX[i]<<verticesY[i]<<slopes[i];
    }

    //Actually scan for lines
    for(int y = ymin;y<ymax;y++){

        //find out active edges
        qDebug()<<"Nu"<<numvertices;
        float x_inter[numvertices];
        int activeEdges = 0;

        for(int i = 0;i<numvertices;i++){
            //claculate min line and max line
            float yMinLine = std::min(verticesY[i],verticesY[i+1]);
            float yMaxLine = std::max(verticesY[i],verticesY[i+1]);

            qDebug()<<yMinLine<<yMaxLine<<y;
            qDebug()<<(yMinLine<y && (y<=yMaxLine));

            if(yMinLine<y && y<=yMaxLine){
                qDebug()<<"hi"<<verticesX[ i ];
                          qDebug()<<slopes[i] ;
                                    qDebug()<<( y - verticesY[i] );
                        x_inter[ activeEdges ] = verticesX[ i ] + ( ( 1 / slopes[i] ) * ( y - verticesY[i] )  ) ;
                        qDebug()<<"Line:"<<x_inter[activeEdges]<<y;
                        activeEdges++;
                    }

        }

        for(int i =0;i<numvertices;i++){
            for(int j = 0;j<numvertices-i-1;j++){
                if(x_inter[j]>x_inter[j+1]){
                    float temp = x_inter[j];
                    x_inter[j] = x_inter[j+1];
                    x_inter[j+1] = temp;

                }
            }
        }




        //for draw line
        for(int i = 0;i<activeEdges;i+=2){
            qDebug()<<x_inter[i]<<x_inter[i];
            dda_line(x_inter[i],y,x_inter[i+1]+1,y);
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    color = QColorDialog::getColor();
}

