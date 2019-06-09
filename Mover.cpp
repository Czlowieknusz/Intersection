//
// Created by janek on 08.06.19.
//

#include "Mover.h"

// tutaj logika wykrywająca czy top czy bottom itd. albo templatka
void Mover::moveCars(std::list<std::shared_ptr<Car>> &cars) {
    for (auto &car: cars) {
        switch (car->getDirection()) {
            case Direction::TOP:
                car->moveUp();
                break;
            case Direction::BOTTOM:
                car->moveDown();
                break;
            case Direction::LEFT:
                car->moveLeft();
                break;
            case Direction::RIGHT:
                car->moveRight();
                break;
        }
    }
}
