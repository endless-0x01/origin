#pragma once
#include "shape.h"
#include "point.h"

class Line : public Shape {
public:
    Line(Point p1, Point p2);
    ShapeType getType() const override;
    void shift(int dx, int dy, int dz = 0) override;
    void scaleX(int s) override;
    void scaleY(int s) override;
    void scaleZ(int s) override;
    void scale(int s) override;

private:
    Point p1, p2;
};
