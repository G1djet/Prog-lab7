#include "shape.h"

class MovableShape : public Shape {
private:
    int initialX1, initialY1, initialX2, initialY2, initialX3, initialY3, initialX4, initialY4;
    int centerX, centerY;

public:
    MovableShape(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
    void displayParameters() override;
    bool isPointOnBoundary(int x, int y, double tolerance) override;
    bool intersectsXAxis() override;
    bool intersectsYAxis() override;
    bool isTrapezoidGeneral() override;
    bool isTrapezoidIsosceles() override;
    bool isTrapezoidRectangular() override;
    void moveTo(int newCenterX, int newCenterY);
    void resetPosition();
};