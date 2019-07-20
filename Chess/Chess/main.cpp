#include <iostream>
#include <string>
#include "Board.hpp"
using namespace std;

int main()
{
    const int msize = 8;
    int round = 1;
    string c_board[msize][msize];
    string set_boardH[4][8];
    string set_boardA[4][8];
    
    Board chess;
    
    chess.genBoard(c_board);
    chess.genBoard2(set_boardH);
    chess.genBoard2(set_boardA);
    chess.setPieces(set_boardH, 'H');
    for (int i = 0; i < 10; i++){
        cout << "\n\n\n";
    }
    cout << "It's turn for the Asmodians!"<< endl;
    chess.setPieces(set_boardA, 'A');
    
    
    
    cout << "\n\n\n\n\n\n";
    
    chess.combine_board(c_board, set_boardA, set_boardH);
    chess.showBoard(c_board);
    
    do {
        cout << "It's turn for Human!"<< endl;
        chess.ask_move(c_board, 'H', round);
        cout << "It's turn for the Asmodians!"<< endl;
        chess.ask_move(c_board, 'A', round);
        round++;
    } while (!chess.win);//each player takes chance to make their moves
    
    //check for winning condition
    if (chess.wside == 'H'){
        cout << "Human wins BABU!\n";
        return 0;
    }else if (chess.wside == 'A'){
        cout << "Asmodians wins BABU!\n";
        return 0;
    }
}
/*
 1 1 a
 2 1 b
 3 1 c
 3 1 d
 4 1 e
 4 1 f
 4 1 g
 4 1 h
 5 2 a
 5 2 b
 6 2 c
 7 3 a
 7 3 b
 7 3 c
 7 3 d
 7 3 e
*/
