//
// Created by pavel on 28.01.18.
//

#include "Pawn.h"

bool Pawn::isValidMove(int i, int j) {
    return j == getJ() && i - getI() == 1;
}