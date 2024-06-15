#include "movableShape.h"

MovableShape::MovableShape(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
    : Shape(x1, y1, x2, y2, x3, y3, x4, y4) {
    initialX1 = x1;
    initialY1 = y1;
    initialX2 = x2;
    initialY2 = y2;
    initialX3 = x3;
    initialY3 = y3;
    initialX4 = x4;
    initialY4 = y4;
    centerX = (x1 + x2 + x3 + x4) / 4;
    centerY = (y1 + y2 + y3 + y4) / 4;
}

void MovableShape::displayParameters() {
    std::cout << "Coordinates of the vertices:" << std::endl;
    std::cout << "(" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << "), (" << x4 << ", " << y4 << ")" << std::endl;
    std::cout << "The center of the figure: (" << centerX << ", " << centerY << ")" << std::endl;
}

bool MovableShape::isPointOnBoundary(int x, int y, double tolerance) {
    double distance1 = sqrt(pow(x1 - x, 2) + pow(y1 - y, 2));
    double distance2 = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
    double distance3 = sqrt(pow(x3 - x, 2) + pow(y3 - y, 2));
    double distance4 = sqrt(pow(x4 - x, 2) + pow(y4 - y, 2));
    return (distance1 <= tolerance || distance2 <= tolerance || distance3 <= tolerance || distance4 <= tolerance);
}

bool MovableShape::intersectsXAxis() {
    return (y1 * y2 <= 0 || y2 * y3 <= 0 || y3 * y4 <= 0 || y4 * y1 <= 0);
}

bool MovableShape::intersectsYAxis() {
    return (x1 * x2 <= 0 || x2 * x3 <= 0 || x3 * x4 <= 0 || x4 * x1 <= 0);
}

bool MovableShape::isTrapezoidGeneral() {
    return !(isTrapezoidIsosceles() || isTrapezoidRectangular());
}

bool MovableShape::isTrapezoidIsosceles() {
    double distance12 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double distance34 = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
    return (abs(distance12 - distance34) < 0.001);
}

bool MovableShape::isTrapezoidRectangular() {
    return (abs(atan2(y2 - y1, x2 - x1) - atan2(y4 - y3, x4 - x3)) < 0.001);
}

void MovableShape::moveTo(int newCenterX, int newCenterY) {
    int dx = newCenterX - centerX;
    int dy = newCenterY - centerY;
    x1 += dx;
    y1 += dy;
    x2 += dx;
    y2 += dy;
    x3 += dx;
    y3 += dy;
    x4 += dx;
    y4 += dy;
    centerX = newCenterX;
    centerY = newCenterY;
}

void MovableShape::resetPosition() {
    x1 = initialX1;
    y1 = initialY1;
    x2 = initialX2;
    y2 = initialY2;
    x3 = initialX3;
    y3 = initialY3;
    x4 = initialX4;
    y4 = initialY4;
    centerX = (x1 + x2 + x3 + x4) / 4;
    centerY = (y1 + y2 + y3 + y4) / 4;
}