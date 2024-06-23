#include "shape.h"

Shape::Shape(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->x3 = x3;
    this->y3 = y3;
    this->x4 = x4;
    this->y4 = y4;
}

void Shape::displayParameters() {
    std::cout << "Coordinates of the vertices:" << std::endl;
    std::cout << "(" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << "), (" << x4 << ", " << y4 << ")" << std::endl;
}

bool Shape::isPointOnBoundary(int x, int y, double tolerance) {
    double distance1 = sqrt(pow(x1 - x, 2) + pow(y1 - y, 2));
    double distance2 = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
    double distance3 = sqrt(pow(x3 - x, 2) + pow(y3 - y, 2));
    double distance4 = sqrt(pow(x4 - x, 2) + pow(y4 - y, 2));
    return (distance1 <= tolerance || distance2 <= tolerance || distance3 <= tolerance || distance4 <= tolerance);
}

bool Shape::intersectsXAxis() {
    return (y1 * y2 <= 0 || y2 * y3 <= 0 || y3 * y4 <= 0 || y4 * y1 <= 0);
}

bool Shape::intersectsYAxis() {
    return (x1 * x2 <= 0 || x2 * x3 <= 0 || x3 * x4 <= 0 || x4 * x1 <= 0);
}

bool Shape::isTrapezoidGeneral() {
    return !(isTrapezoidIsosceles() || isTrapezoidRectangular());
}

bool Shape::isTrapezoidIsosceles() {
    double distance12 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double distance34 = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
    return (abs(distance12 - distance34) < 0.001);
}

bool Shape::isTrapezoidRectangular() {
    return (abs(atan2(y2 - y1, x2 - x1) - atan2(y4 - y3, x4 - x3)) < 0.001);
}
