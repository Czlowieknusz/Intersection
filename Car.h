//
// Created by janek on 31.05.19.
//

#ifndef INTERSECTION_CAR_H
#define INTERSECTION_CAR_H

#include "Direction.h"
#include <list>
#include <memory>

class Car {
    Direction direction_;
    int coord_X, coord_Y;


public:
    bool checkIfFreeToMove(std::list<std::shared_ptr<Car>>::iterator car, std::list<std::shared_ptr<Car>> &cars);
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
