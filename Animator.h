//
// Created by janek on 31.05.19.
//

#ifndef INTERSECTION_ANIMATOR_H
#define INTERSECTION_ANIMATOR_H


#include <list>
#include <memory>
#include <queue>
#include "Car.h"

class Animator {
public:
    void initScreen();

    void animateIntersection();

    void animateSquare(int startX, int startY, int endX, int endY);

    void animateSquares();

    void animateRoadMarking();

    void animateRoad();

    int getSizeX() const;

    int getSizeY() const;

    void animateCars(std::list<std::shared_ptr<Car>> &cars);

    void animateCar(const std::shared_ptr<Car> &car);

    void animateCar(const int);
    void animate(std::list<std::shared_ptr<Car>> &cars);

    int size_X, size_Y;

    Animator();

    virtual ~Animator();

    void animationLoop();
};


#endif //INTERSECTION_ANIMATOR_H
