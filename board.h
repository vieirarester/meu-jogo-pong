#ifndef BOARD_H
#define BOARD_H

#include "ball.h"
#include "playerBar.h"

class Board{

    private:
        int width, height;
        Ball ball;
        PlayerBar playerBar1, playerBar2;

    public:
        Board(int width, int height);

        Ball getBall();
        PlayerBar getPlayerBar1();
        PlayerBar getPlayerBar2();

        void setBackgroundColor(const char* color);
        void setTextColor(const char* color);
        void reset();
        void draw();
};

#endif