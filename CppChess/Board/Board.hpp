//
//  Board.hpp
//  CppChess
//
//  Created by Will Maclean on 5/6/22.
//

#ifndef Board_hpp
#define Board_hpp

#include "SDL2/SDL.h"
#include "Tile.hpp"
#include "TestPiece.hpp"
#include "Piece.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include <vector>

class Board {
public:
    
    enum EGameState{
        EOngoing,
        EStalemate,
        ECheckmate,
    };
    
    Board(class Game* game);
    
    ~Board();
    
    static Board* getStartingBoard(class Game* game){
        Board* board = new Board(game);
        
        // TODO: add all pieces to the starting board setup
        
        // WHITE
        for(int i = 0; i < 8; i++){
            Pawn* piece = new Pawn(board, Piece::WHITE);
            board->addPiece(piece, i, 6);
        }
        
        board->addPiece(new Rook(board, Piece::WHITE), 0, 7);
        board->addPiece(new Knight(board, Piece::WHITE), 1, 7);
        board->addPiece(new Bishop(board, Piece::WHITE), 2, 7);
        board->addPiece(new Queen(board, Piece::WHITE), 3, 7);
        board->addPiece(new King(board, Piece::WHITE), 4, 7);
        board->addPiece(new Bishop(board, Piece::WHITE), 5, 7);
        board->addPiece(new Knight(board, Piece::WHITE), 6, 7);
        board->addPiece(new Rook(board, Piece::WHITE), 7, 7);
        
        //BLACK
        
        for(int i = 0; i < 8; i++){
            Pawn* piece = new Pawn(board, Piece::BLACK);
            board->addPiece(piece, i, 1);
        }
        
        board->addPiece(new Rook(board, Piece::BLACK), 0, 0);
        board->addPiece(new Knight(board, Piece::BLACK), 1, 0);
        board->addPiece(new Bishop(board, Piece::BLACK), 2, 0);
        board->addPiece(new Queen(board, Piece::BLACK), 3, 0);
        board->addPiece(new King(board, Piece::BLACK), 4, 0);
        board->addPiece(new Bishop(board, Piece::BLACK), 5, 0);
        board->addPiece(new Knight(board, Piece::BLACK), 6, 0);
        board->addPiece(new Rook(board, Piece::BLACK), 7, 0);
        
        return board;
    }
    
    void Draw(SDL_Renderer* renderer);
    
    void addPiece(class Piece* piece, int x, int y);
    
    Board* clickOn(int xTile, int yTile);
    
    class Game* getGame(){return mGame;}
    bool getRedrawRequired(){return mRedrawRequired;}
    void setRedrawRequired(bool req){mRedrawRequired = req;}
    
    Tile* getTile(int x, int y){
        return board[x][y];
    }
    
private:
    class Game* mGame;
    class Tile* selectedTile;
    EGameState mGameState;
    
    std::vector<class Move*> possibleMoves;
    
    Tile* board[8][8];
    
    bool mRedrawRequired;
};

#endif /* Board_hpp */
