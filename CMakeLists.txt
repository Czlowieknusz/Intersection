cmake_minimum_required(VERSION 3.14)
project(Intersection)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

find_package(Curses REQUIRED)
include_directories(/usr/include)

add_executable(Intersection main.cpp Factory.cpp Factory.h Animator.cpp Animator.h Car.cpp Car.h Mover.cpp Mover.h Direction.h DirectionGenerator.cpp DirectionGenerator.h)
target_link_libraries(Intersection ${CURSES_LIBRARIES})