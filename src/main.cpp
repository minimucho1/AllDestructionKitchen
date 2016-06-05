#include <iostream>
#include "SDL.h"

#include <Game.hpp>

/*
    Created By: JR - 6/3/2016
    John's the muh fuckin GREATEST
    OH YEAH?
*/

int main(int argc, char *argv[]) {
    if(Game::Loop()) {
        std::cout << "ERROR: gameState_ NOT Uninitialized. Shutting down...\n";
    }

    return 0;
}
