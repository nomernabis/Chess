#include "Rook.h"

//
// Created by pavel on 28.01.18.
//
Rook::Rook(int i, int j, const Texture& texture):Piece(i, j, texture) {
}

bool Rook::isValidMove(int i, int j) {
    return i == getI() || j == getJ();
}


