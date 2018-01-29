//
// Created by pavel on 28.01.18.
//

#include "Game.h"
#include "shapes/Pawn.h"
#include "shapes/Rook.h"
#include "shapes/Bishop.h"
#include "shapes/Queen.h"
#include "shapes/King.h"
#include "shapes/Knight.h"

Game::Game() {
    init();
}

Game::~Game(){
    for(int i=0; i < HEIGHT; ++i){
        for(int j=0; j < WIDTH; ++j){
            if(board[i][j] != nullptr){
                delete board[i][j];
            }
        }
    }
}

void Game::init(){
    //initial layout
    string map[2] = {
            "RHBQKBHR",
            "PPPPPPPP"
    };

    Shape* shape;
    for(int i=0; i < 2; ++i){
        for(int j=0; j < WIDTH; ++j){
            if(map[i][j] == 'R'){
                shape = new Rook;
            } else if(map[i][j] == 'H'){
                shape = new Knight;
            } else if(map[i][j] == 'B'){
                shape = new Bishop;
            } else if(map[i][j] == 'Q'){
                shape = new Queen;
            } else if(map[i][j] == 'P'){
                shape = new Pawn;
            } else if(map[i][j] == 'K'){
                shape = new King;
            }
            shape->setPosition(i, j);
            board[i][j] = shape;
        }
    }
}

void Game::readInput(int i1, int j1, int i2, int j2){
    Shape* shape = board[i1][j1];
    if(shape != nullptr){
        if(shape->isValidMove(i2, j2)){
            moveShape(shape, i2, j2);
        }
    }
}

void Game::moveShape(Shape* shape, int i, int j) {
    board[shape->getI()][shape->getJ()] = nullptr;
    shape->setPosition(i, j);
    board[i][j] = shape;
}

void Game::draw() {
    for(int i=0; i < HEIGHT; ++i){
        for(int j=0; j < WIDTH; ++j){
           if(board[i][j] == nullptr){
               cout << '0';
           } else {
               cout << board[i][j]->getIcon();
           }
        }
        cout << '\n';
    }
}

