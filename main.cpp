#include <iostream>

#include "Game.h"

using namespace std;

int main() {
    Game game;
    int i1, i2, j1, j2;
    while(true){
        game.draw();
        cin >> i1 >> j1 >> i2 >> j2;
        if(i1 == -1){
            break;
        }
        game.readInput(i1, j1, i2, j2);
    }
    return 0;
}