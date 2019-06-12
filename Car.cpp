//
// Created by janek on 31.05.19.
//

#include "Car.h"

Car::~Car() = default;

void Car::move(std::shared_ptr<Car> &prevCar) {
    switch (direction_) {
        case Direction::TOP:
            if (checkIfFreeToMove(prevCar)) {
                moveUp();
            }
            break;
        case Direction::BOTTOM:
            if (checkIfFreeToMove(prevCar)) {
                moveDown();
            }
            break;
        case Direction::LEFT:
            moveLeft();
            break;
        case Direction::RIGHT:
            moveRight();
            break;
    }
}

bool Car::checkIfFreeToMove(std::shared_ptr<Car> &prevCar) {
    switch (direction_) {
        case Direction::TOP:
            if (coord_X >= intersectionFromBottom) {
                if (coord_X >= prevCar->getCoordX() + 4) {
                    return true;
                } else if (coord_X < prevCar->getCoordX() + 4) {
                    return false;
                }
            }
            return true;
        case Direction::BOTTOM:
            if (coord_X <= intersectionFromTop) {
                if (coord_X <= prevCar->coord_X - 4) {
                    return true;
                } else if (coord_X > prevCar->coord_X - 4) {
                    return false;
                }
            }
            return true;
        default:
            return true;
    }
}

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

Car::Car(int sizeX, int sizeY, Direction direction) : direction_(direction) {
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