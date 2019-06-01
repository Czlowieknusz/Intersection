//
// Created by janek on 31.05.19.
//

#ifndef INTERSECTION_ANIMATOR_H
#define INTERSECTION_ANIMATOR_H


#include <list>
#include <memory>
#include "Car.h"

class Animator {
    void initScreen();

    void animateIntersection();

    void animateSquare(int startX, int startY, int endX, int endY);

    void animateRoadMarking();

    void animateCars();

    void animateCar(const std::shared_ptr<Car> &car);

    int size_X, size_Y;
    std::list<std::shared_ptr<Car>> &cars_;
public:
    Animator(std::list<std::shared_ptr<Car>> &cars);

    virtual ~Animator();

    void animationLoop();
};


#endif //INTERSECTION_ANIMATOR_H
