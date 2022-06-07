//
//  Pawn.cpp
//  CppChess
//
//  Created by Will Maclean on 7/6/22.
//

#include <string>

#include "Pawn.hpp"
#include "Piece.hpp"
#include "Board.hpp"
#include "Game.hpp"
#include "Move.hpp"


Pawn::Pawn(Board* board, Side side) : Piece(board, side){
    mTexture =  board->getGame()->getTexture("Resources/Pieces/pawn_" + std::string(1, side) + ".png");
}

std::vector<Move*> Pawn::GetPossibleMoves(){
    std::vector<Move*> possibleMoves;
    
    // position is dependent on side
    int dir = mSide == Piece::WHITE ? -1 : 1;
    
    Position targetPos = {getLocation().x, getLocation().y + 1 * dir};
    
    if(!(targetPos.x >= 8 || targetPos.x < 0 || targetPos.y >= 8 || targetPos.y < 0)){
        // haven't left the board
        
        // check if there's a piece on this tile
        if(!(mBoard->getTile(targetPos.x, targetPos.y)->hasPiece())){
            possibleMoves.emplace_back(new Move(mBoard, this, targetPos, Move::ENormal));
        }
    }
    
    if(!mHasMoved){
        Position targetPos = {getLocation().x, getLocation().y + 2 * dir};
        
        if(!(targetPos.x >= 8 || targetPos.x < 0 || targetPos.y >= 8 || targetPos.y < 0)){
            // haven't left the board
            
            // check if there's a piece on this tile
            if(!(mBoard->getTile(targetPos.x, targetPos.y)->hasPiece())){
                possibleMoves.emplace_back(new Move(mBoard, this, targetPos, Move::ENormal));
            }
        }
    }
    
    
    return possibleMoves;
}

Pawn* Pawn::copy(){
    Pawn* newPiece = new Pawn(mBoard, mSide);
    newPiece->mTile = mTile;
    newPiece->mTexture = mTexture;
    newPiece->setHasMoved(mHasMoved);
    
    return newPiece;
}
