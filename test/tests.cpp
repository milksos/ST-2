// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>

#include <cmath>

#include "circle.h"
#include "tasks.h"

const double PI = 3.14159265358979323846;
const double EPSILON = 1e-10;

TEST(CircleTest, ConstructorTest) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 25.0);
}

TEST(CircleTest, ConstructorZeroTest) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, ConstructorNegativeTest) {
    Circle c(-5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetRadiusTest) {
    Circle c(0);
    c.setRadius(3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 3.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 9.0);
}

TEST(CircleTest, SetRadiusNegativeTest) {
    Circle c(5.0);
    c.setRadius(-2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetRadiusUpdateTest) {
    Circle c(5.0);
    c.setRadius(10.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 10.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 100.0);
}

TEST(CircleTest, SetFerenceTest) {
    Circle c(0);
    double f = 2 * PI * 4.0;
    c.setFerence(f);
    EXPECT_NEAR(c.getRadius(), 4.0, EPSILON);
    EXPECT_DOUBLE_EQ(c.getFerence(), f);
    EXPECT_NEAR(c.getArea(), PI * 16.0, EPSILON);
}

TEST(CircleTest, SetFerenceZeroTest) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetFerenceNegativeTest) {
    Circle c(5.0);
    c.setFerence(-10.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetFerenceLargeTest) {
    Circle c(0);
    double f = 1000.0;
    c.setFerence(f);
    EXPECT_NEAR(c.getRadius(), f / (2 * PI), EPSILON);
    EXPECT_DOUBLE_EQ(c.getFerence(), f);
}

TEST(CircleTest, SetAreaTest) {
    Circle c(0);
    double a = PI * 25.0;
    c.setArea(a);
    EXPECT_NEAR(c.getRadius(), 5.0, EPSILON);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 5.0, EPSILON);
    EXPECT_DOUBLE_EQ(c.getArea(), a);
}

TEST(CircleTest, SetAreaZeroTest) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetAreaNegativeTest) {
    Circle c(5.0);
    c.setArea(-100.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetAreaLargeTest) {
    Circle c(0);
    double a = 1000.0;
    c.setArea(a);
    EXPECT_NEAR(c.getRadius(), std::sqrt(a / PI), EPSILON);
    EXPECT_DOUBLE_EQ(c.getArea(), a);
}

TEST(CircleTest, SetRadiusAfterSetFerenceTest) {
    Circle c(5.0);
    c.setFerence(100.0);
    c.setRadius(3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 3.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 9.0);
}

TEST(CircleTest, SetFerenceAfterSetAreaTest) {
    Circle c(5.0);
    c.setArea(PI * 16.0);
    c.setFerence(2 * PI * 5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, EPSILON);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 5.0);
    EXPECT_NEAR(c.getArea(), PI * 25.0, EPSILON);
}

TEST(CircleTest, ConsistencyTest) {
    Circle c(7.0);
    double r = c.getRadius();
    double f = c.getFerence();
    double a = c.getArea();
    EXPECT_DOUBLE_EQ(f, 2 * PI * r);
    EXPECT_DOUBLE_EQ(a, PI * r * r);
}

TEST(TasksTest, EarthRopeGapPositive) {
    double gap = calculateEarthRopeGap();
    EXPECT_GT(gap, 0.0);
}

TEST(TasksTest, EarthRopeGapValue) {
    double gap = calculateEarthRopeGap();
    EXPECT_NEAR(gap, 1.0 / (2 * PI), 1e-6);
}

TEST(TasksTest, EarthRopeGapReasonable) {
    double gap = calculateEarthRopeGap();
    EXPECT_LT(gap, 1.0);
    EXPECT_GT(gap, 0.1);
}

TEST(TasksTest, PoolCostPositive) {
    double cost = calculatePoolCost();
    EXPECT_GT(cost, 0.0);
}

TEST(TasksTest, PoolCostValue) {
    double cost = calculatePoolCost();
    EXPECT_NEAR(cost, 72256.0, 100.0);
}

TEST(TasksTest, PoolCostComponents) {
    Circle pool(3.0);
    Circle outer(4.0);
    double pathArea = outer.getArea() - pool.getArea();
    double concreteCost = pathArea * 1000.0;
    double fenceCost = outer.getFerence() * 2000.0;
    double totalCost = concreteCost + fenceCost;
    EXPECT_DOUBLE_EQ(totalCost, calculatePoolCost());
}
TEST(CircleTest, VerySmallRadiusTest) {
    Circle c(1e-10);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e-10);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 1e-10, 1e-20);
    EXPECT_NEAR(c.getArea(), PI * 1e-20, 1e-30);
}

TEST(CircleTest, VeryLargeRadiusTest) {
    Circle c(1e10);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e10);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 1e10, 1e-5);
    EXPECT_NEAR(c.getArea(), PI * 1e20, 1e5);
}

TEST(CircleTest, SetFerenceVerySmallTest) {
    Circle c(0);
    c.setFerence(1e-10);
    EXPECT_NEAR(c.getRadius(), 1e-10 / (2 * PI), 1e-20);
}

TEST(CircleTest, SetAreaVerySmallTest) {
    Circle c(0);
    c.setArea(1e-20);
    EXPECT_NEAR(c.getRadius(), std::sqrt(1e-20 / PI), 1e-15);
}
