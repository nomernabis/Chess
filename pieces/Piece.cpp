//
// Created by pavel on 28.01.18.
//

#include "Piece.h"
#include "../Game.h"

Piece::Piece(int i, int j, const Texture& texture)
{
    sprite.setTexture(texture);
    setPosition(i, j);
}

int Piece::getI(){
    return this->i;
}

int Piece::getJ(){
    return this->j;
}

void Piece::setPosition(int i, int j){
    this->i = i;
    this->j = j;
    sprite.setPosition(j * Game::CELL_SIZE + OFFSET, i * Game::CELL_SIZE + OFFSET);
}


Sprite Piece::getIconSprite() {
    return sprite;
}

Piece::~Piece() = default;

