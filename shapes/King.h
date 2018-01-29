//
// Created by pavel on 29.01.18.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H


#include "Shape.h"

class King: public Shape {
public:
    explicit King(int i=0, int j=0);
    bool isValidMove(int i, int j) override;
};


#endif //CHESS_KING_H
