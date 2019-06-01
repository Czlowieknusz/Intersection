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

Animator::Animator(std::list<std::shared_ptr<Car>> &cars) : cars_(cars) {
    //  initScreen();
//    animationLoop();
}

void Animator::animationLoop() {
    animateIntersection();
    while (true) {
//        if (cars_.empty())
//            animateCars();
        refresh();
        usleep(500000);
    }
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

void Animator::animateIntersection() {
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    animateSquare(0, 0, 10, 33);
    animateSquare(0, 44, 10, size_Y);
    animateSquare(16, 0, size_X, 33);
    animateSquare(16, 44, size_X, size_Y);

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
    wmove(stdscr, 12, 0);
    for (int i = 0; i < 33 / 2 + 1; ++i) {
        addstr("_ ");
    }

    wmove(stdscr, 12, 44);
    for (int i = 0; i < 33 / 2 + 2; ++i) {
        addstr("_ ");
    }

    for (int i = 0; i < 10; ++i) {
        mvaddstr(0 + i, 38, "|");
    }

    for (int i = 0; i < 10; ++i) {
        mvaddstr(16 + i, 38, "|");
    }
}

void Animator::animateCars() {
//    for (const auto &car : cars_) {
//        animateCar(car);
//    }
}

void Animator::animateCar(const std::shared_ptr<Car> &car) {

}
