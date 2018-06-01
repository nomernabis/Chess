//
// Created by pavel on 28.01.18.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Piece.h"

class Rook : public Piece{
public:
    using Piece::Piece;
    bool isValidMove(int i, int j) override;
};
#endif //CHESS_ROOK_H
