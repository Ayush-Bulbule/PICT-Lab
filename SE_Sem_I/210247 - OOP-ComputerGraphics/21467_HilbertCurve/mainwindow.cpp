#include <QImage>
#include "mainwindow.h"

// Function to draw a line using the DDA algorithm
void drawLineDDA(QImage &image, Point p1, Point p2, QRgb color)
{
    // Calculate the difference between the two points
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;

    // Calculate the number of steps needed to draw the line
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate the increment in x and y for each step
    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    // Set the starting point
    float x = p1.x;
    float y = p1.y;

    // Draw the line
    for (int i = 0; i <= steps; i++)
    {
        image.setPixel(round(x), round(y), color);
        x += xIncrement;
        y += yIncrement;
    }
}

// Recursive function to draw a Hilbert curve

void drawHilbertCurve(QImage &image, Point p, int width, int height, int depth, QRgb color)
{
    // Base case: draw a line if the curve has reached the desired depth
    if (depth == 0)
    {
        drawLineDDA(image, p, {p.x + width, p.y}, color);
        return;
    }

    // Draw the four sub-curves of the Hilbert curve
    drawHilbertCurve(image, p, width / 2, height / 2, depth - 1, color);
    drawHilbertCurve(image, {p.x + width / 2, p.y}, width / 2, height / 2, depth - 1, color);
    drawHilbertCurve(image, {p.x + width / 2, p.y + height / 2}, width / 2, height / 2, depth - 1, color);
    drawHilbertCurve(image, {p.x, p.y + height / 2}, width / 2, height / 2, depth - 1, color);
}
