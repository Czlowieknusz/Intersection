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
                     isEndOfProgram(false) {
    std::thread animateThread([this]() { animationLoop(); });
    std::thread moverThread([this]() { moverLoop(); });
 //   std::thread worldEnder([this]() { checkIfEnd(); });

    cars_.emplace_back(std::make_shared<Car>(0, 35, false));
    while (not isEndOfProgram) {
        // tu wytwarzamy auta
    }
    animateThread.join();
    moverThread.join();
 //   worldEnder.join();
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
        usleep(500000);
        std::lock_guard<std::mutex> lockGuard(factoryMutex);
        mover_->moveCars(cars_);
        // Tutaj dodać resztę list i zastąpić ogólną
    }
}

// petla ma wywolywac funkcje, reszta ma miec miejsce wewnatrz
void Factory::animationLoop() {
    while (not isEndOfProgram) {
        usleep(500000);
        animator_->animateIntersection();
        std::lock_guard<std::mutex> lockGuard(factoryMutex);
        animator_->animate(cars_);
//        animator_->animate(topCars_);
 //       animator_->animate(bottomCars_);
  //      animator_->animate(leftCars_);
   //     animator_->animate(rightCars_);
    }
}

