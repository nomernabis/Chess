//
// Created by pavel on 28.01.18.
//

#ifndef CHESS_SHAPE_H
#define CHESS_SHAPE_H

#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Piece {
private:
    int i, j;
    Sprite sprite;
    Texture texture;
public:
    static const int OFFSET = 7;
    explicit Piece(int i = 0, int j = 0);
    int getI();
    int getJ();
    void setI(int i);
    void setJ(int j);
    void setPosition(int i, int j);

    Sprite* getIconSprite();
    void setIcon(string path);

    virtual bool isValidMove(int i, int j) = 0;
    virtual ~Piece();
};


#endif //CHESS_SHAPE_H
