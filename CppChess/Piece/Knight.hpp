//
//  Knight.hpp
//  CppChess
//
//  Created by Will Maclean on 7/6/22.
//

#ifndef Knight_hpp
#define Knight_hpp

#include "Piece.hpp"

class Knight : public Piece{
public:
    Knight(class Board* board, Side side);
    ~Knight();
    
    std::vector<class Move*> GetPossibleMoves() override;
    
    virtual Knight* copy() override;
};

#endif /* Knight_hpp */
