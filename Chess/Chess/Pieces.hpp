
#ifndef Pieces_hpp
#define Pieces_hpp

#include <iostream>
#include <ctype.h>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#ifndef size
#define size 8
#endif

class Pieces_H {
public:
    bool stuff, v_move, win;
    bool king(string board[][size]);
    bool queen(string board[][size], int character, int num);
    bool guardian(string board[][size], int num, int character);
    bool knight(string board[][size], int num, int character);
    bool assassin(string board[][size], int num, int character);
    bool priest(string board[][size], int num, int character);
    bool villager(string board[][size], int num, int character);
    bool babu(string board[][size], int num, int character);
    bool champion(string board[][size], int num, int character);
    bool fool(string board[][size], int num, int character);
    void pieceType(string board[][size], string symbol);
    bool isInteger(string str);
    void showBoard(string board[][size]);
    bool validPieces(string symbol, string enemy);
    void ask(string board[][size], string symbol);
    bool move (int direction, int m_blocks, string symbol, string board[][size], int num, int character);
    bool move2(int direction, string symbol, string board[][size], int num, int character);
    void move_jump (int direction, string symbol, string board[][size], int num, int character);
    Pieces_H();
};



class Pieces_A {
private:
    bool isInteger(string str);
    void showBoard(string board[][size]);
    bool validPieces(string symbol, string enemy);
    void ask(string board[][size], string symbol);
    void pieceType(string board[][size], string symbol);
    bool move (int direction, int m_blocks, string symbol, string board[][size], int num, int character);
    bool move2(int direction, string symbol, string board[][size], int num, int character);
    void move_jump (int direction, string symbol, string board[][size], int num, int character);
public:
    bool stuff, v_move, win;
    string trap_piece;
    bool lord(string board[][size], int num, int character);
    bool gabriel(string board[][size], int num, int character, int round);
    bool vampire(string board[][size], int num, int character);
    bool ghost(string board[][size], int num, int character);
    bool magician(string board[][size], int num, int character);
    bool slime(string board[][size], int num, int character, int round);
    bool titan(string board[][size], int num, int character);
    bool skeleton(string board[][size], int num, int character);
    bool clown(string board[][size], int num, int character);
    bool duke(string board[][size], int num, int character);
    bool buba(string board[][size], int num, int character);
    Pieces_A();
};

#endif 
