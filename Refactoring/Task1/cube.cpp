#include "cube.h"

Cube::Cube(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, Point p7, Point p8)
    : p1(p1), p2(p2), p3(p3), p4(p4), p5(p5), p6(p6), p7(p7), p8(p8) {}

ShapeType Cube::getType() const {
    return ShapeType::cube;
}

void Cube::shift(int dx, int dy, int dz) {
    p1.x += dx; p1.y += dy; p1.z += dz;
    p2.x += dx; p2.y += dy; p2.z += dz;
    p3.x += dx; p3.y += dy; p3.z += dz;
    p4.x += dx; p4.y += dy; p4.z += dz;
    p5.x += dx; p5.y += dy; p5.z += dz;
    p6.x += dx; p6.y += dy; p6.z += dz;
    p7.x += dx; p7.y += dy; p7.z += dz;
    p8.x += dx; p8.y += dy; p8.z += dz;
}

void Cube::scaleX(int s) {
    p1.x *= s; p2.x *= s; p3.x *= s; p4.x *= s;
    p5.x *= s; p6.x *= s; p7.x *= s; p8.x *= s;
}

void Cube::scaleY(int s) {
    p1.y *= s; p2.y *= s; p3.y *= s; p4.y *= s;
    p5.y *= s; p6.y *= s; p7.y *= s; p8.y *= s;
}

void Cube::scaleZ(int s) {
    p1.z *= s; p2.z *= s; p3.z *= s; p4.z *= s;
    p5.z *= s; p6.z *= s; p7.z *= s; p8.z *= s;
}

void Cube::scale(int s) {
    scaleX(s); scaleY(s); scaleZ(s);
}
