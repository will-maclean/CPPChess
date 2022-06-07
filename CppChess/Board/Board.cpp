//
//  Board.cpp
//  CppChess
//
//  Created by Will Maclean on 5/6/22.
//
#include "SDL2/SDL.h"
#include "Board.hpp"

#include "Game.hpp"
#include "Move.hpp"

Board::Board(Game* game) : mRedrawRequired(true), selectedTile(nullptr), mGameState(EOngoing){
    mGame = game;
    // start adding tiles
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = new Tile({i, j});
        }
    }
}

Board::~Board(){
    // delete all the moves
    possibleMoves.clear();
    
    // delete all the tiles and pieces
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            delete board[i][j];
        }
    }
}

void Board::Draw(SDL_Renderer* renderer){
    
    // draw background
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            // for each tile...
            Tile* currTile = board[i][j];
            
            // ...get the colour...
            SDL_Color currColour = currTile->getColor();
            
            // ...set the active colour...
            SDL_SetRenderDrawColor(renderer, currColour.r, currColour.g, currColour.b, currColour.a);
            
            SDL_Rect rect = {
                currTile->GetLocation().x * mGame->getScreenWidth() / 8,
                currTile->GetLocation().y * mGame->getScreenHeight() / 8,
                mGame->getScreenWidth() / 8,
                mGame->getScreenHeight() / 8
            };
            
            SDL_RenderFillRect(renderer, &rect);
            
            //draw the piece on that tile
            if(currTile->hasPiece()){
                SDL_Texture* text = currTile->getPiece()->getTexture();
                SDL_Rect rect = {
                    currTile->GetLocation().x * mGame->getScreenWidth() / 8,
                    currTile->GetLocation().y * mGame->getScreenHeight() / 8,
                    mGame->getScreenWidth() / 8,
                    mGame->getScreenHeight() / 8
                };
                
                SDL_RenderCopy(renderer, text, nullptr, &rect);
            
            }
        }
    }
    
}

void Board::addPiece(class Piece* piece, int x, int y){
    board[x][y]->setPiece(piece);
    piece->setTile(board[x][y]);
}

Board* Board::clickOn(int xTile, int yTile){
    Board* returnBoard;
    
    Position clikedPos = {xTile, yTile};
    Tile* clickedTile = board[clikedPos.x][clikedPos.y];
    
    bool shouldCalculatePossibleMoves = false;
    
    // change the colour for that tile
    if(selectedTile){
        if(clickedTile == selectedTile){
            // clicked on same tile
            
            // firstly, unselect that tile
            clickedTile->setSelected(false);
            selectedTile = nullptr;
            returnBoard = this;
        }else{
            // clicked on different tile
            
            // was this a candidate tile?
            if(clickedTile->getCandidateDestination()){
                // time to execute a move!
                
                // find the move
                Move* selectedMove;
                for (auto move : possibleMoves){
                    if(move->getDestination() == clickedTile->GetLocation()){
                        selectedMove = move;
                        break;
                    }
                }
                
                // execute the move
                returnBoard =  selectedMove->execute();
                
            }else{
                selectedTile->setSelected(false);
                clickedTile->setSelected(true);
                selectedTile = clickedTile;
                shouldCalculatePossibleMoves = true;
                returnBoard = this;
            }
        }
    }else{
        clickedTile->setSelected(true);
        selectedTile = clickedTile;
        shouldCalculatePossibleMoves = true;
        returnBoard = this;
    }
    
    // clear all the current possible moves
    for (auto move : possibleMoves){
        Position possibleDestination = move->getDestination();
        board[possibleDestination.x][possibleDestination.y]->setCandidateDestination(false);
    }
    possibleMoves.clear();
    
    // handle stuff after tiles have been (un)selected
    if(shouldCalculatePossibleMoves){
        if(selectedTile->hasPiece()){
            possibleMoves = selectedTile->getPiece()->GetPossibleMoves();
            
            // color in the possible destination squares
            for (auto move : possibleMoves){
                Position possibleDestination = move->getDestination();
                board[possibleDestination.x][possibleDestination.y]->setCandidateDestination(true);
            }
        }
    }
    
    mRedrawRequired = true;
    
    return returnBoard;
}
