//
// Created by janek on 09.06.19.
//

#ifndef INTERSECTION_DIRECTIONGENERATOR_H
#define INTERSECTION_DIRECTIONGENERATOR_H


#include <random>
#include "Direction.h"

class DirectionGenerator {
    std::mt19937 m_generator;
    std::uniform_int_distribution<int> m_distribution;

public:
    DirectionGenerator();
    Direction getRandom();
};


#endif //INTERSECTION_DIRECTIONGENERATOR_H
