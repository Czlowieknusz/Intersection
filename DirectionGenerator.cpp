//
// Created by janek on 09.06.19.
//

#include "DirectionGenerator.h"

DirectionGenerator::DirectionGenerator() :
        m_generator(std::random_device()()),
        m_distribution(0, 3) {}

Direction DirectionGenerator::getRandom() {
    switch (m_distribution(m_generator)) {
        case 0:
            return Direction::TOP;
        case 1:
            return Direction::BOTTOM;
        case 2:
            return Direction::LEFT;
        case 3:
            return Direction::RIGHT;
    }
}