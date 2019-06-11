//
// Created by janek on 08.06.19.
//

#include "Mover.h"

// tutaj logika wykrywająca czy top czy bottom itd. albo templatka
void Mover::moveCars(std::list<std::shared_ptr<Car>> &cars) {
    for (auto car = cars.begin(); car != cars.end(); ++car) {
        switch (car->get()->getDirection()) {
            case Direction::TOP:
                car->get()->moveUp();
                break;
            case Direction::BOTTOM:
                car->get()->moveDown();
                break;
            case Direction::LEFT:
                if (checkIfFreeToMove(car, cars)) {
                    car->get()->moveLeft();
                }
                break;
            case Direction::RIGHT:
                car->get()->moveRight();
                break;
        }
    }
    checkIfIntersectionClear(cars);
}

bool Mover::checkIfFreeToMove(std::list<std::shared_ptr<Car>>::iterator car, std::list<std::shared_ptr<Car>> &cars) {
    switch (car->get()->getDirection()) {
        case Direction::TOP:
            return true;
        case Direction::BOTTOM:
            return true;
        case Direction::LEFT:
            if (not isSubordinatedClear and car->get()->getCoordY() == intersectionFromRight - 1) {
                return false;
            } else if (car->get()->getCoordY() >= intersectionFromRight) {
                if (car == cars.begin()) {
                    return true;
                } else if (car->get()->getCoordY() >= std::prev(car, 1)->get()->getCoordY() + 8) {
                    return true;
                }
            }
            return true;
        case Direction::RIGHT:
            return true;
    }
}

void Mover::checkIfIntersectionClear(std::list<std::shared_ptr<Car>> &cars) {
    for (auto &car : cars) {
        if (car->getCoordY() < intersectionFromRight and car->getCoordY() > intersectionFromLeft
            and car->getCoordX() < intersectionFromBottom and car->getCoordX() > intersectionFromTop) {
            if (car->getDirection() == Direction::RIGHT or car->getDirection() == Direction::LEFT) {
                isMainClear = false;
                return;
            } else {
                isSubordinatedClear = false;
                return;
            }
        }
    }
    if (not cars.empty()) {
        if (cars.begin()->get()->getDirection() == Direction::RIGHT or
            cars.begin()->get()->getDirection() == Direction::LEFT) {
            isMainClear = true;
            return;
        } else {
            isSubordinatedClear = true;
            return;
        }
    }
}
