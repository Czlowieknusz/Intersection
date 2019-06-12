//
// Created by janek on 08.06.19.
//

#include "Mover.h"

// tutaj logika wykrywająca czy top czy bottom itd. albo templatka
void Mover::moveCars(std::list<std::shared_ptr<Car>> &cars) {
//    for (auto car = cars.begin(); car != cars.end(); ++car) {
//        switch (car->get()->getDirection()) {
//            case Direction::TOP:
//                if (checkIfFreeToMove(car, cars)) {
//                    car->get()->moveUp();
//                }
//                break;
//            case Direction::BOTTOM:
//                if (checkIfFreeToMove(car, cars)) {
//                    car->get()->moveDown();
//                }
//                break;
//            case Direction::LEFT:
//                if (checkIfFreeToMove(car, cars)) {
//                    car->get()->moveLeft();
//                }
//                break;
//            case Direction::RIGHT:
//                if (checkIfFreeToMove(car, cars)) {
//                    car->get()->moveRight();
//                }
//                break;
//        }
//    }
    checkIfIntersectionClear(cars);
}

bool Mover::checkIfFreeToMove(std::list<std::shared_ptr<Car>>::iterator car, std::list<std::shared_ptr<Car>> &cars) {
    switch (car->get()->getDirection()) {
        case Direction::TOP:
            if ((isLeftCenter or isRightCenter) and car->get()->getCoordX() == intersectionFromBottom + 1) {
                return false;
            } else if (car->get()->getCoordX() >= intersectionFromBottom) {
                if (car == cars.begin()) {
                    return true;
                } else if (car->get()->getCoordX() >= std::prev(car, 1)->get()->getCoordX() + 4) {
                    return true;
                } else if (car->get()->getCoordX() < std::prev(car, 1)->get()->getCoordX() + 4) {
                    return false;
                }
            }
            return true;
        case Direction::BOTTOM:
            if ((isLeftCenter or isRightCenter) and car->get()->getCoordX() == intersectionFromTop - 3) {
                return false;
            } else if (car->get()->getCoordX() <= intersectionFromTop) {
                if (car == cars.begin()) {
                    return true;
                } else if (car->get()->getCoordX() <= std::prev(car, 1)->get()->getCoordX() - 4) {
                    return true;
                } else if (car->get()->getCoordX() > std::prev(car, 1)->get()->getCoordX() - 4) {
                    return false;
                }
            }
            return true;
        case Direction::LEFT:
            if ((isTopCenter or isBottomCenter) and car->get()->getCoordY() == intersectionFromRight + 1) {
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
            if ((isTopCenter or isBottomCenter) and car->get()->getCoordY() == intersectionFromLeft - 4) {
                return false;
            } else if (car->get()->getCoordY() <= intersectionFromLeft - 4) {
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
        } else if (car->getDirection() == Direction::TOP) {
            if (car->getCoordX() < intersectionFromBottom and car->getCoordX() > intersectionFromTop) {
                isTopCenter = true;
                return;
            }
        } else {
            if (car->getCoordX() < intersectionFromBottom and car->getCoordX() > intersectionFromTop) {
                isBottomCenter = true;
                return;
            }
        }
    }
    if (not cars.empty()) {
        if (cars.begin()->get()->getDirection() == Direction::RIGHT) {
            isRightCenter = false;
        } else if (cars.begin()->get()->getDirection() == Direction::LEFT) {
            isLeftCenter = false;
        } else if (cars.begin()->get()->getDirection() == Direction::TOP) {
            isTopCenter = false;
        } else {
            isBottomCenter = false;
        }
    }
    if (not isRightCenter and not isLeftCenter) {

    }
}
