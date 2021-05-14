//
// Created by yinlei on 2021/5/14.
//

#ifndef CPP_PRIMER_SHAPE_H
#define CPP_PRIMER_SHAPE_H

#include <iostream>
#include <cmath>

/**
 * 对double进行四舍五入，保留n位小数
 * @param t 待四舍五入的值
 * @param n 小数点后的位数
 * @return 按要求四舍五入后的值
 */
double fl(double t, int n) {
    double m = pow(10, n);
    double result = floor(t * m + 0.5) / m;
    return result;
}

// 如果使用round这个方法名，会覆盖cmath中的同名函数
double rd(double x) {
    return fl(x, 2);
}

class Shape {
public:
    virtual void printArea() {};
};

class Circle: public Shape {
public:
    Circle() = default;
    explicit Circle(const double radio): radio(radio) {}

    void printArea() override {
        std::cout << rd(M_PI * radio * radio) << std::endl;
    }

private:
    double radio = 0;
};

class Rectangle: public Shape {
public:
    Rectangle() = default;
    Rectangle(const double length, const double width): length(length), width(width) {}

    void printArea() override {
        std::cout << rd(length * width) << std::endl;
    }

private:
    double length = 0;
    double width = 0;
};

class Triangle: public Shape {
public:
    // 构造函数
    Triangle() = default;
    Triangle(const double bottom, const double height): bottom(bottom), height(height) {}

    // 打印面积的成员函数
    void printArea() override {
        std::cout << rd(bottom * height / 2) << std::endl;
    }

private:
    // 属性
    double bottom = 0;
    double height = 0;
};
#endif //CPP_PRIMER_SHAPE_H
