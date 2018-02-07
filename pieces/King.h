//
// Created by pavel on 29.01.18.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H


#include "Piece.h"

class King: public Piece {
public:
    explicit King(int i, int j, const Texture& texture);
    bool isValidMove(int i, int j) override;
};


#endif //CHESS_KING_H
