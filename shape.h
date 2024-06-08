#include <iostream>
#include <cmath>

class Shape {
protected:
    int x1, y1, x2, y2, x3, y3, x4, y4;

public:
    Shape(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
    virtual void displayParameters();
    virtual bool isPointOnBoundary(int x, int y, double tolerance);
    virtual bool intersectsXAxis();
    virtual bool intersectsYAxis();
    virtual bool isTrapezoidGeneral();
    virtual bool isTrapezoidIsosceles();
    virtual bool isTrapezoidRectangular();
};