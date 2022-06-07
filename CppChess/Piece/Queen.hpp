//
//  Queen.hpp
//  CppChess
//
//  Created by Will Maclean on 7/6/22.
//

#ifndef Queen_hpp
#define Queen_hpp

#include "Piece.hpp"

class Queen : public Piece{
public:
    Queen(class Board* board, Side side);
    ~Queen();
    
    std::vector<class Move*> GetPossibleMoves();
    
    virtual Queen* copy();
};

#endif /* Queen_hpp */
