//
// Created by janek on 08.06.19.
//

#ifndef INTERSECTION_MOVER_H
#define INTERSECTION_MOVER_H


#include "Car.h"
#include <list>
#include <memory>

class Mover {
    int intersectionFromLeft = 33, intersectionFromRight = 44, intersectionFromTop = 10, intersectionFromBottom = 16;

    bool checkIfFreeToMove(std::list<std::shared_ptr<Car>>::iterator car, std::list<std::shared_ptr<Car>> &cars);

public:
    void moveCars(std::list<std::shared_ptr<Car>> &cars);
};


#endif //INTERSECTION_MOVER_H
