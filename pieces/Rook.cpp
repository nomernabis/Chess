#include "Rook.h"

//
// Created by pavel on 28.01.18.
//
Rook::Rook(int i, int j):Piece(i, j) {
    setIcon("assets/blackRook.png");
}

bool Rook::isValidMove(int i, int j) {
    return i == getI() || j == getJ();
}


