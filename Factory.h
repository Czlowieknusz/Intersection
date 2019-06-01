//
// Created by janek on 31.05.19.
//

#ifndef INTERSECTION_FACTORY_H
#define INTERSECTION_FACTORY_H

#include "Animator.h"
#include "Car.h"
#include <list>
#include <memory>

class Factory {
    std::list<std::shared_ptr<Car>> cars_;
    std::shared_ptr<Animator> animator_;
public:
    Factory();
};


#endif //INTERSECTION_FACTORY_H
