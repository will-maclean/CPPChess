//
//  TestPiece.hpp
//  CppChess
//
//  Created by Will Maclean on 5/6/22.
//

#ifndef TestPiece_hpp
#define TestPiece_hpp

#include "Piece.hpp"

class TestPiece : public Piece{
public:
    TestPiece(class Board* board);
    ~TestPiece();
};

#endif /* TestPiece_hpp */
