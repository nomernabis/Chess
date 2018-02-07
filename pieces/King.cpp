//
// Created by pavel on 29.01.18.
//

#include "King.h"
#include <cstdlib>

King::King(int i, int j, const Texture& texture) :Piece(i, j, texture) {

}

bool King::isValidMove(int i, int j) {
    return abs(getI() - i) <= 1 && abs(getJ() - j) <= 1;
}