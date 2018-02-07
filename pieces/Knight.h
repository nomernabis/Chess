//
// Created by pavel on 29.01.18.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H


#include "Piece.h"

class Knight: public Piece {
public:
    explicit Knight(int i,  int j, const Texture& texture);
    bool isValidMove(int i2, int j2) override;
};


#endif //CHESS_KNIGHT_H
