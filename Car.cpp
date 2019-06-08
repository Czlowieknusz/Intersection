//
// Created by janek on 31.05.19.
//

#include "Car.h"

Car::~Car() = default;

void Car::move(int x, int y) {

}

Car::Car(int coordX, int coordY, bool isVertical) : coord_X(coordX), coord_Y(coordY), isVertical(isVertical),
                                                    direction(Direction::TOP) {}

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