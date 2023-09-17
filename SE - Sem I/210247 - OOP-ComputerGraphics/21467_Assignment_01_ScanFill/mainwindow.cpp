#include "mainwindow.h"
#include "./ui_mainwindow.h"


#include <QImage>
#include <QMouseEvent>
#include <QTime>

QImage img = QImage(500,500,QImage::Format_RGB888);

float verticesX[10]; //To store x-coordinate of vertices
float verticesY[10]; //To store y-coordinate of vertices

int numVertices = 0;
int numVerticesIndex = 0;

float slopes[10]; //To store calculated slopes


float temp;

//Main
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

//Method 1 -  To Plot Pixel on Screen
void MainWindow::plotPixel(int x,int y){
    img.setPixel(x,y,qRgb(0,255,0));
}

//Method 2 - To Draw Line
void MainWindow::dda_line(float x1,float y1,float x2,float y2){

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

    for(int i=0;i<=steps;i++){
        x += xinc;
        y += yinc;
        plotPixel(x,y);
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

//Method 3 - Handle MousePress Event
void MainWindow::mousePressEvent(QMouseEvent* event){
    int x = event->pos().x();
    int y = event->pos().y();

    qDebug()<<x<<y;

    plotPixel(x,y);

    if(x>500||y>500){
        return;
    }

    if(event->button()==Qt::RightButton){
        verticesX[numVerticesIndex] = verticesX[0];
        verticesY[numVerticesIndex] = verticesY[0];

        dda_line(verticesX[numVerticesIndex-1],verticesY[numVerticesIndex-1],verticesX[0],verticesY[0]);
        numVertices = numVerticesIndex;
    }else{

        verticesX[numVerticesIndex] = x;
        verticesY[numVerticesIndex] = y;

        qDebug()<<"x1: "<<verticesX[numVerticesIndex-1]<<verticesX[numVerticesIndex];
        qDebug()<<"y1:"<<verticesY[numVerticesIndex-1]<<verticesY[numVerticesIndex];

        if(numVerticesIndex>0){
            qDebug()<<"Hi";
            dda_line(verticesX[numVerticesIndex-1],verticesY[numVerticesIndex-1],x,y);
        }
        numVerticesIndex++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}

//Method 4 - Delay
void delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(100);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
}

//Method 5 - To scan fill the polygon on pressing button
void MainWindow::on_pushButton_clicked()
{
  for(int i = 0;i<numVertices;i++){
      qDebug()<<"x:"<<verticesX[i];
      qDebug()<<"y:"<<verticesY[i];
  }

  //Calculate ymin - Min Y in all vertices
  float ymin = 1000.0f;
  for(float y:verticesY){
      if(y<ymin && y!=0){
          ymin = y;
      }
  }
  qDebug()<<"Ymin: "<<ymin;

  //calculate ymax - Max Y in all vertices
  float ymax = 0.0f;
  for(float y:verticesY){
      if(y>ymax && y!=0){
          ymax = y;
      }
  }
  qDebug()<<"Ymax: "<<ymax;


  //Clculate slope for all edges
  for(int i = 0;i<numVertices;i++){
      float dx = verticesX[i+1]-verticesX[i];
      float dy = verticesY[i+1]-verticesY[i];
      qDebug()<<"dx:"<<dx;
      qDebug()<<"dy:"<<dy;

      if(dx==0){
          slopes[i] = 1.0f;
      }else{
          slopes[i] = dy/dx;
      }
      qDebug()<<"Slopes:"<<slopes[i];
  }

  //Scan lines from ymin to ymax
  for(int y = ymin;y<ymax;y++){
      //array of active edges
      float  x_inter[numVertices];
      int activeEdges = 0;

      //calculate smaller and larger y coordinate
      for(int i = 0;i<numVertices;i++){
        float yMinLine = std::min(verticesY[i],verticesY[i+1]);
        float yMaxLine = std::max(verticesY[i],verticesY[i+1]);

        if(yMinLine<y && y<=yMaxLine){
            x_inter[ activeEdges ] = verticesX[ i ] + ( ( 1 / slopes[i] ) * ( y - verticesY[i] )  ) ;
            qDebug()<<"Line:"<<x_inter[activeEdges]<<y;
            activeEdges++;
        }

      }

      // Sort x_inter with bubble sort
      for( int i = 0 ; i < activeEdges ; i++ ) {
          for( int j = 0 ; j < activeEdges - i - 1 ; j++ ) {
              if( x_inter[j] > x_inter[j+1] ) {
                  int temp = x_inter[j] ;
                  x_inter[j] = x_inter[j+1] ;
                  x_inter[j+1] = temp ;
              }
          }
      }
      //Finally draw all scan line intersections
      for(int i = 0;i<activeEdges;i+=2){
          delay();
          dda_line(x_inter[i],y,x_inter[i+1]+1,y);
      }
  }
}



