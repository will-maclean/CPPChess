//
//  Bishop.hpp
//  CppChess
//
//  Created by Will Maclean on 7/6/22.
//

#ifndef Bishop_hpp
#define Bishop_hpp

#include <vector>

#include "Piece.hpp"

class Bishop : public Piece{
public:
    Bishop(class Board* board, Side side);
    ~Bishop();
    
    std::vector<class Move*> GetPossibleMoves() override;
    
    virtual Bishop* copy() override;
};

#endif /* Bishop_hpp */
