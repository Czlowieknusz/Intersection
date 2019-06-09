//
// Created by janek on 31.05.19.
//

#include "Factory.h"
#include <unistd.h>
#include <iostream>
#include <thread>
#include <ncurses.h>

Factory::Factory() : cars_({}),
                     animator_(std::make_shared<Animator>()), mover_(std::make_shared<Mover>()),
                     isEndOfProgram(false), directionGenerator_(std::make_shared<DirectionGenerator>()) {
    std::thread animateThread([this]() { animationLoop(); });
    std::thread moverThread([this]() { moverLoop(); });
    std::thread worldEnder([this]() { checkIfEnd(); });

    while (not isEndOfProgram) {
        // tu wytwarzamy auta
        createCar();
        usleep(5000000);
    }
    animateThread.join();
    moverThread.join();
    worldEnder.join();
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
        mover_->moveCars(topCars_);
        mover_->moveCars(bottomCars_);
        mover_->moveCars(leftCars_);
        mover_->moveCars(rightCars_);
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

void Factory::createCar() {
    auto car = std::make_shared<Car>(animator_->getSizeX(), animator_->getSizeY(), directionGenerator_->getRandom());
    switch (car->getDirection()) {
        case Direction::TOP:
            bottomCars_.push_back(car);
            break;
        case Direction::BOTTOM:
            topCars_.push_back(car);
            break;
        case Direction::LEFT:
            rightCars_.push_back(car);
            break;
        case Direction::RIGHT:
            leftCars_.push_back(car);
            break;
    }
}

