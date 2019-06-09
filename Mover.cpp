//
// Created by janek on 08.06.19.
//

#include "Mover.h"

// tutaj logika wykrywająca czy top czy bottom itd. albo templatka
void Mover::moveCars(std::list<std::shared_ptr<Car>> &cars) {
    for (auto &car: cars) {
        car->moveDown();
       // car->moveRight();
    }
}
