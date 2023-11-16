/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "ball.h"


Ball::Ball() : x(0), y(0), originalX(0), originalY(0), direction(STOP) {}

Ball::Ball(int posX, int posY) : originalX(posX), originalY(posY), x(posX), y(posY), direction(STOP) {}

int Ball::getX() {
    return x;
}

int Ball::getY() {
    return y;
}

eDirection Ball::getDirection(){
    return direction;
}

void Ball::reset() {
    x = originalX;
    y = originalY;
    direction = STOP;
}

void Ball::changeDirection(eDirection d) {
    direction = d;
}

void Ball::randomDirection() {
    direction = static_cast<eDirection>(rand() % 6 + 1);
}

void Ball::move() {
    switch (direction) {
        case STOP:
            break;
        case LEFT:
            x--;
            break;
        case UPLEFT:
            x--;
            y--;
            break;
        case RIGHT:
            x++;
            break;
        case DOWNLEFT:
            x--;
            y++;
            break;
        case UPRIGHT:
            x++;
            y--;
            break;
        case DOWNRIGHT:
            x++;
            y++;
            break;
        default:
            break;
    }
}

