//
// Created by pavel on 28.01.18.
//

#include "Pawn.h"

Pawn::Pawn(int x, int y): Piece(x, y) {
    setIcon("assets/blackPawn.png");
}

bool Pawn::isValidMove(int i, int j) {
    return j == getJ() && i - getI() == 1;
}