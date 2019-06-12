//
// Created by janek on 08.06.19.
//

#ifndef INTERSECTION_MOVER_H
#define INTERSECTION_MOVER_H


#include "Car.h"
#include <list>
#include <memory>

class Mover {
public:

    int intersectionFromLeft = 33, intersectionFromRight = 44, intersectionFromTop = 10, intersectionFromBottom = 16;
    bool isLeftCenter = false, isRightCenter = false;

    void checkIfIntersectionClear(std::list<std::shared_ptr<Car>> &cars);
};


#endif //INTERSECTION_MOVER_H
