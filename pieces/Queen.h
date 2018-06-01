//
// Created by pavel on 28.01.18.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H


#include "Piece.h"

class Queen: public Piece{
private:
public:
    using Piece::Piece;
    bool isValidMove(int i, int j) override;
};


#endif //CHESS_QUEEN_H
