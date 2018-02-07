//
// Created by pavel on 28.01.18.
//

#include "Queen.h"
#include <cstdlib>

Queen::Queen(int i, int j, const Texture& texture): Piece(i, j, texture) {
}

bool Queen::isValidMove(int i, int j) {
    return abs(getI() - i) == abs(getJ() - j) || getI() == i || getJ() == j;
}