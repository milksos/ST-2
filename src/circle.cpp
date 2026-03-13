// Copyright 2022 UNN-CS
#include <cmath>
#include "circle.h"

const double PI = 3.14159265358979323846;

Circle::Circle(double radius) {
    setRadius(radius);
}

void Circle::setRadius(double radius) {
    if (radius < 0) radius = 0;
    radius_ = radius;
    updateFromRadius();
}

void Circle::setFerence(double ference) {
    if (ference < 0) ference = 0;
    ference_ = ference;
    updateFromFerence();
}

void Circle::setArea(double area) {
    if (area < 0) area = 0;
    area_ = area;
    updateFromArea();
}

double Circle::getRadius() const {
    return radius_;
}

double Circle::getFerence() const {
    return ference_;
}

double Circle::getArea() const {
    return area_;
}

void Circle::updateFromRadius() {
    ference_ = 2 * PI * radius_;
    area_ = PI * radius_ * radius_;
}

void Circle::updateFromFerence() {
    radius_ = ference_ / (2 * PI);
    area_ = PI * radius_ * radius_;
}

void Circle::updateFromArea() {
    radius_ = std::sqrt(area_ / PI);
    ference_ = 2 * PI * radius_;
}
