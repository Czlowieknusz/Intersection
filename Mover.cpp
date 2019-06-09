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
                car->get()->moveLeft();
                break;
            case Direction::RIGHT:
                car->get()->moveRight();
                break;
        }
    }
}

bool Mover::checkIfFreeToMove() {

    return false;
}
