//
//  King.hpp
//  CppChess
//
//  Created by Will Maclean on 7/6/22.
//

#ifndef King_hpp
#define King_hpp

#include "Piece.hpp"

class King : public Piece{
public:
    King(class Board* board, Side side);
    ~King();
    
    std::vector<class Move*> GetPossibleMoves();
    
    virtual King* copy();
};

#endif /* King_hpp */
