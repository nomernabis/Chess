//
// Created by pavel on 28.01.18.
//

#ifndef CHESS_SHAPE_H
#define CHESS_SHAPE_H

#include <string>
#include <SFML/Graphics.hpp>
#include "../TextureHolder.h"

using namespace std;
using namespace sf;

class Piece {
private:
    int i, j;
    Sprite sprite;
public:
    static const int OFFSET = 7;
    Piece() = default;
    explicit Piece(int i, int j, const Texture& texture);
    int getI();
    int getJ();
    void setPosition(int i, int j);
    Sprite getIconSprite();
    virtual bool isValidMove(int i, int j) = 0;
    virtual ~Piece();
};


#endif //CHESS_SHAPE_H
