//
// Created by pavel on 28.01.18.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H


#include "Piece.h"

class Queen: public Piece{
private:
public:
    explicit Queen(int i=0, int j=0);
    bool isValidMove(int i, int j) override;
};


#endif //CHESS_QUEEN_H
