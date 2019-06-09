//
// Created by janek on 08.06.19.
//

#ifndef INTERSECTION_MOVER_H
#define INTERSECTION_MOVER_H


#include "Car.h"
#include <list>
#include <memory>

class Mover {
    bool checkIfFreeToMove();
public:
    void moveCars(std::list<std::shared_ptr<Car>> &cars);
};


#endif //INTERSECTION_MOVER_H
