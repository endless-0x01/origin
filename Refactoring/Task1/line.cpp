#include "line.h"

Line::Line(Point p1, Point p2) : p1(p1), p2(p2) {}

ShapeType Line::getType() const {
    return ShapeType::line;
}

void Line::shift(int dx, int dy, int dz) {
    p1.x += dx; p1.y += dy;
    p2.x += dx; p2.y += dy;
}

void Line::scaleX(int s) {
    p1.x *= s; p2.x *= s;
}

void Line::scaleY(int s) {
    p1.y *= s; p2.y *= s;
}

void Line::scaleZ(int s) {
    p1.z *= s; p2.z *= s;
}

void Line::scale(int s) {
    scaleX(s); scaleY(s);
}
