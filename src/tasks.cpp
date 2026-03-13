// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

const double EARTH_RADIUS_KM = 6378.1;
const double EARTH_RADIUS_M = EARTH_RADIUS_KM * 1000;
const double ADDED_ROPE = 1.0;

double calculateEarthRopeGap() {
    Circle earth(EARTH_RADIUS_M);
    double earthFerence = earth.getFerence();

    double newFerence = earthFerence + ADDED_ROPE;
    Circle newCircle(0);
    newCircle.setFerence(newFerence);

    return newCircle.getRadius() - earth.getRadius();
}

double calculatePoolCost() {
    const double POOL_RADIUS = 3.0;
    const double PATH_WIDTH = 1.0;
    const double CONCRETE_COST = 1000.0;
    const double FENCE_COST = 2000.0;
    Circle pool(POOL_RADIUS);
    Circle outerCircle(POOL_RADIUS + PATH_WIDTH);

    double pathArea = outerCircle.getArea() - pool.getArea();
    double concreteCost = pathArea * CONCRETE_COST;

    double fenceLength = outerCircle.getFerence();
    double fenceCost = fenceLength * FENCE_COST;
    return concreteCost + fenceCost;
}
