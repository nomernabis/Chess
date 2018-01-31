//
// Created by pavel on 28.01.18.
//

#include "Game.h"
#include "pieces/Rook.h"
#include "pieces/Knight.h"
#include "pieces/Bishop.h"
#include "pieces/Queen.h"
#include "pieces/Pawn.h"
#include "pieces/King.h"

using namespace sf;

Game::Game()
        :window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Chess") {
    init();
}

Game::~Game() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (board[i][j] != nullptr) {
                delete board[i][j];
            }
        }
    }
}

void Game::run() {
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            readInput();
        }
        draw();
    }
}

void Game::init() {
    //load resources
    boardTexture.loadFromFile("assets/board.png");
    boardSprite.setTexture(boardTexture);

    redRect.setFillColor(Color::Red);
    redRect.setSize({Piece::CELL_SIZE, Piece::CELL_SIZE});
    redRect.setPosition(currentPiece->getJ() * Piece::CELL_SIZE,
                     currentPiece->getI() * Piece::CELL_SIZE);
    //initial layout
    //"RHBQKBHR",
    string map[2] = {
            "RHBQKBHR",
            "PPPPPPPP"
    };

    Piece *piece = nullptr;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (map[i][j] == 'R') {
                piece = new Rook(i, j);
            } else if (map[i][j] == 'H') {
                piece = new Knight(i, j);
            } else if (map[i][j] == 'B') {
                piece = new Bishop(i, j);
            } else if (map[i][j] == 'Q') {
                piece = new Queen(i, j);
            } else if (map[i][j] == 'P') {
                piece = new Pawn(i, j);
            } else if (map[i][j] == 'K') {
                piece = new King(i, j);
            }
            board[i][j] = piece;
        }
    }
}

void Game::readInput() {
    Vector2i position;
    if(Mouse::isButtonPressed(Mouse::Left)){
        position = Mouse::getPosition(window);
        int i = position.y / Piece::CELL_SIZE;
        int j = position.x / Piece::CELL_SIZE;

        if(currentPiece == nullptr){
            currentPiece = board[i][j];
        } else {
            if(currentPiece->getI() == i && currentPiece->getJ() == j){
                currentPiece = nullptr;
                return;
            }
            if(currentPiece->isValidMove(i, j)){
                moveShape(currentPiece, i, j);
                currentPiece = nullptr;
            }
        }
    }

}

void Game::moveShape(Piece *shape, int i, int j) {
    board[shape->getI()][shape->getJ()] = nullptr;
    shape->setPosition(i, j);
    board[i][j] = shape;
}

void Game::draw() {
    window.clear(Color::White);
    window.draw(boardSprite);

    if(currentPiece != nullptr){
        window.draw(redRect);
    }
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (board[i][j] != nullptr) {
                window.draw(*board[i][j]->getIconSprite());
            }
        }

    }
    window.display();
}

