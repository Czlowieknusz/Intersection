//
// Created by janek on 31.05.19.
//

#include "Car.h"

Car::~Car() = default;

void Car::move(int x, int y) {

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