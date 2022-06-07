//
//  Knight.cpp
//  CppChess
//
//  Created by Will Maclean on 7/6/22.
//

#include "Knight.hpp"

#include "Piece.hpp"
#include "Board.hpp"
#include "Game.hpp"
#include "Move.hpp"

Knight::Knight(Board* board, Side side) : Piece(board, side){
    mTexture =  board->getGame()->getTexture("Resources/Pieces/knight_" + std::string(1, side) + ".png");
}


std::vector<Move*> Knight::GetPossibleMoves(){
    std::vector<Move*> possibleMoves;
    
    std::vector<Position> candidateLocations = {
        {getLocation().x+1, getLocation().y-2},
        {getLocation().x+2, getLocation().y-1},
        {getLocation().x+2, getLocation().y+1},
        {getLocation().x+1, getLocation().y+2},
        {getLocation().x-1, getLocation().y+2},
        {getLocation().x-2, getLocation().y+1},
        {getLocation().x-2, getLocation().y-1},
        {getLocation().x-1, getLocation().y-2},
    };
    
    for(auto pos : candidateLocations){
        if(pos.x >= 8 || pos.x < 0 || pos.y >= 8 || pos.y < 0){
            continue;
        }
        
        // is there a friendly player there?
        if(!(mBoard->getTile(pos.x, pos.y)->hasPiece() && mBoard->getTile(pos.x, pos.y)->getPiece()->getSide() == mSide)){
            // if not, we can move there
            Move* newMove = new Move(mBoard, this, pos, Move::ENormal);
            
            possibleMoves.emplace_back(newMove);
        }
    }
    
    return possibleMoves;
}

Knight* Knight::copy(){
    Knight* newPiece = new Knight(mBoard, mSide);
    newPiece->mTile = mTile;
    newPiece->mTexture = mTexture;
    newPiece->setHasMoved(mHasMoved);
    
    return newPiece;
}
