//
// Created by pavel on 29.01.18.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H


#include "Shape.h"

class Knight: public Shape {
public:
    explicit Knight(int i=0,  int j=0);
    bool isValidMove(int i2, int j2) override;
};


#endif //CHESS_KNIGHT_H
