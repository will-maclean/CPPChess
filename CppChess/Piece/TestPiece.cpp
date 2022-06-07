//
//  TestPiece.cpp
//  CppChess
//
//  Created by Will Maclean on 5/6/22.
//

#include <string>

#include "TestPiece.hpp"
#include "Piece.hpp"
#include "Board.hpp"
#include "Game.hpp"

TestPiece::TestPiece(Board* board) : Piece(board, Piece::WHITE){
    mTexture =  board->getGame()->getTexture("Resources/Pieces/bishop_white.png");
}
