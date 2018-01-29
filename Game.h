//
// Created by pavel on 28.01.18.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include <iostream>
#include "shapes/Shape.h"
using namespace std;

class Game{
private:
    static const int WIDTH = 8;
    static const int HEIGHT = 8;
    Shape* board[WIDTH][HEIGHT] = { nullptr };
    void moveShape(Shape*, int x, int y);
    void init();
public:
    Game();
    ~Game();
    void readInput(int x1, int y1, int x2, int y2);
    void draw();
};

#endif //CHESS_GAME_H
