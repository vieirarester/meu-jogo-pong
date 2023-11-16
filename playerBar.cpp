/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "playerBar.h"

PlayerBar::PlayerBar() : x(0), y(0), originalX(0), originalY(0), score(0) {}

PlayerBar::PlayerBar(int posX, int posY) : originalX(posX), originalY(posY), x(posX), y(posY) {}

int PlayerBar::getX() {
    return this->x;
}

int PlayerBar::getY() {
    return this->y;
}

int PlayerBar::getScore() {
    return this->score;
}

void PlayerBar::scoreUp(){
    this-> score++;
}

void PlayerBar::reset() {
    this->x = originalX;
    this->y = originalY;
}

void PlayerBar::moveUp() {
    this->y--;
}

void PlayerBar::moveDown() {
    this->y++;
}



