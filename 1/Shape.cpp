//
// Created by yinlei on 2021/5/14.
//

#include "Shape.h"

int main() {
//    int x = 999;
//    int countx = 0;
//    while (x) {
//        countx++;
//        x = x & (x - 1);
//    }
//    std::cout<< countx << std::endl;
    double radio = 0;

    double rect_height = 0;
    double rect_width = 0;

    double tri_bottom = 0;
    double tri_height = 0;

    std::cin >> radio >> rect_height >> rect_width >> tri_bottom >> tri_height;

    // 以下是使用引用，来进行C++的虚方法的多态调用
    Circle rc(radio);
    Shape &circle = rc;
    circle.printArea();

    Rectangle rect(rect_height, rect_width);
    Shape &rectangle = rect;
    rectangle.printArea();

    Triangle angle(tri_bottom, tri_height);
    Shape &triangle = angle;
    triangle.printArea();

    // 以下是使用指针来进行C++的虚方法的多态调用
//    Shape *shape;
//
//    shape = &rc;
//    shape->printArea();
//
//    shape = &rect;
//    shape->printArea();
//
//    shape = &angle;
//    shape->printArea();
}