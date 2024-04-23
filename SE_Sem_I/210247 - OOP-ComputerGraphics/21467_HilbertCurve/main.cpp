#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include <QPushButton>
#include "mainwindow.h"
#include "./mainwindow.ui"

QImage img(500,500,QImage::Format_RGB888);

QColor color = Qt::yellow;
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;
    window.setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    // Create a QLabel to display the image
    QLabel *label = new QLabel(&window);
    label->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    // Create a QPushButton to draw the curve
    QPushButton *button = new QPushButton("Draw Hilbert Curve", &window);
    button->setGeometry(0, 0, 150, 30);

    // Connect the button's clicked signal to a slot that draws the curve
    QObject::connect(button, &QPushButton::clicked, [&]() {
        // Clear the image
        img.fill(Qt::white);

        // Draw the Hilbert curve
        int depth = 5; // Change this value to increase/decrease the curve's complexity
        drawHilbertCurve(img, {0, 0}, WINDOW_WIDTH, WINDOW_HEIGHT, depth, color.rgb());

        // Display the image in the label
        QPixmap pixmap = QPixmap::fromImage(img);
        ui->lbl_canvas->setPixmap(pixmap);
    });

    window.show();

    return app.exec();
}
