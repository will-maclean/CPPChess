//
//  Bishop.cpp
//  CppChess
//
//  Created by Will Maclean on 7/6/22.
//

#include <vector>

#include "Bishop.hpp"
#include "Piece.hpp"
#include "Board.hpp"
#include "Game.hpp"
#include "Move.hpp"
#include "Position.hpp"


Bishop::Bishop(Board* board, Side side) : Piece(board, side){
    mTexture =  board->getGame()->getTexture("Resources/Pieces/bishop_" + std::string(1, side) + ".png");
}

std::vector<Move*> Bishop::GetPossibleMoves(){
    std::vector<Move*> possibleMoves;
    
    Position location = getLocation();
    
    // down right
    for(int i = 1; i < 8; i++){
        Position targetPos = {location.x + i, location.y + i};
        if(targetPos.x >= 8 || targetPos.x < 0 || targetPos.y >= 8 || targetPos.y < 0){
            break;
        }
        // haven't left the board
        
        // check if there's a piece on this tile
        if(mBoard->getTile(targetPos.x, targetPos.y)->hasPiece()){
            // there's a piece here!
            Piece* pieceOnTargetSquare = mBoard->getTile(targetPos.x, targetPos.y)->getPiece();
            
            // is it on the same team as us?
            if (pieceOnTargetSquare->getSide() == mSide){
                // same team! we can't take it, and we also can't continue on this diagonal
                break;
            }else{
                // opposition team! add taking this piece as a possible move
                
                possibleMoves.emplace_back(new Move(mBoard, this, targetPos, Move::ENormal));
                
                // now that we've found a piece, we can't continue on this diagonal anymore
                break;
            }
        } else{
            // no piece here! add this as a possible move
            possibleMoves.emplace_back(new Move(mBoard, this, targetPos, Move::ENormal));
        }
    }
    
    // up right
    for(int i = 1; i < 8; i++){
        Position targetPos = {location.x + i, location.y - i};
        if(targetPos.x >= 8 || targetPos.x < 0 || targetPos.y >= 8 || targetPos.y < 0){
            break;
        }
        // haven't left the board
        
        // check if there's a piece on this tile
        if(mBoard->getTile(targetPos.x, targetPos.y)->hasPiece()){
            // there's a piece here!
            Piece* pieceOnTargetSquare = mBoard->getTile(targetPos.x, targetPos.y)->getPiece();
            
            // is it on the same team as us?
            if (pieceOnTargetSquare->getSide() == mSide){
                // same team! we can't take it, and we also can't continue on this diagonal
                break;
            }else{
                // opposition team! add taking this piece as a possible move
                
                possibleMoves.emplace_back(new Move(mBoard, this, targetPos, Move::ENormal));
                
                // now that we've found a piece, we can't continue on this diagonal anymore
                break;
            }
        } else{
            // no piece here! add this as a possible move
            possibleMoves.emplace_back(new Move(mBoard, this, targetPos, Move::ENormal));
        }
    }
    
    // up right
    for(int i = 1; i < 8; i++){
        Position targetPos = {location.x - i, location.y + i};
        if(targetPos.x >= 8 || targetPos.x < 0 || targetPos.y >= 8 || targetPos.y < 0){
            break;
        }
        // haven't left the board
        
        // check if there's a piece on this tile
        if(mBoard->getTile(targetPos.x, targetPos.y)->hasPiece()){
            // there's a piece here!
            Piece* pieceOnTargetSquare = mBoard->getTile(targetPos.x, targetPos.y)->getPiece();
            
            // is it on the same team as us?
            if (pieceOnTargetSquare->getSide() == mSide){
                // same team! we can't take it, and we also can't continue on this diagonal
                break;
            }else{
                // opposition team! add taking this piece as a possible move
                
                possibleMoves.emplace_back(new Move(mBoard, this, targetPos, Move::ENormal));
                
                // now that we've found a piece, we can't continue on this diagonal anymore
                break;
            }
        } else{
            // no piece here! add this as a possible move
            possibleMoves.emplace_back(new Move(mBoard, this, targetPos, Move::ENormal));
        }
    }
    
    // down right
    for(int i = 1; i < 8; i++){
        Position targetPos = {location.x - i, location.y - i};
        if(targetPos.x >= 8 || targetPos.x < 0 || targetPos.y >= 8 || targetPos.y < 0){
            break;
        }
        // haven't left the board
        
        // check if there's a piece on this tile
        if(mBoard->getTile(targetPos.x, targetPos.y)->hasPiece()){
            // there's a piece here!
            Piece* pieceOnTargetSquare = mBoard->getTile(targetPos.x, targetPos.y)->getPiece();
            
            // is it on the same team as us?
            if (pieceOnTargetSquare->getSide() == mSide){
                // same team! we can't take it, and we also can't continue on this diagonal
                break;
            }else{
                // opposition team! add taking this piece as a possible move
                
                possibleMoves.emplace_back(new Move(mBoard, this, targetPos, Move::ENormal));
                
                // now that we've found a piece, we can't continue on this diagonal anymore
                break;
            }
        } else{
            // no piece here! add this as a possible move
            possibleMoves.emplace_back(new Move(mBoard, this, targetPos, Move::ENormal));
        }
    }
    
    return possibleMoves;
}

Bishop* Bishop::copy(){
    Bishop* newPiece = new Bishop(mBoard, mSide);
    newPiece->mTile = mTile;
    newPiece->mTexture = mTexture;
    newPiece->setHasMoved(mHasMoved);
    
    return newPiece;
}
