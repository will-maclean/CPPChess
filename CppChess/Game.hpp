//
//  Game.hpp
//  CppChess
//
//  Created by Will Maclean on 5/6/22.
//

#ifndef Game_hpp
#define Game_hpp

#include <unordered_map>

#include "SDL2/SDL.h"

class Game{
public:
    Game();
    
    bool begin();
    
    void gameLoop();
    
    
    SDL_Texture* getTexture(const std::string& fileName);
    
    int getScreenWidth(){return screenWidth;}
    int getScreenHeight(){return screenHeight;}
    
private:
    void UpdateOutput();
    
    void handleMouseEvent(SDL_Event e);
    
    class Board* mBoard;
    
    int screenWidth;
    int screenHeight;
    
    SDL_Renderer* mRenderer;
    SDL_Window* mWindow;
    
    // Map of textures loaded
    std::unordered_map<std::string, SDL_Texture*> mTextures;
};

#endif /* Game_hpp */
