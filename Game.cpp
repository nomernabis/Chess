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
        :window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Chess"), currentPiece{nullptr} {
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

void Game::loadTextures() {
    textureHolder.load(Textures::ID::BLACK_PAWN, assetsPath + "blackPawn.png");
    textureHolder.load(Textures::ID::BLACK_KING, assetsPath + "blackKing.png");
    textureHolder.load(Textures::ID::BLACK_QUEEN, assetsPath + "blackQueen.png");
    textureHolder.load(Textures::ID::BLACK_BISHOP, assetsPath + "blackBishop.png");
    textureHolder.load(Textures::ID::BLACK_ROOK, assetsPath + "blackRook.png");
    textureHolder.load(Textures::ID::BLACK_KNIGHT, assetsPath + "blackKnight.png");

    textureHolder.load(Textures::ID::WHITE_PAWN, assetsPath + "whitePawn.png");
    textureHolder.load(Textures::ID::WHITE_KING, assetsPath + "whiteKing.png");
    textureHolder.load(Textures::ID::WHITE_QUEEN, assetsPath + "whiteQueen.png");
    textureHolder.load(Textures::ID::WHITE_BISHOP, assetsPath + "whiteBishop.png");
    textureHolder.load(Textures::ID::WHITE_ROOK, assetsPath + "whiteRook.png");
    textureHolder.load(Textures::ID::WHITE_KNIGHT, assetsPath + "whiteKnight.png");
}

void Game::init() {
    loadTextures();

    boardTexture.loadFromFile("assets/board.png");
    boardSprite.setTexture(boardTexture);
    boardSprite.move(0, BOARD_OFFSET);

    redRect.setFillColor(Color::Red);
    redRect.setSize({Game::CELL_SIZE, Game::CELL_SIZE});
    blackRect.setFillColor(Color::Black);
    blackRect.setSize({300, 200});
    blackRect.setPosition(window.getSize().x / 2 - blackRect.getSize().x / 2,  (window.getSize().y - blackRect.getSize().y)/2);



    //initial layout

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (map[i][j] == 'R') {
                board[i][j] = new Rook(i, j, textureHolder.get(Textures::ID::BLACK_ROOK), Piece::Color::BLACK);
                board[HEIGHT - 1 - i][j] = new Rook(HEIGHT - 1 - i, j, textureHolder.get(Textures::ID::WHITE_ROOK), Piece::Color::WHITE);
            } else if (map[i][j] == 'H') {
                board[i][j] = new Knight(i, j, textureHolder.get(Textures::ID::BLACK_KNIGHT), Piece::Color::BLACK);
                board[HEIGHT - 1 - i][j] = new Knight(HEIGHT - 1 - i, j, textureHolder.get(Textures::ID::WHITE_KNIGHT), Piece::Color::WHITE);
            } else if (map[i][j] == 'B') {
                board[i][j] = new Bishop(i, j, textureHolder.get(Textures::ID::BLACK_BISHOP), Piece::Color::BLACK);
                board[HEIGHT - 1 - i][j] = new Bishop(HEIGHT - 1 - i, j, textureHolder.get(Textures::ID::WHITE_BISHOP), Piece::Color::WHITE);
            } else if (map[i][j] == 'Q') {
                board[i][j] = new Queen(i, j, textureHolder.get(Textures::ID::BLACK_QUEEN), Piece::Color::BLACK);
                board[HEIGHT - 1 - i][j] = new Queen(HEIGHT - 1 - i, j, textureHolder.get(Textures::ID::WHITE_QUEEN), Piece::Color::WHITE);
            } else if (map[i][j] == 'P') {
                board[i][j] = new Pawn(i, j, textureHolder.get(Textures::ID::BLACK_PAWN), Piece::Color::BLACK);
                board[HEIGHT - 1 - i][j] = new Pawn(HEIGHT - 1 - i, j, textureHolder.get(Textures::ID::WHITE_PAWN), Piece::Color::WHITE);
            } else if (map[i][j] == 'K') {
                board[i][j] = new King(i, j, textureHolder.get(Textures::ID::BLACK_KING), Piece::Color::BLACK);
                board[HEIGHT - 1 - i][j] = new King(HEIGHT - 1 - i, j, textureHolder.get(Textures::ID::WHITE_KING), Piece::Color::WHITE);
            }
        }
    }

}

bool Game::is_collisions(int i, int j) {
    int dx = 0, dy = 0;

    if(i > currentPiece->getI()){
        dy = 1;
    } else if(i < currentPiece->getI()){
        dy = -1;
    }

    if(j > currentPiece->getJ()){
        dx = 1;
    } else if( j < currentPiece->getJ()){
        dx = -1;
    }

    int curI = currentPiece->getI() + dy;
    int curJ = currentPiece->getJ() + dx;

    while(curI != i || curJ != j){
        std::cout << curI << " " << curJ << "\n";
        if(board[curI][curJ] != nullptr){
            return true;
        }
        curI += dy;
        curJ += dx;
    }
    return false;
}

template<class T> bool Game::is_instance(Piece *piece) {
    return dynamic_cast<T*>(piece) != nullptr;
}

bool Game::is_knight(Piece *piece) {
   return dynamic_cast<Knight*>(piece) != nullptr;
}

void Game::next_player() {
    if(current_player == Piece::Color::WHITE){
        current_player = Piece::Color::BLACK;
    } else {
        current_player = Piece::Color::WHITE;
    }
}

void Game::readInput() {
    Vector2i position;
    if(Mouse::isButtonPressed(Mouse::Left)){
        position = Mouse::getPosition(window);


        int i = (position.y - BOARD_OFFSET)/ Game::CELL_SIZE;
        int j = position.x / Game::CELL_SIZE;

        if(currentPiece == nullptr){
            if(board[i][j] != nullptr){
                if(board[i][j]->color == current_player){
                    currentPiece = board[i][j];
                }
            }
        } else {
            if(currentPiece->getI() == i && currentPiece->getJ() == j){
                currentPiece = nullptr;
                return;
            }
            if(currentPiece->isValidMove(i, j) ){
                if(!is_instance<Knight>(currentPiece)){
                    if(!is_collisions(i, j)){
                        moveShape(currentPiece, i, j);
                    }
                } else {
                    moveShape(currentPiece, i, j);
                }
            }
        }
    }

}

void Game::moveShape(Piece *shape, int i, int j) {

    if(board[i][j] == nullptr){
        board[shape->getI()][shape->getJ()] = nullptr;
        shape->setPosition(i, j);
        board[i][j] = shape;
        currentPiece = nullptr;
        next_player();
    } else {
        if(board[i][j]->color != current_player){
            board[shape->getI()][shape->getJ()] = nullptr;
            if(board[i][j]->color == Piece::WHITE){
                board[i][j]->setPositionEeaten(eaten_white.size());
                eaten_white.push_back(board[i][j]);
            } else {
                board[i][j]->setPositionEeaten(eaten_black.size());
                eaten_black.push_back(board[i][j]);
            }
            shape->setPosition(i, j);
            if(is_instance<King>(board[i][j])){
                is_running = false;
                return;
            }
            board[i][j] = shape;
            currentPiece = nullptr;
            next_player();
        }
    }
}

void Game::draw_eaten() {
    for(Piece* piece : eaten_white){
        window.draw(piece->getIconSprite());
    }
    for(Piece* piece : eaten_black){
        window.draw(piece->getIconSprite());
    }
}


void Game::reset_game() {

}

void Game::draw() {
    window.clear(Color::White);
    window.draw(boardSprite);

    if(is_running){
        draw_eaten();
        if(currentPiece != nullptr){
            redRect.setPosition(currentPiece->getJ() * Game::CELL_SIZE,
                                currentPiece->getI() * Game::CELL_SIZE + BOARD_OFFSET);
            window.draw(redRect);
        }

        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                if (board[i][j] != nullptr) {
                    window.draw(board[i][j]->getIconSprite());
                }
            }

        }
    } else {
        window.draw(blackRect);
    }
    window.display();
}


