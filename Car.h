//
// Created by janek on 31.05.19.
//

#ifndef INTERSECTION_CAR_H
#define INTERSECTION_CAR_H

#include <memory>
#include "Direction.h"

class Car {
    Direction direction_;
    int coord_X, coord_Y, intersectionFromTop = 10, intersectionFromBottom = 16;

public:
    bool checkIfFreeToMove(std::shared_ptr<Car> &prevCar);

    void move(std::shared_ptr<Car> &prevCar);

    bool checkIfFreeToMove();

    void move();

    int getCoordX() const;

    void setCoordX(int coordX);

    int getCoordY() const;

    void setCoordY(int coordY);

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    Car(int sizeX, int sizeY, Direction direction);

    Direction getDirection() const;

    ~Car();
};


#endif //INTERSECTION_CAR_H
