//
// Created by janek on 31.05.19.
//

#ifndef INTERSECTION_CAR_H
#define INTERSECTION_CAR_H

#include "Direction.h"

class Car {
    Direction direction;
    int coord_X, coord_Y;
    bool isVertical;

    void move(int x, int y);

public:
    int getCoordX() const;

    void setCoordX(int coordX);

    int getCoordY() const;

    void setCoordY(int coordY);

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    Car(int coordX, int coordY, bool isVertical);

    ~Car();
};


#endif //INTERSECTION_CAR_H
