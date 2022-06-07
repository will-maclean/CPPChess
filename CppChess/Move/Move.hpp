//
//  Move.hpp
//  CppChess
//
//  Created by Will Maclean on 5/6/22.
//

#ifndef Move_hpp
#define Move_hpp

#include "Position.hpp"

class Move{
public:
    enum EMoveType{
        ENormal,
        ECastle,
        EEnPassant,
    };
    
    Move(class Board* fromBoard, class Piece* movePiece, struct Position destination, EMoveType eMoveType);
    
    class Board* execute();
    
    Position getDestination(){return mDestination;}
private:
    class Board* mFromBoard;
    class Piece* mMovePiece;
    Position mDestination;
    EMoveType mMoveType;
};

#endif /* Move_hpp */
