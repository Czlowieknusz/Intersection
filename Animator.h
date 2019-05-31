//
// Created by janek on 31.05.19.
//

#ifndef INTERSECTION_ANIMATOR_H
#define INTERSECTION_ANIMATOR_H


class Animator {
    void initScreen();

    void animationLoop();

    void animateIntersection();

    void animateSquare(int startX, int startY, int endX, int endY);

    void animateRoadMarking();

    int size_X, size_Y;

public:
    Animator();

    virtual ~Animator();
};


#endif //INTERSECTION_ANIMATOR_H
