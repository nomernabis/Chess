//
// Created by pavel on 28.01.18.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Shape.h"

class Rook : public Shape{
public:
    explicit Rook(int i=0, int j=0);
    bool isValidMove(int i, int j) override;
};
#endif //CHESS_ROOK_H
