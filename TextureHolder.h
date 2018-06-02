//
// Created by pavel on 06.02.18.
//

#ifndef CHESS_TEXTUREHOLDER_H
#define CHESS_TEXTUREHOLDER_H
#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <string>

namespace Textures{
    enum class ID {BLACK_PAWN, BLACK_KING, BLACK_BISHOP,
        BLACK_KNIGHT, BLACK_QUEEN, BLACK_ROOK, WHITE_PAWN, WHITE_KING, WHITE_BISHOP, WHITE_KNIGHT, WHITE_QUEEN, WHITE_ROOK};
};

class TextureHolder {
    std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
public:
    void load(Textures::ID id, const std::string& path);
    sf::Texture& get(Textures::ID id);
};


#endif //CHESS_TEXTUREHOLDER_H
