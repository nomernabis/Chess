//
// Created by pavel on 29.01.18.
//

#include "King.h"
#include <cstdlib>

King::King(int i, int j) :Piece(i, j) {
    setIcon("assets/blackKing.png");
}

bool King::isValidMove(int i, int j) {
    return abs(getI() - i) <= 1 && abs(getJ() - j) <= 1;
}