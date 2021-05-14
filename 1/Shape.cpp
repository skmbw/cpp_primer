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

    Circle rc(radio);
    Shape &circle = rc;
    circle.printArea();

    Rectangle rect(rect_height, rect_width);
    Shape &rectangle = rect;
    rectangle.printArea();

    Triangle angle(tri_bottom, tri_height);
    Shape &triangle = angle;
    triangle.printArea();
}