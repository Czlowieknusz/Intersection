//
// Created by janek on 31.05.19.
//

#include "Car.h"

Car::~Car() = default;

void Car::move(int x, int y) {

}

Car::Car(int coordX, int coordY, bool isVertical) : coord_X(coordX), coord_Y(coordY), isVertical(isVertical) {

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
