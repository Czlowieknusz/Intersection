//
// Created by janek on 08.06.19.
//

#include "Mover.h"

// tutaj logika wykrywająca czy top czy bottom itd. albo templatka
void Mover::moveCars(std::list<std::shared_ptr<Car>> &cars) {
    for (auto car = cars.begin(); car != cars.end(); ++car) {
        switch (car->get()->getDirection()) {
            case Direction::TOP:
                car->get()->moveUp();
                break;
            case Direction::BOTTOM:
                car->get()->moveDown();
                break;
            case Direction::LEFT:
                if (checkIfFreeToMove(car, cars)) {
                    car->get()->moveLeft();
                }
                break;
            case Direction::RIGHT:
                car->get()->moveRight();
                break;
        }
    }
}

bool Mover::checkIfFreeToMove(std::list<std::shared_ptr<Car>>::iterator car, std::list<std::shared_ptr<Car>> &cars) {
    switch (car->get()->getDirection()) {
        case Direction::TOP:
            return true;
        case Direction::BOTTOM:
            return true;
        case Direction::LEFT:
            if (car->get()->getCoordY() > intersectionFromRight) {
                if (car == cars.begin()) {
                    return true;
                } else if (car->get()->getCoordY() < std::prev(car, 1)->get()->getCoordY() + 4) {
//                    car->get()->setCoordY(std::prev(car, 1)->get()->getCoordY() - 1);
  //                  car->get()->setCoordX(std::prev(car, 1)->get()->getCoordX() - 1);
                    return false;
                }
            }
            return false;
        case Direction::RIGHT:
            return true;
    }
}
