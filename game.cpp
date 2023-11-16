/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "game.h"
#include <iostream>

using namespace std;

Game::Game(int w, int h) : width(w), height(h), 
                            playerJoy1({PA_4, PF_1}),  // Inicializando playerJoy1 com pinos específicos
                            playerJoy2({PA_1, PB_0}),  // Inicializando playerJoy2 com pinos específicos
                            board(w, h) {};


void Game::scoreUp(PlayerBar &playerBar){
    playerBar.scoreUp();
}

void Game::movePlayers(){

    PlayerBar playerBar1 = this->board.getPlayerBar1();
    PlayerBar playerBar2 = this->board.getPlayerBar2();
    Ball ball = this->board.getBall();

    int player1x = this->board.getPlayerBar1().getX();
    int player2x = this->board.getPlayerBar2().getX();

    int player1y = this->board.getPlayerBar1().getY();
    int player2y = this->board.getPlayerBar2().getY();

    ball.move();

    if(playerJoy1.y.read() > 0.7) {
        playerBar1.moveUp();
    } else if (playerJoy1.y.read() < 0.3) {
        playerBar1.moveDown();
    } 

    if(playerJoy2.y.read() > 0.7) {
        playerBar2.moveUp();
    } else if (playerJoy2.y.read() < 0.3) {
        playerBar2.moveDown();
    }         

    if(ball.getDirection() == STOP) {
        ball.randomDirection();
    }
}

void Game::checkMovements(){

    PlayerBar playerBar1 = this->board.getPlayerBar1();
    PlayerBar playerBar2 = this->board.getPlayerBar2();

    int ballx = this->board.getBall().getX();
    int bally = this->board.getBall().getY();;

    int player1x = this->board.getPlayerBar1().getX();
    int player2x = this->board.getPlayerBar2().getX();

    int player1y = this->board.getPlayerBar1().getY();
    int player2y = this->board.getPlayerBar2().getY();

    // jogador 1
    for(int i = 0; i < 4 ; i++) {
        if(ballx == player1x + 1) {
            if (bally == player1y + 1) {
                this->board.getBall().changeDirection((eDirection)((rand() % 3) + 4));
            }
        }
    }

    // jogador 2
    for(int i = 0; i < 4 ; i++) {
        if(ballx == player2x - 1) {
            if (bally == player2y + 1) {
                this->board.getBall().changeDirection((eDirection)((rand() % 3) + 1));
            }
        }
    }

    // parte de cima
    if(bally == 0) {
        this->board.getBall().changeDirection((eDirection) this->board.getBall().getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT );
    }

    // parte de baixo
    if(bally == height - 1) {
        this->board.getBall().changeDirection((eDirection) this->board.getBall().getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT );
    }

    // colisões laterais (incrementar score dos players)
    // parede direita
    if(ballx == width - 1) {
        scoreUp(playerBar1);
        this->board.reset();
    }

    // parede esquerta
    if(ballx == 0) {
        scoreUp(playerBar2);
        this->board.reset();
    }
}

void Game::start() {
    this->board.draw();
    movePlayers();
    checkMovements();   
}

