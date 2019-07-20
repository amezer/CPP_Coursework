
#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <ctype.h>
#include "Pieces.hpp"
using namespace std;

#ifndef size
#define size 8
#endif

class Board {
private:
    bool isInteger(string str);
    
public:
    bool win;
    char wside;
    void genBoard(string board[][size]);
    
    void genBoard2(string board[4][8]);
    
    void showBoard(string board[][size]);
    void showBoard2(string board[4][8]);
    void setPieces(string board[4][8], char side);
    Pieces_H Human;
    Pieces_A Asmodians;
    
    void combine_board(string t_board[][size], string boardA[4][8], string boardH[4][8]);
    void ask_move(string board[][size], char side, int round);
    Board();
};

#endif
