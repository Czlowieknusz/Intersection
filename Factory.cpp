//
// Created by janek on 31.05.19.
//

#include "Factory.h"
#include <unistd.h>
#include <iostream>
#include <thread>
#include <ncurses.h>

Factory::Factory() : cars_({std::make_shared<Car>(2, 2, false)}),
                     animator_(std::make_shared<Animator>(cars_)),
                     isEndOfProgram(false) {
    std::thread animateThread(&Animator::animationLoop, animator_);
//    std::thread worldEnder(&Factory::checkIfEnd, this);
    while (not isEndOfProgram) {

    }
    animateThread.join();
    //   worldEnder.join();
    //cars_.emplace_back(std::make_shared<Car>(2, 2));
}

void Factory::checkIfEnd() {
    while (not isEndOfProgram) {
        if (getch()) {
            isEndOfProgram = true;
        }
    }
}

void Factory::moverLoop() {
    while (not isEndOfProgram) {
        for (auto &car : cars_) {
            usleep(100000);
            std::lock_guard<std::mutex> lockGuard(factoryMutex);
            car->moveRight();
        }
    }
}
