//
// Created by yinlei on 2021/5/14.
//

#include "Shape.h"

int main() {
    double radio = 0;

    double rect_height = 0;
    double rect_width = 0;

    double tri_bottom = 0;
    double tri_height = 0;

    std::cin >> radio >> rect_height >> rect_width >> tri_bottom >> tri_height;

    Shape circle = Circle(radio);
    circle.printArea();

    Shape rectangle = Rectangle(rect_height, rect_width);
    rectangle.printArea();

    Shape triangle = Triangle(tri_bottom, tri_height);
    triangle.printArea();
}