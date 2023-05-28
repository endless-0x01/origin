#pragma once
#include "shape.h"
#include "point.h"

class Cube : public Shape {
public:
    Cube(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, Point p7, Point p8);
    ShapeType getType() const override;
    void shift(int dx, int dy, int dz) override;
    void scaleX(int s) override;
    void scaleY(int s) override;
    void scaleZ(int s) override;
    void scale(int s) override;

private:
    Point p1, p2, p3, p4, p5, p6, p7, p8;
};
