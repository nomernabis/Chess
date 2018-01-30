//
// Created by pavel on 28.01.18.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "pieces/Piece.h"

using namespace std;

class Game{
private:
    static const int WIDTH = 8;
    static const int HEIGHT = 8;
    const int SCREEN_WIDTH = 512;
    const int SCREEN_HEIGHT = 512;

    RenderWindow window;
    Texture boardTexture;
    Sprite boardSprite;
    Piece* board[WIDTH][HEIGHT] = { nullptr };
    void moveShape(Piece*, int x, int y);
    void init();

    Piece* currentPiece;
public:
    Game();
    ~Game();
    void run();
    void readInput();
    void draw();
};

#endif //CHESS_GAME_H
