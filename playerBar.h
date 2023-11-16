#ifndef PLAYERBAR_H
#define PLAYERBAR_H

class PlayerBar{

    private:
    int x, y, originalX, originalY, score;

    public:
    PlayerBar();
    PlayerBar(int posX, int posY);
    int getX();
    int getY();
    int getScore();
    void scoreUp();
    void reset();
    void moveUp();
    void moveDown();
};

#endif