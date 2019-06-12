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
#include "DirectionGenerator.h"
#include <thread>
#include <condition_variable>

class Factory {
    std::list<std::shared_ptr<Car>> topCars_;
    std::list<std::shared_ptr<Car>> bottomCars_;
    std::list<std::shared_ptr<Car>> leftCars_;
    std::list<std::shared_ptr<Car>> rightCars_;
    std::list<std::shared_ptr<Car>> cars_;
    std::list<std::thread> threadCars;
    std::shared_ptr<Animator> animator_;
    std::shared_ptr<Mover> mover_;
    std::shared_ptr<DirectionGenerator> directionGenerator_;
    std::condition_variable conditionVariable;
    std::mutex factoryMutex;
    int intersectionFromTop = 10, intersectionFromBottom = 16;
    bool isEndOfProgram;

    void checkIfEnd();

    void moverLoop();

    void animationLoop();

    void carLoop(std::shared_ptr<Car> &car, std::shared_ptr<Car> &prevCar);

    void carLoop(std::shared_ptr<Car> &car);

    void createCar(std::list<std::shared_ptr<Car>> &cars, std::shared_ptr<Car> &car);

public:
    Factory();
};


#endif //INTERSECTION_FACTORY_H
