//
// Created by janek on 31.05.19.
//

#include "Animator.h"
#include <ncurses.h>
#include <unistd.h>
#include <iostream>

void Animator::initScreen() {
    initscr();
    curs_set(0);
    getmaxyx(stdscr, size_X, size_Y);
}

Animator::Animator() : size_X(0), size_Y(0) {
    initScreen();
}

/*
 *
 * C = animateSquare(0, 0, 2, 15);
 * __________________________________________> Y
 * |
 * |
 * | (C)|||||||||||||
 * |    |||||||||||||
 * |
 * |
 * |  (10, 2)
 * |   X
 * |
 * |
 * |
 * |
 * \/
 * X
 *
 *
 *     mvprintw(10, 33, "c");
    mvprintw(10, 43, "c");
    mvprintw(15, 33, "c");
    mvprintw(15, 43, "c");
 */

void Animator::animateSquares() {
    attron(COLOR_PAIR(1));
    animateSquare(0, 0, 10, 33);
    animateSquare(0, 44, 10, size_Y);
    animateSquare(16, 0, size_X, 33);
    animateSquare(16, 44, size_X, size_Y);
}

void Animator::animateIntersection() {
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_RED);
    init_pair(4, COLOR_BLACK, COLOR_BLACK);
    animateRoad();
    animateSquares();
    animateRoadMarking();
}

Animator::~Animator() {
    endwin();
}

void Animator::animateSquare(int startX, int startY, int endX, int endY) {
    for (int i = startX; i < endX; ++i) {
        wmove(stdscr, i, startY);
        for (int j = startY; j < endY; ++j) {
            addstr(" ");
        }
    }
}

void Animator::animateRoadMarking() {
    attron(COLOR_PAIR(2));
    move(12, 0);
    for (int i = 0; i < 33 / 2 + 1; ++i) {
        addstr("_ ");
    }

    move(12, 44);
    for (int i = 0; i < 33 / 2 + 2; ++i) {
        addstr("_ ");
    }

    for (int i = 0; i < 10; ++i) {
        mvaddstr(0 + i, 38, "|");
    }

    for (int i = 0; i < 10; ++i) {
        mvaddstr(16 + i, 38, "|");
    }
    move(9, 33);
    for (int i = 0; i < 3; ++i) {
        addstr("_ ");
    }

    move(15, 39);
    for (int i = 0; i < 3; ++i) {
        addstr("_ ");
    }
}

void Animator::animateCars(std::list<std::shared_ptr<Car>> &cars) {
//    const std::string RcordX = std::to_string(cars.rbegin()->get()->getCoordX());
//    const std::string RcordY = std::to_string(cars.rbegin()->get()->getCoordY());
//    mvaddstr(15, 20, RcordX.c_str());
//    mvaddstr(15, 22, RcordY.c_str());
//    const std::string cordX = std::to_string(cars.front()->getCoordX());
//    const std::string cordY = std::to_string(cars.front()->getCoordY());
//    mvaddstr(20, 20, cordX.c_str());
//    mvaddstr(22, 22, cordY.c_str());
    attron(COLOR_PAIR(3));

    for (const auto &car : cars) {
        animateCar(car);
    }
}

void Animator::animateCar(const std::shared_ptr<Car> &car) {
    switch (car->getDirection()) {
        case Direction::TOP:
        case Direction::BOTTOM:
            mvaddstr(car->getCoordX(), car->getCoordY(), "|");
            mvaddstr(car->getCoordX(), car->getCoordY() + 1, "|");
            mvaddstr(car->getCoordX() + 1, car->getCoordY(), "|");
            mvaddstr(car->getCoordX() + 1, car->getCoordY() + 1, "|");
            break;
        case Direction::LEFT:
        case Direction::RIGHT:
            mvaddstr(car->getCoordX(), car->getCoordY(), "|");
            mvaddstr(car->getCoordX(), car->getCoordY() + 1, "|");
            mvaddstr(car->getCoordX(), car->getCoordY() + 2, "|");
            mvaddstr(car->getCoordX(), car->getCoordY() + 3, "|");
            break;
    }
}

void Animator::animate(std::list<std::shared_ptr<Car>> &cars) {
    animateCars(cars);
    refresh();
}

/*
 *     attron(COLOR_PAIR(1));
    animateSquare(0, 0, 10, 33);
    animateSquare(0, 44, 10, size_Y);
    animateSquare(16, 0, size_X, 33);
    animateSquare(16, 44, size_X, size_Y);
 */

void Animator::animateRoad() {
    attron(COLOR_PAIR(4));
    for (int j = 0; j < size_X; ++j) {
        move(j, 33);
        for (int i = 0; i < 11; ++i) {
            addstr("_");
        }
    }
    for (int j = 10; j < 16; ++j) {
        move(j, 0);
        for (int i = 0; i < size_Y; ++i) {
            addstr("_");
        }
    }
}

int Animator::getSizeX() const {
    return size_X;
}

int Animator::getSizeY() const {
    return size_Y;
}
