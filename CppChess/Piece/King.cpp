//
//  King.cpp
//  CppChess
//
//  Created by Will Maclean on 7/6/22.
//

#include "King.hpp"
#include "Piece.hpp"
#include "Board.hpp"
#include "Game.hpp"
#include "Move.hpp"


King::King(Board* board, Side side) : Piece(board, side){
    mTexture =  board->getGame()->getTexture("Resources/Pieces/king_" + std::string(1, side) + ".png");
}

std::vector<Move*> King::GetPossibleMoves(){
    std::vector<Move*> possibleMoves;
    
    std::vector<Position> candidateLocations = {
        {getLocation().x, getLocation().y-1},
        {getLocation().x+1, getLocation().y-1},
        {getLocation().x+1, getLocation().y},
        {getLocation().x+1, getLocation().y+1},
        {getLocation().x, getLocation().y+1},
        {getLocation().x-1, getLocation().y+1},
        {getLocation().x-1, getLocation().y},
        {getLocation().x-1, getLocation().y-1},
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

King* King::copy(){
    King* newPiece = new King(mBoard, mSide);
    newPiece->mTile = mTile;
    newPiece->mTexture = mTexture;
    newPiece->setHasMoved(mHasMoved);
    
    return newPiece;
}
