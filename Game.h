//
// Created by pavel on 28.01.18.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "pieces/Piece.h"
#include "TextureHolder.h"

using namespace std;

class Game{
private:
    //constants
    static const int WIDTH = 8;
    static const int HEIGHT = 8;
    const int SCREEN_WIDTH = 512;
    const int SCREEN_HEIGHT = 512;
    const string map[2] = {"RHBQKBHR", "PPPPPPPP"};
    const string assetsPath = "assets/";
    //fields
    Piece* board[WIDTH][HEIGHT] = { nullptr };
    Piece* currentPiece{nullptr};
    //GUI
    RenderWindow window;

    TextureHolder textureHolder;

    Texture boardTexture;
    Sprite boardSprite;
    RectangleShape redRect;
    //methods
    void moveShape(Piece*, int x, int y);
    void init();
    void readInput();
    void draw();
    void loadTextures();
    bool is_collisions(int i, int j);
    bool is_knight(Piece* piece);
public:
    static const int CELL_SIZE = 64;
    Game();
    ~Game();
    void run();
};

#endif //CHESS_GAME_H
