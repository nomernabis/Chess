//
// Created by pavel on 28.01.18.
//

#ifndef CHESS_SHAPE_H
#define CHESS_SHAPE_H


class Shape {
private:
    int i, j;
    char icon;
public:
    explicit Shape(int i = 0, int j = 0);
    int getI();
    int getJ();
    void setI(int i);
    void setJ(int j);
    void setPosition(int i, int j);
    char getIcon();
    void setIcon(char icon);
    virtual bool isValidMove(int i, int j) = 0;
    virtual ~Shape();
};


#endif //CHESS_SHAPE_H
