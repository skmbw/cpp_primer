//
// Created by yinlei on 2021/5/14.
//

#ifndef CPP_PRIMER_SHAPE_H
#define CPP_PRIMER_SHAPE_H

#include <iostream>
#include <cmath>

double fl(double t, int n) {
    double m = pow(10, n);
    double result = floor(t * m + 0.5) / m;
    return result;
}

double round(double x) {
    return fl(x, 2);
}

class Shape {
public:
    void printArea() {};
};

class Circle: Shape {
public:
    Circle() = default;
    Circle(const double radio): radio(radio) {}

    double radio = 0;
    void printArea() {
        std::cout << round(M_PI * radio * radio) << std::endl;
    }
};

class Rectangle: Shape {
public:
    Rectangle() = default;
    Rectangle(const double length, const double width): length(length), width(width) {}

    double length = 0;
    double width = 0;

    void printArea() {
        std::cout << round(length * width) << std::endl;
    }
};

class Triangle: Shape {
public:
    // 构造函数
    Triangle() = default;
    Triangle(const double bottom, const double height): bottom(bottom), height(height) {}

    // 属性
    double bottom = 0;
    double height = 0;

    // 打印面积的成员函数
    void printArea() {
        std::cout << round(bottom * height / 2) << std::endl;
    }
};
#endif //CPP_PRIMER_SHAPE_H
