//
// Created by janek on 31.05.19.
//

#include "Car.h"

Car::~Car() = default;

void Car::move() {
    switch (direction_) {
        case Direction::TOP:
            moveUp();
            break;
        case Direction::BOTTOM:
            moveDown();
            break;
        case Direction::LEFT:
            moveLeft();
            break;
        case Direction::RIGHT:
            moveRight();
            break;
    }
}

Car::Car(int
         sizeX, int
         sizeY, Direction
         direction) : direction_(direction) {
    switch (direction_) {
        case Direction::TOP:
            coord_X = sizeX;
            coord_Y = 40;
            break;
        case Direction::BOTTOM:
            coord_X = -4;
            coord_Y = 35;
            break;
        case Direction::LEFT:
            coord_X = 11;
            coord_Y = sizeY;
            break;
        case Direction::RIGHT:
            coord_X = 14;
            coord_Y = 0;
            break;
    }
}

int Car::getCoordX() const {
    return coord_X;
}

void Car::setCoordX(int coordX) {
    coord_X = coordX;
}

int Car::getCoordY() const {
    return coord_Y;
}

void Car::setCoordY(int coordY) {
    coord_Y = coordY;
}

void Car::moveUp() {
    --coord_X;
}

void Car::moveDown() {
    ++coord_X;
}

void Car::moveLeft() {
    --coord_Y;
}

void Car::moveRight() {
    ++coord_Y;
}

Direction Car::getDirection() const {
    return direction_;
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

/*
 * To teraz tak -> tutaj sparawdzamy czy nie walnie w auto z przodu
 * Inna funkcja sprawdzi czy nie trzeba uśpić.
 */
//bool Car::checkIfFreeToMove(std::list<std::shared_ptr<Car>>::iterator car, std::list<std::shared_ptr<Car>> &cars) {
//    switch (car->get()->getDirection()) {
//        case Direction::TOP:
//            if ((isLeftCenter or isRightCenter) and car->get()->getCoordX() == intersectionFromBottom + 1) {
//                return false;
//            } else if (car->get()->getCoordX() >= intersectionFromBottom) {
//                if (car == cars.begin()) {
//                    return true;
//                } else if (car->get()->getCoordX() >= std::prev(car, 1)->get()->getCoordX() + 4) {
//                    return true;
//                } else if (car->get()->getCoordX() < std::prev(car, 1)->get()->getCoordX() + 4) {
//                    return false;
//                }
//            }
//            return true;
//        case Direction::BOTTOM:
//            if ((isLeftCenter or isRightCenter) and car->get()->getCoordX() == intersectionFromTop - 3) {
//                return false;
//            } else if (car->get()->getCoordX() <= intersectionFromTop) {
//                if (car == cars.begin()) {
//                    return true;
//                } else if (car->get()->getCoordX() <= std::prev(car, 1)->get()->getCoordX() - 4) {
//                    return true;
//                } else if (car->get()->getCoordX() > std::prev(car, 1)->get()->getCoordX() - 4) {
//                    return false;
//                }
//            }
//            return true;
//        case Direction::LEFT:
//            if ((isTopCenter or isBottomCenter) and car->get()->getCoordY() == intersectionFromRight + 1) {
//                return false;
//            } else if (car->get()->getCoordY() >= intersectionFromRight) {
//                if (car == cars.begin()) {
//                    return true;
//                } else if (car->get()->getCoordY() >= std::prev(car, 1)->get()->getCoordY() + 8) {
//                    return true;
//                } else if (car->get()->getCoordY() < std::prev(car, 1)->get()->getCoordY() + 8) {
//                    return false;
//                }
//            }
//            return true;
//        case Direction::RIGHT:
//            if ((isTopCenter or isBottomCenter) and car->get()->getCoordY() == intersectionFromLeft - 4) {
//                return false;
//            } else if (car->get()->getCoordY() <= intersectionFromLeft - 4) {
//                if (car == cars.begin()) {
//                    return true;
//                } else if (car->get()->getCoordY() <= std::prev(car, 1)->get()->getCoordY() - 8) {
//                    return true;
//                } else if (car->get()->getCoordY() > std::prev(car, 1)->get()->getCoordY() - 8) {
//                    return false;
//                }
//            }
//            return true;
//    }
//}