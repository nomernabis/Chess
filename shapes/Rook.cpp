#include "Rook.h"

//
// Created by pavel on 28.01.18.
//
Rook::Rook(int i, int j):Shape(i, j) {
    setIcon('R');
}

bool Rook::isValidMove(int i, int j) {
    return i == getI() || j == getJ();
}


