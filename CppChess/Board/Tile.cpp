//
//  Tile.cpp
//  CppChess
//
//  Created by Will Maclean on 5/6/22.
//

#include "SDL2/SDL.h"

#include "Game.hpp"
#include "Tile.hpp"
#include "Position.hpp"

Tile::Tile(Position position): mHasPiece(false), mSelected(false), mCandidateDestination(false){
    mLocation = position;
    
    mSelectedColor = {255, 0, 0, 255};
    mCandidateDestinationColor = {0, 255, 0, 255};
    
    // set square colour
    if((mLocation.x % 2 == 0) ^ (mLocation.y % 2 == 0)){
        // dark square
        mColor.r = 115;
        mColor.g = 81;
        mColor.b = 13;
    }else{
        // light square
        mColor.r = 243;
        mColor.g = 205;
        mColor.b = 108;
    }
}

void Tile::draw(SDL_Renderer *renderer){
    if(mPiece){
        mPiece->draw(renderer);
    }
}
