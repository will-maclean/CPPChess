//
//  Game.cpp
//  CppChess
//
//  Created by Will Maclean on 5/6/22.
//

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cmath>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Game.hpp"
#include "Board.hpp"

Game::Game() : screenWidth(600), screenHeight(600){
}

bool Game::begin(){
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0){
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }
    
    mWindow = SDL_CreateWindow("CPPChess", 100, 100, screenWidth, screenHeight, 0);
    
    if (!mWindow){
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }
    
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!mRenderer){
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }
    
    if (IMG_Init(IMG_INIT_PNG) == 0){
        SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
        return false;
    }
    
    mBoard = Board::getStartingBoard(this);
    
    return true;
}

void Game::gameLoop(){
    // start by updating output
    UpdateOutput();
    
    
    SDL_bool quit = SDL_FALSE;
    while (!quit) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    quit = SDL_TRUE;
                    break;
                    
                case SDL_MOUSEBUTTONDOWN:
                    handleMouseEvent(e);
                    break;
                
                default:
                    break;
            }
        }
        
        if(mBoard->getRedrawRequired()){
            UpdateOutput();
        }
    }
    
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Game::handleMouseEvent(SDL_Event e){
    // e.type == SDL_MouseButtonEvent
    SDL_MouseButtonEvent mouseEvent = e.button;
    
    // figure out where we clicked
    int xClick = mouseEvent.x;
    int yClick = mouseEvent.y;
    
    int xTile = floor((100 * xClick / screenWidth) / 12.5);
    int yTile = floor((100 * yClick / screenHeight) / 12.5);
    
    Board* returnBoard = mBoard->clickOn(xTile, yTile);
    
    if(!(returnBoard == mBoard)){
        // we have a new board!
        
        // delete the old one
        delete mBoard;
        mBoard = returnBoard;
    }
}

void Game::UpdateOutput(){
    SDL_SetRenderDrawColor(mRenderer, 50, 0, 0, 255);
    SDL_RenderClear(mRenderer);
    
    // draw the board
     mBoard->Draw(mRenderer);
    mBoard->setRedrawRequired(false);
    
    SDL_RenderPresent(mRenderer);
}

SDL_Texture* Game::getTexture(const std::string& fileName)
{
    SDL_Texture* tex = nullptr;
    // Is the texture already in the map?
    auto iter = mTextures.find(fileName);
    if (iter != mTextures.end())
    {
        tex = iter->second;
    }
    else
    {
        // Load from file
        SDL_Surface* surf = IMG_Load(fileName.c_str());
        if (!surf)
        {
            SDL_Log("Failed to load texture file %s", fileName.c_str());
            return nullptr;
        }
        
        // Create texture from surface
        tex = SDL_CreateTextureFromSurface(mRenderer, surf);
        SDL_FreeSurface(surf);
        if (!tex)
        {
            SDL_Log("Failed to convert surface to texture for %s", fileName.c_str());
            return nullptr;
        }
        
        mTextures.emplace(fileName.c_str(), tex);
    }
    return tex;
}
