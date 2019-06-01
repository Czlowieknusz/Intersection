//
// Created by janek on 31.05.19.
//

#include "Factory.h"
#include <unistd.h>
#include <iostream>
#include <thread>

Factory::Factory() : cars_({std::make_shared<Car>(2, 2, false)}),
                     animator_(std::make_shared<Animator>(cars_)) {
    std::thread animateThread(&Animator::animationLoop, animator_);
    if (cars_.empty())
        std::cout << "Dupencja";
    std::cout << "size = " << cars_.size();
    usleep(1500000);
    usleep(1500000);
    usleep(1500000);
    usleep(1500000);
    animateThread.join();
    //cars_.emplace_back(std::make_shared<Car>(2, 2));
}
