//
// Created by janek on 08.06.19.
//

#ifndef INTERSECTION_MOVER_H
#define INTERSECTION_MOVER_H


#include "Car.h"
#include <list>
#include <memory>
#include <condition_variable>

class Mover {
public:
    explicit Mover(std::condition_variable conditionVariable);

    int intersectionFromLeft = 33, intersectionFromRight = 44, intersectionFromTop = 10, intersectionFromBottom = 16;
//    bool isMainClear = true, isSubordinatedClear = true;
    bool isLeftCenter = false, isRightCenter = false, isTopCenter = false, isBottomCenter = false;
    std::condition_variable &conditionVariable_;

    bool checkIfFreeToMove(std::list<std::shared_ptr<Car>>::iterator car, std::list<std::shared_ptr<Car>> &cars);

    void checkIfIntersectionClear(std::list<std::shared_ptr<Car>> &cars);

    void moveCars(std::list<std::shared_ptr<Car>> &cars);
};


#endif //INTERSECTION_MOVER_H
