//
// Created by pavel on 29.01.18.
//

#include "Knight.h"
#include <cstdlib>

Knight::Knight(int i, int j, const Texture& texture): Piece(i, j, texture){
}

bool Knight::isValidMove(int i2, int j2) {
    return (abs(getI() - i2) + abs(getJ() - j2)) == 3
           && abs(getJ() - j2) != 0
           && abs(getI() - i2) != 0;
}



