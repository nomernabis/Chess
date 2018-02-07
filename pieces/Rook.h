//
// Created by pavel on 28.01.18.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Piece.h"

class Rook : public Piece{
public:
    explicit Rook(int i, int j, const Texture& texture);
    bool isValidMove(int i, int j) override;
};
#endif //CHESS_ROOK_H
