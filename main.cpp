/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "game.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     1000ms
#define UPDATE_RATE       0.5

int main()
{
    BufferedSerial pc(USBTX, USBRX, 144000);
    // USBTX = pb_3
    // USBRX = pa_10
    Game game(125, 25);

    while (true) {

        game.start();

        ThisThread::sleep_for(BLINKING_RATE);
    }
}
