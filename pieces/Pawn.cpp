//
// Created by pavel on 28.01.18.
//

#include "Pawn.h"

Pawn::Pawn(int x, int y, const Texture& texture): Piece(x, y, texture) {
}

bool Pawn::isValidMove(int i, int j) {
    return j == getJ() && i - getI() == 1;
}