//
// Created by janek on 08.06.19.
//

#include "Mover.h"

void Mover::checkIfIntersectionClear(std::list<std::shared_ptr<Car>> &cars) {
    for (auto &car : cars) {
        if (car->getDirection() == Direction::RIGHT) {
            if (car->getCoordY() < intersectionFromRight + 8 and car->getCoordY() > intersectionFromLeft - 8) {
                isRightCenter = true;
                return;
            }
        } else if (car->getDirection() == Direction::LEFT) {
            if (car->getCoordY() < intersectionFromRight + 8 and car->getCoordY() > intersectionFromLeft - 8) {
                isLeftCenter = true;
                return;
            }
        }
    }
    if (not cars.empty()) {
        if (cars.begin()->get()->getDirection() == Direction::RIGHT) {
            isRightCenter = false;
        } else if (cars.begin()->get()->getDirection() == Direction::LEFT) {
            isLeftCenter = false;
        }
    }
}
