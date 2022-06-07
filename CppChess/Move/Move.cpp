//
//  Move.cpp
//  CppChess
//
//  Created by Will Maclean on 5/6/22.
//

#include "Move.hpp"
#include "Position.hpp"
#include "Board.hpp"
#include "Piece.hpp"

Move::Move(Board* fromBoard, Piece* movePiece, Position destination, EMoveType eMoveType):
mFromBoard(fromBoard), mMovePiece(movePiece), mDestination(destination), mMoveType(eMoveType){
    
}

Board* Move::execute(){
    Board* newBoard = new Board(mFromBoard->getGame());
    
    // add all the pieces, except for the ones at the start and target positions
    
    for(int i = 0; i < 8; i++){
        for(int j = 0; j<8; j++){
            Position currPos = {i, j};
            
            newBoard->getTile(currPos.x, currPos.y)->setSelected(false);
            newBoard->getTile(currPos.x, currPos.y)->setCandidateDestination(false);
            
            if(!(currPos == mMovePiece->getLocation() || currPos == mDestination)){
                // if there's a piece here, add it to the new board
                if(mFromBoard->getTile(currPos.x, currPos.y)->hasPiece()){
                    Piece* newPiece = mFromBoard->getTile(currPos.x, currPos.y)->getPiece()->copy();
                    newPiece->setBoard(newBoard);
                    newBoard->addPiece(newPiece, currPos.x, currPos.y);
                }
            }
        }
    }
    
    // move the target piece to the destination
    Piece* movedPiece = mMovePiece->copy();
    movedPiece->setBoard(newBoard);
    movedPiece->setHasMoved(true);
    newBoard->addPiece(movedPiece, mDestination.x, mDestination.y);
    
    return newBoard;
}
