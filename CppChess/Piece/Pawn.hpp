//
//  Pawn.hpp
//  CppChess
//
//  Created by Will Maclean on 7/6/22.
//

#ifndef Pawn_hpp
#define Pawn_hpp

#include "Piece.hpp"

class Pawn : public Piece{
public:
    Pawn(class Board* board, Side side);
    ~Pawn();
    
    std::vector<class Move*> GetPossibleMoves() override;
    
    Pawn* copy() override;
    
};

#endif /* Pawn_hpp */
