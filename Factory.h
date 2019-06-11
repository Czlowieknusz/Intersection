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
#include <condition_variable>
#include <thread>

class Factory {
    std::list<std::thread> threadCars;
    std::list<std::shared_ptr<Car>> topCars_;
    std::list<std::shared_ptr<Car>> bottomCars_;
    std::list<std::shared_ptr<Car>> leftCars_;
    std::list<std::shared_ptr<Car>> rightCars_;
    std::list<std::shared_ptr<Car>> cars_;
    std::shared_ptr<Animator> animator_;
    std::shared_ptr<Mover> mover_;
    std::shared_ptr<DirectionGenerator> directionGenerator_;
    std::mutex factoryMutex;
    std::condition_variable conditionVariable;
    bool isEndOfProgram;

    void checkIfEnd();

    void moverLoop();

    void animationLoop();

    void carLoop(std::list<std::shared_ptr<Car>>::iterator &car, std::list<std::shared_ptr<Car>> &cars);

    void createCar();

public:
    Factory();
};


#endif //INTERSECTION_FACTORY_H
