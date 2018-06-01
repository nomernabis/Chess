#include "Rook.h"

//
// Created by pavel on 28.01.18.
//

bool Rook::isValidMove(int i, int j) {
    return i == getI() || j == getJ();
}


