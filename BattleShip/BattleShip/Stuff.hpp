//
//  Stuff.hpp
//  BattleShip
//
//  Created by レン on 2019/7/15.
//  Copyright © 2019 レン. All rights reserved.
//

#ifndef Stuff_hpp
#define Stuff_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
using namespace std;

#ifndef size
#define size 10
#endif



class Board{
private:
    bool isInteger(string str);
    void victoryCheck(int sunk, char side);
public:
    Board();
    int Destroyer_p, Destroyer_e;
    int score;
    void ai_genBoard(char arr[][size], int b_length, char symbol);
    void genBoard(char arr[][size]);
    void showBoard(char arr[][size]);
    void set(int num, char ch, char direction, char arr[][size], char symbol, int b_length);
    void ask(char arr[][size], int b_length, char symbol);
    void ai_attack(char arr[][size], char result_b[][size]);
    
    void attackShip(char arr[][size], char result_b[][size], char side);
    string side_check(char side);
    bool win;
    int p_sunk, e_sunk, a_sunk;
    void shipType(char ch, char side);
    void checkShip(int num, int character, char play_b[][size], int b_length, char result_b[][size], char side);
};

/*
 1 a v
 1 b v
 1 c v
 1 d v
 1 e v
 1 f v
 1 g v
 1 h v
 1 i v
 1 j v
 10 a h
 10 c h
 10 e h
 10 g h
 10 i h
 */

#endif /* Stuff_hpp */
