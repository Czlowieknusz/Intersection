//
// Created by janek on 31.05.19.
//

#include "Intersection.h"
#include <ncurses.h>
#include <unistd.h>

void Intersection::InitScreen() {
    initscr();
    curs_set(0);
    getmaxyx(stdscr, size_X, size_Y);
}

Intersection::Intersection() {
    InitScreen();
    usleep(1500000);
}
