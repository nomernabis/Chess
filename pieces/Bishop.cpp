//
// Created by pavel on 28.01.18.
//

#include "Bishop.h"

bool Bishop::isValidMove(int i, int j) {
    return abs(getI() - i) == abs(getJ() - j);
}