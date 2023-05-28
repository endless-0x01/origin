#include "square.h"

Square::Square(Point p1, Point p2, Point p3, Point p4)
    : p1(p1), p2(p2), p3(p3), p4(p4) {}

ShapeType Square::getType() const {
    return ShapeType::square;
}

void Square::shift(int dx, int dy, int dz) {
    p1.x += dx; p1.y += dy;
    p2.x += dx; p2.y += dy;
    p3.x += dx; p3.y += dy;
    p4.x += dx; p4.y += dy;
}

void Square::scaleX(int s) {
    p1.x *= s; p2.x *= s; p3.x *= s; p4.x *= s;
}

void Square::scaleY(int s) {
    p1.y *= s; p2.y *= s; p3.y *= s; p4.y *= s;
}

void Square::scaleZ(int s) {
    p1.z *= s; p2.z *= s; p3.z *= s; p4.z *= s;
}

void Square::scale(int s) {
    scaleX(s); scaleY(s);
}
