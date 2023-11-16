#ifndef GAME_H
#define GAME_H

#include "mbed.h"
#include "playerBar.h"
#include "board.h"

typedef struct playerJoy {
    AnalogIn y;
    DigitalIn sw;
} playerJoy_t;

class Game {
private:
    int width, height;

    playerJoy_t playerJoy1;
    playerJoy_t playerJoy2;

    Board board;

public:
    Game(int w, int h);
    void scoreUp(PlayerBar &player);
    void movePlayers();
    void checkMovements();
    void start();
};

#endif
