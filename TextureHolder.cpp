//
// Created by pavel on 06.02.18.
//

#include "TextureHolder.h"


void TextureHolder::load(Textures::ID id, const std::string& filename) {
    std::unique_ptr<sf::Texture> texture_ptr(new sf::Texture());
    if(!texture_ptr->loadFromFile(filename)){}
    mTextureMap.insert(std::make_pair(id, std::move(texture_ptr)));
}

sf::Texture& TextureHolder::get(Textures::ID id){
    auto found = mTextureMap.find(id);
    return *found->second;
}