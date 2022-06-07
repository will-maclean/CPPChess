//
//  Piece.cpp
//  CppChess
//
//  Created by Will Maclean on 5/6/22.
//
#include <vector>

#include "Piece.hpp"
#include "Move.hpp"
#include "Board.hpp"
#include "Game.hpp"

Piece::Piece(Board* board, Side side): mHasMoved(false){
    mBoard = board;
    mSide = side;
}

std::vector<Move*> Piece::GetPossibleMoves(){
    std::vector<Move*> possibleMoves;
    
    return possibleMoves;
}


void Piece::draw(SDL_Renderer* renderer){
    if (mTexture)
    {
        SDL_Rect r;
        // Scale the width/height by owner's scale
        r.w = static_cast<int>(mBoard->getGame()->getScreenWidth() / 8);
        r.h = static_cast<int>(mBoard->getGame()->getScreenHeight() / 8);
        // Center the rectangle around the position of the owner
        r.x = static_cast<int>((mTile->GetLocation().x - r.w / 2) * mBoard->getGame()->getScreenHeight() / 8 - r.w / 2);
        r.y = static_cast<int>((mTile->GetLocation().y - r.h / 2)* mBoard->getGame()->getScreenHeight() / 8- r.h / 2);
        
        SDL_RenderCopy(renderer,
            mTexture,
            nullptr,
            &r);
    }
}

Position Piece::getLocation(){
    return mTile->GetLocation();
}
