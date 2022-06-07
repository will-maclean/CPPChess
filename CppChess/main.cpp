//
//  main.cpp
//  CppChess
//
//  Created by Will Maclean on 5/6/22.
//
#include <iostream>
#include "Game.hpp"

int main(int argc, const char * argv[]) {
    Game* game = new Game();
    
    if(game->begin()){
        std::cout << "Starting Game\n";
        game->gameLoop();
        
    }
}
