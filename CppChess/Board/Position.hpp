//
//  Position.hpp
//  CppChess
//
//  Created by Will Maclean on 7/6/22.
//

#ifndef Position_hpp
#define Position_hpp

struct Position{
    int x;
    int y;
    
    bool operator ==(const Position& a){
        return (x == a.x) && (y == a.y);
    }
    
    bool operator !=(const Position& a){
        return (x != a.x) || (y =! a.y);
    }
};

#endif /* Position_hpp */
