//
// Created by pavel on 28.01.18.
//

#include "Piece.h"

Piece::Piece(int i, int j) :i(i), j(j) {}

int Piece::getI(){
    return this->i;
}

int Piece::getJ(){
    return this->j;
}

void Piece::setI(int i){
    this->i = i;
}

void Piece::setJ(int j) {
    this->j = j;
}

void Piece::setPosition(int i, int j){
    this->i = i;
    this->j = j;
    sprite.setPosition(j * CELL_SIZE + OFFSET, i * CELL_SIZE + OFFSET);
}

void Piece::setIcon(string iconPath) {
    texture.loadFromFile(iconPath);
    sprite.setTexture(texture);
    sprite.setPosition(j * CELL_SIZE + OFFSET, i * CELL_SIZE + OFFSET);
}

Sprite* Piece::getIconSprite() {
    return &sprite;
}

Piece::~Piece() = default;

