//
//  Rook.hpp
//  CppChess
//
//  Created by Will Maclean on 7/6/22.
//

#ifndef Rook_hpp
#define Rook_hpp

#include "Piece.hpp"

class Rook : public Piece{
public:
    Rook(class Board* board, Side side);
    ~Rook();
    
    std::vector<class Move*> GetPossibleMoves();
    
    virtual Rook* copy();
};

#endif /* Rook_hpp */
