//
// Created by janek on 08.06.19.
//

#include "Mover.h"

// tutaj logika wykrywająca czy top czy bottom itd. albo templatka
void Mover::moveCars(std::list<std::shared_ptr<Car>> &cars) {
    for (auto car = cars.begin(); car != cars.end(); ++car) {
        switch (car->get()->getDirection()) {
            case Direction::TOP:
                if (checkIfFreeToMove(car, cars)) {
                    car->get()->moveUp();
                }
                break;
            case Direction::BOTTOM:
                if (checkIfFreeToMove(car, cars)) {
                    car->get()->moveDown();
                }
                break;
            case Direction::LEFT:
                if (checkIfFreeToMove(car, cars)) {
                    car->get()->moveLeft();
                }
                break;
            case Direction::RIGHT:
                if (checkIfFreeToMove(car, cars)) {
                    car->get()->moveRight();
                }
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
            if (not isSubordinatedClear and car->get()->getCoordY() == intersectionFromRight + 1) {
                return false;
            } else if (car->get()->getCoordY() >= intersectionFromRight) {
                if (car == cars.begin()) {
                    return true;
                } else if (car->get()->getCoordY() >= std::prev(car, 1)->get()->getCoordY() + 8) {
                    return true;
                } else if (car->get()->getCoordY() < std::prev(car, 1)->get()->getCoordY() + 8) {
                    return false;
                }
            }
            return true;
        case Direction::RIGHT:
//            if (car->get()->getCoordY() == intersectionFromLeft - 4)
//                return false;
            if (not isSubordinatedClear and car->get()->getCoordY() == intersectionFromLeft - 4) {
                return false;
            } else if (car->get()->getCoordY() <= intersectionFromLeft-4) {
                if (car == cars.begin()) {
                    return true;
                } else if (car->get()->getCoordY() <= std::prev(car, 1)->get()->getCoordY() - 8) {
                    return true;
                } else if (car->get()->getCoordY() > std::prev(car, 1)->get()->getCoordY() - 8) {
                    return false;
                }
            }
            return true;
    }
}
/*
 *
 * C = animateSquare(0, 0, 2, 15);
 * __________________________________________> Y
 * |
 * |
 * | (C)|||||||||||||
 * |    |||||||||||||
 * |
 * |
 * |  (10, 2)
 * |   X
 * |
 * |
 * |
 * |
 * \/
 * X
 */

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
