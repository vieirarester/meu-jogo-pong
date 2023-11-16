/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iostream>
#include "board.h"

// definir cores
#define TXT_VERMELHO    "\033[31m" 
#define TXT_VERDE       "\033[31m"
#define TXT_AZUL        "\033[34m"
#define TXT_AMARELO     "\033[33m"
#define TXT_PRETO       "\033[30m"
#define TXT_BRANCO      "\033[97m"

// definir background
#define BG_VERMELHO     "\033[41m"
#define BG_VERDE        "\033[42m"
#define BG_AZUL         "\033[44m"
#define BG_AMARELO      "\033[43m"
#define BG_PRETO        "\033[40m"
#define BG_BRANCO       "\033[107m"

// definir elementos do tabuleiro
#define BALL            "O"
#define BLANK_SPACE     " "
#define PLAYER_BAR      "\xDB"

// definir reset
#define RESET           "\033[0m"

using namespace std;

Board::Board(int w, int h) : width(w), height(h), ball(Ball(w / 2, h / 2)),
                            playerBar1(PlayerBar(1, h / 2 - 3)), playerBar2(PlayerBar(w - 2, h / 2 - 3)){}

Ball Board::getBall(){
    return this->ball;
}

PlayerBar Board::getPlayerBar1(){
    return this->playerBar1;
}

PlayerBar Board::getPlayerBar2(){
    return this->playerBar1;
}

void Board::setTextColor(const char* color){
    cout << color;
}

void Board::setBackgroundColor(const char* color){
    cout << color;
}

void Board::reset(){
    this->ball.reset();
    this->playerBar1.reset();
    this->playerBar2.reset();
}

void Board::draw() {
    cout << "\033[2J\033[H";
        cout << "\033[H";

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {

                int ballx = this->ball.getX();
                int bally = this->ball.getY();

                int player1x = this->playerBar1.getX();
                int player2x = this->playerBar2.getX();

                int player1y = this->playerBar1.getY();
                int player2y = this->playerBar2.getY();

                if (x == 0 || x == width - 2) {
                    setBackgroundColor(BG_AZUL);
                    setTextColor(TXT_AZUL);
                    cout << BLANK_SPACE; 

                } else if (ballx == x && bally == y) {
                    setBackgroundColor(BG_AZUL);
                    setTextColor(TXT_BRANCO);
                    cout << BALL; // Imprimir a bola

                } else if ((player1x + 1 == x || player1x + 2 == x) && y >= player1y && y < player1y + 4) {
                    setBackgroundColor(BG_AZUL);
                    setTextColor(TXT_BRANCO);
                    cout << PLAYER_BAR; // Imprimir o jogador 1

                } else if ((player2x - 1 == x || player2x - 2 == x) && y >= player2y && y < player2y + 4) {
                    setBackgroundColor(BG_AZUL);
                    setTextColor(TXT_BRANCO);
                    cout << PLAYER_BAR; // Imprimir o jogador 2

                } else {
                    setBackgroundColor(BG_AZUL);
                    setTextColor(TXT_AZUL);
                    cout << BLANK_SPACE;
                }
            }
            cout << RESET << endl;
        }
}

