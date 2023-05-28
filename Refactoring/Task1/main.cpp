#include <iostream>
#include "line.h"
#include "square.h"
#include "cube.h"

int main() {

    Line line(Point(0, 0), Point(1, 1));
    Square square(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
    Cube cube(Point(0, 0, 0), Point(1, 0, 0), Point(1, 1, 0), Point(0, 1, 0),
        Point(0, 0, 1), Point(1, 0, 1), Point(1, 1, 1), Point(0, 1, 1));


    std::cout << "Type of line: " << static_cast<int>(line.getType()) << std::endl;
    std::cout << "Type of square: " << static_cast<int>(square.getType()) << std::endl;
    std::cout << "Type of cube: " << static_cast<int>(cube.getType()) << std::endl;

    line.shift(1, 1);
    square.shift(1, 1);
    cube.shift(1, 1, 1);

    line.scale(2);
    square.scale(2);
    cube.scale(2);

    return 0;
}
