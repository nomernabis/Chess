#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game.h"

using namespace std;
using namespace sf;

int main() {

    RenderWindow window(VideoMode(512, 512), "Chess");
    window.setFramerateLimit(60);

    Texture texture;
    texture.loadFromFile("assets/board.png");

    Texture pawnTexture;
    pawnTexture.loadFromFile("assets/blackPawn.png");

    Sprite bgSprite;
    bgSprite.setTexture(texture);

    Sprite pawnSprite;
    pawnSprite.setTexture(pawnTexture);
    pawnSprite.setPosition(7, 7);

    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
        }

        window.clear(Color::White);
        window.draw(bgSprite);
        window.draw(pawnSprite);
        window.display();
    }

    return 0;
}