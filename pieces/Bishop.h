//
// Created by pavel on 28.01.18.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include <cstdlib>
#include "Piece.h"


class Bishop: public Piece {
public:
    using Piece::Piece;
    bool isValidMove(int i, int j) override;
};


#endif //CHESS_BISHOP_H
