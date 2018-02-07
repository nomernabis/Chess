//
// Created by pavel on 28.01.18.
//

#include "Bishop.h"
Bishop::Bishop(int i, int j, const Texture& texture): Piece(i, j, texture) {}

bool Bishop::isValidMove(int i, int j) {
    return abs(getI() - i) == abs(getJ() - j);
}