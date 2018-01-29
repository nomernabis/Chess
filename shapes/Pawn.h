//
// Created by pavel on 28.01.18.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Shape.h"

class Pawn: public Shape {
public:
    explicit Pawn(int i=0, int j=0);
    bool isValidMove(int i, int j) override;
};


#endif //CHESS_PAWN_H
