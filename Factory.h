//
// Created by janek on 31.05.19.
//

#ifndef INTERSECTION_FACTORY_H
#define INTERSECTION_FACTORY_H

#include "Animator.h"
#include "Car.h"
#include <list>
#include <memory>
#include <mutex>
#include <queue>
#include "Mover.h"

class Factory {
    std::queue<std::shared_ptr<Car>> topCars_;
    std::queue<std::shared_ptr<Car>> bottomCars_;
    std::queue<std::shared_ptr<Car>> leftCars_;
    std::queue<std::shared_ptr<Car>> rightCars_;
    std::list<std::shared_ptr<Car>> cars_;
    std::shared_ptr<Animator> animator_;
    Mover mover;
    std::mutex factoryMutex;
    bool isEndOfProgram;

    void checkIfEnd();

    void moverLoop();

    void createCar();

public:
    Factory();
};


#endif //INTERSECTION_FACTORY_H
