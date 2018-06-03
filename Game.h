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
    const int SCREEN_HEIGHT = 512 + BOARD_OFFSET * 2;
    const string map[2] = {"RHBQKBHR", "PPPPPPPP"};
    const string assetsPath = "assets/";
    //fields
    Piece* board[WIDTH][HEIGHT] = { nullptr };
    Piece* currentPiece{nullptr};
    //
    Piece::Color current_player = Piece::Color::WHITE;
    std::vector<Piece*> eaten_white, eaten_black;
    //GUI
    RenderWindow window;

    TextureHolder textureHolder;

    Texture boardTexture;
    Sprite boardSprite;
    RectangleShape redRect;
    RectangleShape blackRect;
    //methods
    void moveShape(Piece*, int x, int y);
    void init();
    void readInput();
    void draw();
    void loadTextures();
    bool is_collisions(int i, int j);
    bool is_knight(Piece* piece);
    template<class T> bool is_instance(Piece*);
    void next_player();
    void draw_eaten();
    void draw_label();
    void reset_game();
public:
    static const int CELL_SIZE = 64;
    static const int BOARD_OFFSET = 140;
    bool is_running = true;
    Game();
    ~Game();
    void run();
};

#endif //CHESS_GAME_H
