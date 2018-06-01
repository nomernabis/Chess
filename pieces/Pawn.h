//
// Created by pavel on 28.01.18.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"

class Pawn: public Piece {
public:
    using Piece::Piece;
    bool isValidMove(int i, int j) override;
};


#endif //CHESS_PAWN_H
