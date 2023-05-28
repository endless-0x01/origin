#pragma once

enum class ShapeType {
    line,
    square,
    cube
};

class Shape {
public:
    virtual ~Shape() = default;
    virtual ShapeType getType() const = 0;
    virtual void shift(int dx, int dy, int dz = 0) = 0;
    virtual void scaleX(int s) = 0;
    virtual void scaleY(int s) = 0;
    virtual void scaleZ(int s) = 0;
    virtual void scale(int s) = 0;
};
