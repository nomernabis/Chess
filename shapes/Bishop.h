//
// Created by pavel on 28.01.18.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include <cstdlib>
#include "Shape.h"


class Bishop: public Shape {
public:
    explicit Bishop(int i=0, int j=0);
    bool isValidMove(int i, int j) override;
};


#endif //CHESS_BISHOP_H
