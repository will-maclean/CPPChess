//
//  Piece.hpp
//  CppChess
//
//  Created by Will Maclean on 5/6/22.
//

#ifndef Piece_hpp
#define Piece_hpp

#include <vector>
#include <string>
#include "SDL2/SDL.h"
#include "Position.hpp"

class Piece{
public:
    enum Side : char{
        BLACK = 'b',
        WHITE = 'w',
    };
    
    Piece(class Board* board, Side side);
    
    void draw(SDL_Renderer* renderer);
    
    virtual std::vector<class Move*> GetPossibleMoves();
    
    virtual Piece* copy(){return nullptr;}
    
    void setTile(class Tile* tile){mTile = tile;}
    
    void setBoard(class Board* board){mBoard = board;}
    
    SDL_Texture* getTexture(){return mTexture;}
    
    Side getSide(){return mSide;}
    
    Position getLocation();
    
    void setHasMoved(bool hasMoved){mHasMoved = hasMoved;}
    bool getHasMoved(){return mHasMoved;}
    
protected:
    class Board* mBoard;
    class Tile* mTile;
    Side mSide;
    SDL_Texture* mTexture;
    bool mHasMoved;
};

#endif /* Piece_hpp */
