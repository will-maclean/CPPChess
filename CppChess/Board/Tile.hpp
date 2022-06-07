//
//  Tile.hpp
//  CppChess
//
//  Created by Will Maclean on 5/6/22.
//

#ifndef Tile_hpp
#define Tile_hpp

#include "SDL2/SDL.h"
#include "Piece.hpp"
#include "Position.hpp"

class Tile{
public:
    Tile(Position position);
    
    Position GetLocation(){
        return mLocation;
    }
    
    bool getSelected(){return mSelected;}
    void setSelected(bool selected){mSelected = selected;}
    
    bool getCandidateDestination(){return mCandidateDestination;}
    void setCandidateDestination(bool candidate){mCandidateDestination = candidate;}
    
    class Piece* getPiece(){return mPiece;}
    void setPiece(class Piece* piece){
        mHasPiece = true;
        mPiece = piece;
        
    }
    
    SDL_Color getColor(){
        if(mCandidateDestination){
            return mCandidateDestinationColor;
        }
        else if(mSelected){
            return mSelectedColor;
        }else{
            return mColor;
            
        }
    }
    
    void draw(SDL_Renderer* renderer);
    
    bool hasPiece(){return mHasPiece;}
    
private:
    Piece* mPiece;
    Position mLocation;
    bool mSelected;
    bool mHasPiece;
    bool mCandidateDestination;
    SDL_Color mColor;
    SDL_Color mSelectedColor;
    SDL_Color mCandidateDestinationColor;
};

#endif /* Tile_hpp */
