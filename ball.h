#ifndef BALL_H
#define BALL_H

enum eDirection {
    STOP = 0,
    LEFT = 1,
    UPLEFT = 2,
    DOWNLEFT = 3,
    RIGHT = 4,
    UPRIGHT = 5,
    DOWNRIGHT = 6
};

class Ball {
private:
    int x, y, originalX, originalY;
    eDirection direction;

public:
    Ball();
    Ball(int posX, int posY);
    int getX();
    int getY();
    eDirection getDirection();
    void reset();
    void changeDirection(eDirection d);
    void randomDirection();
    void move();
};

#endif // BALL_H