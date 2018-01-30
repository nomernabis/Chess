//
// Created by pavel on 28.01.18.
//

#include "Bishop.h"
Bishop::Bishop(int i, int j): Piece(i, j) {
    setIcon("assets/blackBishop.png");
}

bool Bishop::isValidMove(int i, int j) {
    return abs(getI() - i) == abs(getJ() - j);
}