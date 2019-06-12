//
// Created by janek on 31.05.19.
//

#include "Factory.h"
#include <unistd.h>
#include <iostream>
#include <ncurses.h>

Factory::Factory() : cars_({}),
                     animator_(std::make_shared<Animator>()),
                     mover_(std::make_shared<Mover>(std::ref(conditionVariable))),
                     isEndOfProgram(false), directionGenerator_(std::make_shared<DirectionGenerator>()) {
    std::thread animateThread([this]() { animationLoop(); });
    std::thread moverThread([this]() { moverLoop(); });
    std::thread worldEnder([this]() { checkIfEnd(); });

    while (not isEndOfProgram) {
        // tu wytwarzamy auta
        auto car = std::make_shared<Car>(animator_->getSizeX(), animator_->getSizeY(),
                                         directionGenerator_->getRandom());
        switch (car->getDirection()) {
            case Direction::TOP: {
                createCar(bottomCars_, car);
                break;
            }
            case Direction::BOTTOM: {
                createCar(topCars_, car);
                break;
            }
            case Direction::LEFT: {
                createCar(rightCars_, car);
                break;
            }
            case Direction::RIGHT: {
                createCar(leftCars_, car);
                break;
            }
        }
        usleep(900000);
    }
    animateThread.join();
    moverThread.join();
    worldEnder.join();
    for (auto &thread : threadCars) {
        thread.join();
    }
}

void Factory::checkIfEnd() {
    while (not isEndOfProgram) {
        if (getch()) {
            isEndOfProgram = true;
            exit(1);
        }
    }
}

void Factory::moverLoop() {
    while (not isEndOfProgram) {
        usleep(100000);
        std::lock_guard<std::mutex> lockGuard(factoryMutex);
//        mover_->moveCars(topCars_);
        //      mover_->moveCars(bottomCars_);
        mover_->checkIfIntersectionClear(leftCars_);
        mover_->checkIfIntersectionClear(rightCars_);
        // Tutaj dodać resztę list i zastąpić ogólną
    }
}

// petla ma wywolywac funkcje, reszta ma miec miejsce wewnatrz
void Factory::animationLoop() {
    while (not isEndOfProgram) {
        usleep(50000);
        animator_->animateIntersection();
        std::lock_guard<std::mutex> lockGuard(factoryMutex);
//        animator_->animate(cars_);
        animator_->animate(topCars_);
        animator_->animate(bottomCars_);
        animator_->animate(leftCars_);
        animator_->animate(rightCars_);
    }
}

void Factory::createCar(std::list<std::shared_ptr<Car>> &cars, std::shared_ptr<Car> &car) {
    cars.push_back(std::move(car));
    auto &mainCar = *std::prev(cars.end(), 1);
    if (mainCar == *cars.begin()) {
        std::thread threadCar([&mainCar, this]() { carLoop(std::ref(mainCar)); });
        threadCars.push_back(std::move(threadCar));
    } else {
        auto &prevCar = *std::prev(cars.end(), 2);
        std::thread threadCar([&mainCar, &prevCar, this]() { carLoop(std::ref(mainCar), std::ref(prevCar)); });
        threadCars.push_back(std::move(threadCar));
    }
}

void Factory::carLoop(std::shared_ptr<Car> &car, std::shared_ptr<Car> &prevCar) {
    while (not isEndOfProgram) {
        usleep(100000);
        if (mover_->isLeftCenter or mover_->isRightCenter) {
            if (car->getDirection() == Direction::BOTTOM and car->getCoordX() == intersectionFromBottom + 1) {
                std::unique_lock<std::mutex> mlock(factoryMutex);
                conditionVariable.wait(mlock);
            }
            if (car->getDirection() == Direction::TOP and car->getCoordX() == intersectionFromTop - 3) {
                std::unique_lock<std::mutex> mlock(factoryMutex);
                conditionVariable.wait(mlock);
            }
        }
        car->move(prevCar);
    }
}

void Factory::carLoop(std::shared_ptr<Car> &car) {
    while (not isEndOfProgram) {
        usleep(100000);
        if (mover_->isLeftCenter or mover_->isRightCenter) {
            if (car->getDirection() == Direction::BOTTOM and car->getCoordX() == intersectionFromBottom + 1) {
                std::unique_lock<std::mutex> mlock(factoryMutex);
                conditionVariable.wait(mlock);
            }
            if (car->getDirection() == Direction::TOP and car->getCoordX() == intersectionFromTop - 3) {
                std::unique_lock<std::mutex> mlock(factoryMutex);
                conditionVariable.wait(mlock);
            }
        }
        car->move();
    }
}
/*
 *     // Acquire the lock
    std::unique_lock<std::mutex> mlock(m_mutex);
    // Start waiting for the Condition Variable to get signaled
    // Wait() will internally release the lock and make the thread to block
    // As soon as condition variable get signaled, resume the thread and
    // again acquire the lock. Then check if condition is met or not
    // If condition is met then continue else again go in wait.
    m_condVar.wait(mlock, std::bind(&Application::isDataLoaded, this));
 */