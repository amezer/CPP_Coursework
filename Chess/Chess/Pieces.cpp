#include <iostream>
#include <ctype.h>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include "Pieces.hpp"
using namespace std;


int the_fool = 1, b_chance = 1;
int bomb_x, bomb_y;

int Guar = 2, kn_ight = 4, murabito = 5, ass_assin = 2, ba_bu = 0, ch_ampion = 0;
int b_king = 1, b_guardian = Guar, b_knight = kn_ight, b_assassin = ass_assin, b_priest = 1, b_babu = ba_bu, b_champ = ch_ampion, b_queen = 1;
int champ = 1;

int vamp = 4, gh_ost = 2, Ti_tan = 2, bu_ba = 0;
int b_lord = 1, b_gabriel = 1, b_vamp = vamp, b_ghost = gh_ost, b_magician = 1, b_titan = Ti_tan, b_buba = bu_ba;

void betray(string board[][size]){// randomly decides wheather the fool is going to betray the Human side
    int chance, x, y;
    srand(time(NULL));
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (board[i][j] == "Ѷ"){
                y = i;
                x = j;
            }
        }
    }
    chance = rand()%2;
    if(chance == 0){
        cout << "The Fool has betrayed!\n";
        board[y][x] = "〠";
        b_chance = 0;
    }
}

    bool Pieces_H::isInteger(string str)//check interger
    {
        int num;
        istringstream iss (str);
        
        iss >> num;
        
        return !iss.fail();
    }
    
    void Pieces_H::showBoard(string board[][size]){//prints the board
        int character = 0;
        char ch = 'A';
        cout << "\t" << "\t";
        for (int k = 0; k < size; k++){
            character = int(ch);
            cout << ch << "\t";
            character++;
            ch = char(character);
        }
        cout << endl;
        cout << "\t" << "\t";
        for (int k = 0; k < size; k++){
            cout << "-" << "\t";
        }
        cout << endl;
        for (int i = 0; i < size; i++){
            cout << i+1 << "\t" << "|" << "\t";
            for (int j = 0; j < size; j++){
                cout << board[i][j] << "\t";
            }
            cout << "\n\n";
            if (i == 3){
                cout << "\t --------------------------------"<<"\n\n";
            }
        }
    }
    
    void Pieces_H::ask(string board[][size], string symbol){//used when ont's BABU needed
        string ch_num, ch_ch;
        int num, character, num2;
        bool empty;
        char ch;
        do{
            do{
                cout << "Enter the location(num): ";
                cin >> ch_num;
                cout << endl;
                try {
                    num = stoi(ch_num);
                }
                catch (exception err) {
                    cout << "Invalid Input." << endl;
                    num = 0;
                }
            }while(!((num <= 8) && (isInteger(ch_num) && (num >=1))));
            getchar();
            do{
                system("stty raw");
                cout << "Enter the location(char): ";
                ch = getchar();
                cout << endl;
                ch = toupper(ch);
            }while(!((ch >= 'A') && (ch <= 'J')&& (!isInteger(ch_ch))));
            character = 0;
            character = (int(ch) - 64)-1;
            num2 = num-1;
            if (board[num2][character] != "0"){
                cout << "There's stuff at that spot BABU!" << endl;
                empty = false;
            }else{
                empty = true;
            }
        }while(!empty);
        board[num2][character] = symbol;
    }
    
    void Pieces_H::pieceType(string board[][size], string symbol){//check for special conditions
        if (symbol == "↭"){
            vamp--;
        }else if (symbol == "♛"){
            win = true;
        }
    }

    bool Pieces_H::validPieces(string symbol, string enemy){//checking the orders between each pieces
    if (symbol == "♔" && (enemy == "♚"||enemy == "웃"||enemy == "↭"||enemy == "𝕲"||enemy == "✡"||enemy == "⍢"||enemy == "☠"||enemy == "〠"||enemy == "❧"))
        return true;
    else if ((symbol == "♔" && !(enemy == "♚"||enemy == "웃"||enemy == "↭"||enemy == "𝕲"||enemy == "✡"||enemy == "⍢"||enemy == "☠"||enemy == "〠"||enemy == "❧")))
        return false;
    if (symbol == "♢" && (enemy == "웃"||enemy == "↭"||enemy == "𝕲"||enemy == "✡"||enemy == "⍢"||enemy == "☠"||enemy == "〠"||enemy == "❧"))
        return true;
    else if ((symbol == "♢" && !(enemy == "웃"||enemy == "↭"||enemy == "𝕲"||enemy == "✡"||enemy == "⍢"||enemy == "☠"||enemy == "〠"||enemy == "❧")))
        return false;
    if (symbol == "♘" && (enemy == "↭"||enemy == "𝕲"||enemy == "⍢"||enemy == "☠"||enemy == "〠"||enemy == "❧"))
        return true;
    else if ((symbol == "♘" && !(enemy == "↭"||enemy == "𝕲"||enemy == "⍢"||enemy == "☠"||enemy == "〠"||enemy == "❧")))
        return false;
    if (symbol == "☽" && (enemy == "♛"||enemy == "♚"||enemy == "웃"||enemy == "↭"||enemy == "𝕲"||enemy == "✡"||enemy == "⍢"||enemy == "☠"||enemy == "〠"||enemy == "❧"||enemy == "☫"))
        return true;
    else if ((symbol == "☽" && !(enemy == "♛"||enemy == "♚"||enemy == "웃"||enemy == "↭"||enemy == "𝕲"||enemy == "✡"||enemy == "⍢"||enemy == "☠"||enemy == "〠"||enemy == "❧"||enemy == "☫")))
        return false;
    if (symbol == "✙" && (enemy == "웃"||enemy == "↭"||enemy == "𝕲"||enemy == "✡"||enemy == "⍢"||enemy == "☠"||enemy == "〠"||enemy == "❧"))
        return true;
    else if ((symbol == "✙" && !(enemy == "웃"||enemy == "↭"||enemy == "𝕲"||enemy == "✡"||enemy == "⍢"||enemy == "☠"||enemy == "〠"||enemy == "❧")))
        return false;
    if (symbol == "ꆜ" && (enemy == "♛"||enemy == "☠"||enemy == "〠"||enemy == "⍢"))
        return true;
    else if ((symbol == "ꆜ" && !(enemy == "♛"||enemy == "☠"||enemy == "〠"||enemy == "⍢")))
        return false;
    if (symbol == "卍" && (enemy == "♛"||enemy == "♚"||enemy == "웃"||enemy == "↭"||enemy == "𝕲"||enemy == "✡"||enemy == "⍢"||enemy == "☠"||enemy == "〠"||enemy == "☫"||enemy == "❧"))
        return true;
    else if ((symbol == "卍" && !(enemy == "♛"||enemy == "♚"||enemy == "웃"||enemy == "↭"||enemy == "𝕲"||enemy == "✡"||enemy == "⍢"||enemy == "☠"||enemy == "〠"||enemy == "☫"||enemy == "❧")))
        return false;
    if (symbol == "❦" && (enemy == "♛"||enemy == "♚"||enemy == "웃"||enemy == "↭"||enemy == "𝕲"||enemy == "✡"||enemy == "⍢"||enemy == "☠"||enemy == "〠"||enemy == "❧"))
        return true;
    else if ((symbol == "❦" && !(enemy == "♛"||enemy == "♚"||enemy == "웃"||enemy == "↭"||enemy == "𝕲"||enemy == "✡"||enemy == "⍢"||enemy == "☠"||enemy == "〠"||enemy == "❧"))){
        return false;
    }
    if (symbol == "Ѷ" && (enemy == "♚"||enemy == "웃"||enemy == "↭"||enemy == "𝕲"||enemy == "✡"||enemy == "⍢"||enemy == "☠"||enemy == "〠"||enemy == "☫"||enemy == "❧"))
        return true;
    else
        return false;
}


    bool Pieces_H::move (int direction, int m_blocks, string symbol, string board[][size], int num, int character){//basic moves with 8 directions
        string enemy;
        int j = character, i;
        switch (direction) {
            case 1://up
                enemy = board[num-m_blocks][character];
                symbol = board[num][character];
                if(num-m_blocks == bomb_y && character == bomb_x){
                    cout << symbol << " died from Gabriel's BABU!" << endl;
                    board[num-m_blocks][character] = "0";
                    return v_move = true;
                }
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num-m_blocks][character] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num-m_blocks][character] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 2://down
                enemy = board[num+m_blocks][character];
                symbol = board[num][character];
                if(num+m_blocks == bomb_y && character == bomb_x){
                    cout << symbol << " died from Gabriel's BABU!" << endl;
                    board[num+m_blocks][character] = "0";
                    return v_move = true;
                }
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num+m_blocks][character] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num+m_blocks][character] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 3://right
                enemy = board[num][character+m_blocks];
                symbol = board[num][character];
                if(num == bomb_y && character+m_blocks == bomb_x){
                    cout << symbol << " died from Gabriel's BABU!" << endl;
                    board[num][character+m_blocks] = "0";
                    return v_move = true;
                }
                if (board[num][character+m_blocks] != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num][character+m_blocks] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num][character+m_blocks] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 4://left
                enemy = board[num][character-m_blocks];
                symbol = board[num][character];
                if(num == bomb_y && character-m_blocks == bomb_x){
                    cout << symbol << " died from Gabriel's BABU!" << endl;
                    board[num][character-m_blocks] = "0";
                    return v_move = true;
                }
                if (board[num][character-m_blocks] != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num][character-m_blocks] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num][character-m_blocks] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 5://up right
                j = character;
                for (i = num; i > num-m_blocks; i--){
                    j++;
                }
                enemy = board[i][j];
                symbol = board[num][character];
                if(i == bomb_y && j == bomb_x){
                    cout << symbol << " died from Gabriel's BABU!" << endl;
                    board[i][j] = "0";
                    return v_move = true;
                }
                if (board[i][j] != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[i][j] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[i][j] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 6://up left
                j = character;
                for (i = num; i > num-m_blocks; i--){
                    j--;
                }
                enemy = board[i][j];
                symbol = board[num][character];
                if(i == bomb_y && j == bomb_x){
                    cout << symbol << " died from Gabriel's BABU!" << endl;
                    board[i][j] = "0";
                    return v_move = true;
                }
                if (board[i][j] != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[i][j] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[i][j] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 7://down left
                j = character;
                for (i = num; i < num+m_blocks; i++){
                    j--;
                }
                enemy = board[i][j];
                symbol = board[num][character];
                if(i == bomb_y && j == bomb_x){
                    cout << symbol << " died from Gabriel's BABU!" << endl;
                    board[i][j] = "0";
                    return v_move = true;
                }
                if (board[i][j] != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[i][j] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[i][j] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 8://down right
                j = character;
                for (i = num; i < num+m_blocks; i++){
                    j++;
                }
                enemy = board[i][j];
                symbol = board[num][character];
                if(i == bomb_y && j == bomb_x){
                    cout << symbol << " died from Gabriel's BABU!" << endl;
                    board[i][j] = "0";
                    return v_move = true;
                }
                if (board[i][j] != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[i][j] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[i][j] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            default:
                return v_move = true;
        }
    }
    
    bool Pieces_H::move2(int direction, string symbol, string board[][size], int num, int character){// moves to walk in the shape "L"
        string enemy;
        switch (direction){
            case 1:
                symbol = board[num][character];
                enemy = board[num-2][character+1];
                if(num-2 == bomb_y && character+1 == bomb_x){
                    cout << symbol << " died from Gabriel's BABU!" << endl;
                    board[num-2][character+1] = "0";
                    return v_move = true;
                }
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num-2][character+1] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num-2][character+1] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 2:
                symbol = board[num][character];
                enemy = board[num-1][character+2];
                if(num-1 == bomb_y && character+2 == bomb_x){
                    cout << symbol << " died from Gabriel's BABU!" << endl;
                    board[num-1][character+2] = "0";
                    return v_move = true;
                }
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num-1][character+2] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num-1][character+2] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 3:
                symbol = board[num][character];
                enemy = board[num-2][character-1];
                if(num-2 == bomb_y && character-1 == bomb_x){
                    cout << symbol << " died from Gabriel's BABU!" << endl;
                    board[num-2][character-1] = "0";
                    return v_move = true;
                }
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num-2][character-1] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num-2][character-1] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 4:
                symbol = board[num][character];
                enemy = board[num-1][character-2];
                if(num-1 == bomb_y && character-2 == bomb_x){
                    cout << symbol << " died from Gabriel's BABU!" << endl;
                    board[num-1][character-2] = "0";
                    return v_move = true;
                }
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        enemy = board[num-1][character-2] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num-1][character-2] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 5:
                symbol = board[num][character];
                enemy = board[num+2][character+1];
                if(num+2 == bomb_y && character+1 == bomb_x){
                    cout << symbol << " died from Gabriel's BABU!" << endl;
                    board[num+2][character+1] = "0";
                    return v_move = true;
                }
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num+2][character+1] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num+2][character+1] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 6:
                symbol = board[num][character];
                enemy = board[num+1][character+2];
                if(num+1 == bomb_y && character+2 == bomb_x){
                    cout << symbol << " died from Gabriel's BABU!" << endl;
                    board[num+1][character+2] = "0";
                    return v_move = true;
                }
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num+1][character+2] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num+1][character+2] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 7:
                symbol = board[num][character];
                enemy = board[num+2][character-1];
                if(num+2 == bomb_y && character-1 == bomb_x){
                    cout << symbol << " died from Gabriel's BABU!" << endl;
                    board[num+2][character-1] = "0";
                    return v_move = true;
                }
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num+2][character-1] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num+2][character-1] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 8:
                symbol = board[num][character];
                enemy = board[num+1][character-2];
                if(num+1 == bomb_y && character-2 == bomb_x){
                    cout << symbol << " died from Gabriel's BABU!" << endl;
                    board[num+1][character-2] = "0";
                    return v_move = true;
                }
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num+1][character-2] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num+1][character-2] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            default:
                return v_move = true;
        }
    }
    
    void Pieces_H::move_jump (int direction, string symbol, string board[][size], int num, int character){//used for assassin/ghost's "move&attack" [counts the space between one piece and another]
        int count, m_blocks;
        switch (direction){
            case 1: //up
                count = 0;
                m_blocks = 0;
                for (int i = num-1; i > 0; i--){
                    m_blocks++;
                    if (board [i][character] != "0"){
                        count++;
                    }
                    if (count == 2){
                        break;
                    }
                }
                move(1, m_blocks, symbol, board, num, character);
                break;
            case 2: //down
                count = 0;
                m_blocks = 0;
                for (int i = num; i > (8-num); i++){
                    m_blocks++;
                    if (board [i][character] != "0"){
                        count++;
                    }
                    if (count == 2){
                        break;
                    }
                }
                move(2, m_blocks, symbol, board, num, character);
                break;
            case 3: //right
                count = 0;
                m_blocks = 0;
                for (int i = character; i > (8-character); i++){
                    m_blocks++;
                    if (board [num][i] != "0"){
                        count++;
                    }
                    if (count == 2){
                        break;
                    }
                }
                move(3, m_blocks, symbol, board, num, character);
                break;
            case 4: //left
                count = 0;
                m_blocks = 0;
                for (int i = character; i > 0; i--){
                    m_blocks++;
                    if (board [num][i] != "0"){
                        count++;
                    }
                    if (count == 2){
                        break;
                    }
                }
                move(4, m_blocks, symbol, board, num, character);
                break;
        }
    }

    bool Pieces_H::king(string board[][size]){
        int ans;
        do{
            cout << "Do you want to use King's BABU? \n1)Yes\t2)No\n";
            cout << ">";
            cin >> ans;
        }while(ans != 1 && ans!= 2 && isdigit(ans));
        switch (ans) {
            case 1:
                if (b_king != 1){
                    cout << "King has no more BABU to use.\n";
                }else{
                    cout << "Summon Castle x4 BABU!" << endl;
                    for (int i = 0; i < 4; i++){
                        ask(board, "♖");
                        cout << "Castle setted." << (4-(i+1)) << " more ♖ left." << endl;
                        showBoard(board);
                    }
                    b_king--;
                }
                return stuff = false;
                break;
            case 2:
                return stuff = false;
                break;
            default:
                return stuff = false;
                break;
        }
    }
    
    bool Pieces_H::queen(string board[][size], int num, int character){
        int ans, direction, m_blocks, ans2, x, y, j;
        bool space = true, no_chess = true;
        string ch_direc, ch_mblocks;
        srand(time(NULL));
        do{
            cout << "Do you want to move Queen or use Queen's BABU? \n1)move\t2)BABU\t3)Exit\n";
            cout << ">";
            cin >> ans;
        }while(ans != 1 && ans!= 2 && isdigit(ans));
        switch (ans) {
            case 1:
                while (!v_move){
                    do{
                        cout << "Which direction?\n";
                        cout << "1)up \t";
                        cout << "2)down \t";
                        cout << "3)right \n";
                        cout << "4)left \t";
                        cout << "5)up right \t";
                        cout << "6)up left \n";
                        cout << "7)down left\t";
                        cout << "8)down right \t";
                        cout << "9)Exit \n";
                        cout << ">";
                        cin >> ch_direc;
                        cout << endl;
                        try {
                            direction = stoi(ch_direc);
                        }
                        catch (exception err) {
                            cout << "Invalid Input." << endl;
                            direction = 0;
                        }
                        if (direction == 9){
                            return stuff = false;
                        }
                    }while(!((direction <= 9) && (isInteger(ch_direc) && (direction >=1))));
                    //ask and check direction
                    do{
                        do{//check for intergers
                            cout << "How many steps do you want to BABU? [9 to exit]" << endl;
                            cout << ">";
                            cin >> ch_mblocks;
                            try {
                                m_blocks = stoi(ch_mblocks);
                            }
                            catch (exception err) {
                                cout << "Invalid Input." << endl;
                                m_blocks = 0;
                            }
                            if (m_blocks == 9)
                                return stuff = false;
                        }while(!((m_blocks <= 9) && (isInteger(ch_mblocks) && (m_blocks >=1))));
                        switch (direction) {
                            case 1://up
                                
                                if ((num+1) < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((num+1) >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 2://down
                                
                                if ((8-(num+1)) < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(num+1)) >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 3://right
                                
                                if ((8-(character+1)) < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(character+1)) >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 4://left
                                
                                if (character+1 < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(character+1 >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 5://up right
                                
                                if(((num+1) >= m_blocks) && ((8-(character+1)) >= m_blocks)){
                                    space = true;
                                
                                }else if (((num+1) < m_blocks) && ((8-(character+1)) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                break;
                            case 6://up left
                                
                                if(((num+1) >= m_blocks) && ((character+1) >= m_blocks)){
                                    space = true;
                                }
                                else if (((num+1) < m_blocks) && ((character+1) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                break;
                            case 7:
                                j = character-1;
                                
                                if(((8-(num+1)) >= m_blocks) && ((character+1) >= m_blocks )){
                                    space = true;
                                }
                                else if (((8-(num+1)) < m_blocks) && ((character+1) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                break;
                            case 8:
                                
                                if(((8-(num+1)) >= m_blocks) && ((8-(character+1)) >= m_blocks) ){
                                    space = true;
                                }
                                else if (((8-(num+1)) < m_blocks) && ((8-(character+1)) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                break;
                            default:
                                break;
                        }//checl m_block validation
                    }while (!space);
                    move(direction, m_blocks, "♔", board, num, character);
                }
                return stuff = true;
            case 2:
                if (kn_ight == 0){
                    do{
                        cout << "Do you want to use Queen's BABU? \n1)Yes\t2)No\n";
                        cout << ">";
                        cin >> ans2;
                    }while(ans2 != 1 && ans2 != 2 && isdigit(ans2));
                    if (ans2 == 1){
                        if (b_queen < 1){
                            cout << "Queen has no more BABU to use.\n";
                            return stuff = false;
                        }else{
                            do{
                                x = rand()%8;
                                y = rand()%8;
                            }while (board[y][x] != "0");
                            board[x][y] = "♢";
                            cout << "Guardian summoned!\n";
                            Guar++;
                            return stuff = false;
                        }
                    }else if (ans2 == 2){
                        return stuff = false;
                    }
                }else{
                    cout << "Queen's BABU is not avaliable right now." << endl;
                    return stuff = false;
                }
            case 3:
                return stuff = false;
            default:
                return stuff = false;
        }
    }
    
    bool Pieces_H::guardian(string board[][size], int num, int character){
        int ans, direction, m_blocks = 2, x, y;
        string ch_direc;
        bool space = false, no_chess = true;
        srand(time(NULL));
        do{
            cout << "Do you want to move Guardian or use Guardian's BABU? \n1)move\t2)BABU\t3)Exit\n";
            cout << ">";
            cin >> ans;
        }while(ans != 1 && ans!= 2 && isdigit(ans));
        switch (ans) {
            case 1:
                while (!v_move){
                    while (!space){
                        do{
                            cout << "Which direction?\n";
                            cout << "1)up \t";
                            cout << "2)down \t";
                            cout << "3)right \t";
                            cout << "4)left \t";
                            cout << "5)Exit \n";
                            cout << ">";
                            cin >> ch_direc;
                            cout << endl;
                            try {
                                direction = stoi(ch_direc);
                            }
                            catch (exception err) {
                                cout << "Invalid Input." << endl;
                                direction = 0;
                            }
                            if (direction == 5){
                                return stuff = false;
                            }
                        }while(!((direction <= 4) && (isInteger(ch_direc) && (direction >=1))));//ask direction
                        switch (direction) {
                            case 1://up
                                
                                if ((num+1) < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((num+1) >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 2://down
                                
                                if ((8-(num+1)) < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(num+1)) >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 3://right
                                
                                if ((8-(character+1)) < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(character+1)) >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 4://left
                                
                                if (character+1 < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(character+1 >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                        }//check space
                    }
                    move(direction, m_blocks, "♢", board, num, character);
                }
                return stuff = true;
            case 2:
                if (b_guardian < 1){
                    cout << "Guardian has no more BABU to use.\n";
                    return stuff = false;
                }else{
                    do{
                        cout << "Do you want to use Guardian's BABU? \n1)Yes\t2)No\n";
                        cout << ">";
                        cin >> ans;
                    }while(ans != 1 && ans!= 2 && isdigit(ans));
                    if (ans == 1){
                        do{
                            x = rand()%8;
                            y = rand()%8;
                        }while (board[y][x] != "0");
                        board[y][x] = "❦";
                        cout << "BABU [❦] is randomly set on the board." << endl;
                        b_guardian--;
                        ba_bu++;
                        return stuff = false;
                    }else if (ans == 2){
                        return stuff = false;
                    }
                }
            case 3:
                return stuff = false;
            default:
                return stuff = false;
        }
    }
    
    bool Pieces_H::knight(string board[][size], int num, int character){
        int ans, direction, ans2;
        string ch_direc, ch_num, ch_ch, symbol;
        bool space = false;
        do{
            cout << "Do you want to move Knight or use Knight's BABU? \n1)move\t2)BABU\t3)Exit\n";
            cout << ">";
            cin >> ans;
        }while(ans != 1 && ans!= 2 && isdigit(ans));
        switch (ans){
            case 1:
                while (!v_move){
                    do{
                        do{
                            cout << "Which direction?\n";
                            cout << "1)up up right \t";
                            cout << "2)right up right \t";
                            cout << "3)up up left \n";
                            cout << "4)left up left \t";
                            cout << "5)down down right \t";
                            cout << "6)right down right \n";
                            cout << "7)down down left\t";
                            cout << "8)left down left \t";
                            cout << "9)Exit\n";
                            cout << ">";
                            cin >> ch_direc;
                            cout << endl;
                            try {
                                direction = stoi(ch_direc);
                            }
                            catch (exception err) {
                                cout << "Invalid Input." << endl;
                                direction = 0;
                            }
                            if (direction == 9){
                                return stuff = false;
                            }
                        }while(!((direction <= 8) && (isInteger(ch_direc) && (direction >=1))));
                        switch (direction) {
                            case 1://up up right
                                if (((num+1) < 2) && ((8-(character+1)) < 1)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(((num+1) >= 2) && ((8-(character+1)) >= 1)){
                                    space = true;
                                }
                                break;
                            case 2://right up right
                                if (((num+1) < 1) && ((8-(character+1)) < 2)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(((num+1) >= 1) && ((8-(character+1)) >= 2)){
                                    space = true;
                                }
                                break;
                            case 3://up up left
                                if (((num+1) < 2) && (character+1) < 1){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(((num+1) >= 2) && (character+1) >= 1){
                                    space = true;
                                }
                                break;
                            case 4://left up left
                                if (((num+1) < 1) && (character+1) < 2){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(((num+1) >= 1) && (character+1) >= 2){
                                    space = true;
                                }
                                break;
                            case 5://down down right
                                if ((8-(num+1) < 2) && (8-(character+1)) < 1){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(num+1) >= 2) && (8-(character+1)) >= 1){
                                    space = true;
                                }
                                break;
                            case 6://right down right
                                if ((8-(num+1) < 1) && (8-(character+1)) < 2){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(num+1) >= 1) && (8-(character+1)) >= 2){
                                    space = true;
                                }
                                break;
                            case 7://down down left
                                if ((8-(num+1) < 2) && (character+1) < 1){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(num+1) >= 2) && (character+1) >= 1){
                                    space = true;
                                }
                                break;
                            case 8://left down left
                                if ((8-(num+1) < 1) && (character+1) < 2){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(num+1) >= 1) && (character+1) >= 2){
                                    space = true;
                                }
                                break;
                            default:
                                break;
                        }
                    }while (!space);
                    move2(direction, "♘", board, num, character);
                }
                return stuff = true;
            case 2:
                do{
                    cout << "Do you want to use Knight's BABU? \n1)Yes\t2)No\n";
                    cout << ">";
                    cin >> ans2;
                }while(ans2 != 1 && ans2 != 2 && isdigit(ans2));
                if (ans2 == 1){
                    if (b_knight < 1){
                        cout << "Knight has no more BABU to use.\n";
                        return stuff = false;
                    }
                    else{
                        while (!v_move){
                            do{
                                do{
                                    cout << "Which direction?\n";
                                    cout << "1)up up right \t";
                                    cout << "2)right up right \t";
                                    cout << "3)up up left \n";
                                    cout << "4)left up left \t";
                                    cout << "5)down down right \t";
                                    cout << "6)right down right \n";
                                    cout << "7)down down left\t";
                                    cout << "8)left down left \n";
                                    cout << ">";
                                    cin >> ch_direc;
                                    cout << endl;
                                    try {
                                        direction = stoi(ch_direc);
                                    }
                                    catch (exception err) {
                                        cout << "Invalid Input." << endl;
                                        direction = 0;
                                    }
                                }while(!((direction <= 8) && (isInteger(ch_direc) && (direction >=1))));
                                switch (direction) {
                                    case 1://up up right
                                        if (((num+1) < 2) && ((8-(character+1)) < 1)){
                                            cout << "There's no enough BABU! \n";
                                            space = false;
                                        }else if(((num+1) >= 2) && ((8-(character+1)) >= 1)){
                                            space = true;
                                        }
                                        break;
                                    case 2://right up right
                                        if (((num+1) < 1) && ((8-(character+1)) < 2)){
                                            cout << "There's no enough BABU! \n";
                                            space = false;
                                        }else if(((num+1) >= 1) && ((8-(character+1)) >= 2)){
                                            space = true;
                                        }
                                        break;
                                    case 3://up up left
                                        if (((num+1) < 2) && (character+1) < 1){
                                            cout << "There's no enough BABU! \n";
                                            space = false;
                                        }else if(((num+1) >= 2) && (character+1) >= 1){
                                            space = true;
                                        }
                                        break;
                                    case 4://left up left
                                        if (((num+1) < 1) && (character+1) < 2){
                                            cout << "There's no enough BABU! \n";
                                            space = false;
                                        }else if(((num+1) >= 1) && (character+1) >= 2){
                                            space = true;
                                        }
                                        break;
                                    case 5://down down right
                                        if ((8-(num+1) < 2) && (8-(character+1)) < 1){
                                            cout << "There's no enough BABU! \n";
                                            space = false;
                                        }else if((8-(num+1) >= 2) && (8-(character+1)) >= 1){
                                            space = true;
                                        }
                                        break;
                                    case 6://right down right
                                        if ((8-(num+1) < 1) && (8-(character+1)) < 2){
                                            cout << "There's no enough BABU! \n";
                                            space = false;
                                        }else if((8-(num+1) >= 1) && (8-(character+1)) >= 2){
                                            space = true;
                                        }
                                        break;
                                    case 7://down down left
                                        if ((8-(num+1) < 2) && (character+1) < 1){
                                            cout << "There's no enough BABU! \n";
                                            space = false;
                                        }else if((8-(num+1) >= 2) && (character+1) >= 1){
                                            space = true;
                                        }
                                        break;
                                    case 8://left down left
                                        if ((8-(num+1) < 1) && (character+1) < 2){
                                            cout << "There's no enough BABU! \n";
                                            space = false;
                                        }else if((8-(num+1) >= 1) && (character+1) >= 2){
                                            space = true;
                                        }
                                        break;
                                    default:
                                        break;
                                }
                            }while (!space);
                            move2(direction, "♘", board, num, character);
                        }
                    }
                    b_knight--;
                    return stuff = false;
                }else if (ans2 == 2){
                    return stuff = false;
                }
            case 3:
                return stuff = false;
            default:
                return stuff = false;
        }
    }
    
    bool Pieces_H::assassin(string board[][size], int num, int character){
        int ans, direction, m_blocks, ans2, x, y;
        string ch_direc, ch_mblocks;
        bool space = false, no_chess = true;
        srand(time(NULL));
        do{
            cout << "Do you want to move Assassin or use Assassin's BABU? \n1)move\t2)move & attack\t3)BABU\t4)Exit\n";
            cout << ">";
            cin >> ans;
        }while(ans != 1 && ans!= 2 && isdigit(ans));
        switch (ans) {
            case 1:
                while (!v_move){
                        do{
                            cout << "Which direction?\n";
                            cout << "1)up \t";
                            cout << "2)down \t";
                            cout << "3)right \t";
                            cout << "4)left \n";
                            cout << "5)Exit \n";
                            cout << ">";
                            cin >> ch_direc;
                            cout << endl;
                            try {
                                direction = stoi(ch_direc);
                            }
                            catch (exception err) {
                                cout << "Invalid Input." << endl;
                                direction = 0;
                            }
                            if (direction == 5){
                                return stuff = false;
                            }
                        }while(!((direction <= 5) && (isInteger(ch_direc) && (direction >=1))));//ask direction
                        do{
                            do{//check for intergers
                                cout << "How many steps do you want to BABU? [9 to exit]" << endl;
                                cout << ">";
                                cin >> ch_mblocks;
                                try {
                                    m_blocks = stoi(ch_mblocks);
                                }
                                catch (exception err) {
                                    cout << "Invalid Input." << endl;
                                    m_blocks = 0;
                                }
                                if (m_blocks == 9)
                                    return stuff = false;
                            }while(!((m_blocks <= 9) && (isInteger(ch_mblocks) && (m_blocks >=1))));
                            switch (direction) {
                                case 1://up
                                    if (board[num-m_blocks][character] != "0"){
                                        cout << "You can't make the BABU! \n";
                                        space = false;
                                        no_chess = false;
                                    }else{
                                        for (int i = num-1; i > num-m_blocks; i--){
                                            if (board[i][character] != "0"){
                                                cout << "You can't make the BABU! \n";
                                                space = false;
                                                no_chess = false;
                                                break;
                                            }
                                        }
                                        if ((num+1) < m_blocks){
                                            cout << "There's no enough BABU! \n";
                                            space = false;
                                        }else if((num+1) >= m_blocks && no_chess == true){
                                            space = true;
                                        }
                                    }
                                    break;
                                case 2://down
                                    if (board[num+m_blocks][character] != "0"){
                                        cout << "You can't make the BABU! \n";
                                        space = false;
                                        no_chess = false;
                                    }else{
                                        for (int i = num+1; i < num+m_blocks; i++){
                                            if (board[i][character] != "0"){
                                                cout << "You can't make the BABU! \n";
                                                space = false;
                                                no_chess = false;
                                            }
                                        }
                                        if ((8-(num+1)) < m_blocks){
                                            cout << "There's no enough BABU! \n";
                                            space = false;
                                        }else if((8-(num+1)) >= m_blocks && no_chess == true){
                                            space = true;
                                        }
                                    }
                                    break;
                                case 3://right
                                    if (board[num][character+m_blocks] != "0"){
                                        cout << "You can't make the BABU! \n";
                                        space = false;
                                        no_chess = false;
                                    }else{
                                        for (int i = character+1; i < character+m_blocks; i--){
                                            if (board[num][i] != "0"){
                                                cout << "You can't make the BABU! \n";
                                                space = false;
                                                no_chess = false;
                                                break;
                                            }
                                        }
                                        if ((8-(character+1)) < m_blocks){
                                            cout << "There's no enough BABU! \n";
                                            space = false;
                                        }else if((8-(character+1)) >= m_blocks && no_chess == true){
                                            space = true;
                                        }
                                    }
                                    break;
                                case 4://left
                                    if (board[num][character-m_blocks] != "0"){
                                        cout << "You can't make the BABU! \n";
                                        space = false;
                                        no_chess = false;
                                    }else{
                                        for (int i = character-1; i > character-m_blocks; i--){
                                            if (board[num][i] != "0"){
                                                cout << "You can't make the BABU! \n";
                                                space = false;
                                                no_chess = false;
                                                break;
                                            }
                                        }
                                        if (character+1 < m_blocks){
                                            cout << "There's no enough BABU! \n";
                                            space = false;
                                        }else if(character+1 >= m_blocks && no_chess == true){
                                            space = true;
                                        }
                                    }
                                    break;
                                default:
                                    break;
                            }
                        }while (!space);
                    move(direction, m_blocks, "☽", board, num, character);
                    }
                return stuff = true;
            case 2:
                while(!v_move){
                    do{
                        do{
                            cout << "Which direction?\n";
                            cout << "1)up \t";
                            cout << "2)down \t";
                            cout << "3)right \t";
                            cout << "4)left \t";
                            cout << "5)Exit \n";
                            cout << ">";
                            cin >> ch_direc;
                            cout << endl;
                            try {
                                direction = stoi(ch_direc);
                            }
                            catch (exception err) {
                                cout << "Invalid Input." << endl;
                                direction = 0;
                            }
                            if (direction == 5){
                                return stuff = false;
                            }
                        }while(!((direction <= 5) && (isInteger(ch_direc) && (direction >=1))));//ask direction
                        switch (direction) {
                            case 1://up
                                if ((num+1) < 2){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((num+1) >= 2){
                                    space = true;
                                }
                                break;
                            case 2://down
                                if ((8-(num+1)) < 2){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(num+1)) >= 2){
                                    space = true;
                                }
                                break;
                            case 3://right
                                if ((8-(character+1)) < 2){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(character+1)) >= 2){
                                    space = true;
                                }
                                break;
                            case 4://left
                                if (character+1 < 2){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(character+1 >= 2){
                                    space = true;
                                }
                            default:
                                break;
                        }
                    }while (!space);
                    move_jump(direction, "☽", board, num, character);
                }
                return stuff = true;
            case 3:
                do{
                    cout << "Do you want to use Assassin's BABU? \n1)Yes\t2)No\n";
                    cout << ">";
                    cin >> ans2;
                }while(ans2 != 1 && ans2 != 2 && isdigit(ans2));
                switch (ans2) {
                    case 1:
                        if(b_assassin < 1){
                            cout << "Assassin has no more BABU to use.\n";
                            return stuff = false;
                        }else{
                            do{
                                x = rand()%8;
                                y = rand()%8;
                            }while (board[y][x] != "0");
                            board[y][x] = board[num][character];
                            board[num][character] = "0";
                            cout << "Assassin has been sent to a random block on the BABU!\n";
                            b_assassin--;
                            return stuff = false;
                        }
                    case 2:
                        return stuff = false;
                    default:
                        return stuff = false;
                }
            case 4:
                return stuff = false;
            default:
                return stuff = false;
        }
    }
    
    bool Pieces_H::priest(string board[][size], int num, int character){
        int ans, direction, m_blocks, ans2, x, y, chess, j;
        bool space = true, no_chess = true;
        string ch_direc, ch_mblocks;
        srand(time(NULL));
        do{
            cout << "Do you want to move Priest or use Priest's BABU? \n1)move\t2)BABU\t3)Exit\n";
            cout << ">";
            cin >> ans;
        }while(ans != 1 && ans!= 2 && isdigit(ans));
        switch (ans) {
            case 1:
                while (!v_move){
                    do{
                        cout << "Which direction?\n";
                        cout << "1)up right \t";//5
                        cout << "2)up left \n";//6
                        cout << "3)down left\t";//7
                        cout << "4)down right \n";//8
                        cout << "5)Exit \n";
                        cout << ">";
                        cin >> ch_direc;
                        cout << endl;
                        try {
                            direction = stoi(ch_direc);
                        }
                        catch (exception err) {
                            cout << "Invalid Input." << endl;
                            direction = 0;
                        }
                        if (direction == 5){
                            return stuff = false;
                        }
                    }while(!((direction <= 5) && (isInteger(ch_direc) && (direction >=1))));
                    //ask and check direction
                    do{
                        do{//check for intergers
                            cout << "How many steps do you want to BABU? [9 to exit]" << endl;
                            cout << ">";
                            cin >> ch_mblocks;
                            try {
                                m_blocks = stoi(ch_mblocks);
                            }
                            catch (exception err) {
                                cout << "Invalid Input." << endl;
                                m_blocks = 0;
                            }
                            if (m_blocks == 9)
                                return stuff = false;
                        }while(!((m_blocks <= 9) && (isInteger(ch_mblocks) && (m_blocks >=1))));
                        switch (direction) {
                            case 1://up right
                                
                                if(((num+1) >= m_blocks) && ((8-(character+1)) >= m_blocks)){
                                    space = true;
                                    
                                }else if (((num+1) < m_blocks) && ((8-(character+1)) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                break;
                            case 2://up left
                                
                                if(((num+1) >= m_blocks) && ((character+1) >= m_blocks)){
                                    space = true;
                                }
                                else if (((num+1) < m_blocks) && ((character+1) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                break;
                            case 3:
                                j = character-1;
                                
                                if(((8-(num+1)) >= m_blocks) && ((character+1) >= m_blocks )){
                                    space = true;
                                }
                                else if (((8-(num+1)) < m_blocks) && ((character+1) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                break;
                            case 4:
                                
                                if(((8-(num+1)) >= m_blocks) && ((8-(character+1)) >= m_blocks) ){
                                    space = true;
                                }
                                else if (((8-(num+1)) < m_blocks) && ((8-(character+1)) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                break;
                            default:
                                break;
                        }//checl m_block validation
                    }while (!space);
                    move((direction+4), m_blocks, "✙", board, num, character);
                }
                return stuff = true;
                break;
            case 2:
                do{
                    cout << "Do you want to use Priest's BABU? \n1)Yes\t2)No\n";
                    cout << ">";
                    cin >> ans2;
                }while(ans2 != 1 && ans2 != 2 && isdigit(ans2));
                switch (ans2) {
                    case 1:
                        if (b_priest < 1){
                            cout << "Priest has no more BABU to use.\n";
                            return stuff = false;
                        }else{
                            do{
                                x = rand()%8;
                                y = rand()%8;
                            }while (board[y][x] != "0");
                            chess = rand()%4+1;
                            switch (chess) {
                                case 1:
                                    board[y][x] = "☽";
                                    cout << "Priest summoned an Assassin.\n";
                                    b_assassin++;
                                    break;
                                case 2:
                                    board[y][x] = "♘";
                                    cout << "Priest summoned a Knight.\n";
                                    kn_ight++;
                                    break;
                                case 3:
                                    board[y][x] = "♢";
                                    cout << "Priest summoned a Guardian.\n";
                                    Guar++;
                                    break;
                                case 4:
                                    board[y][x] = "ꆜ";
                                    cout << "Priest summoned a Villager.\n";
                                    murabito++;
                                    break;
                                default:
                                    break;
                            }
                            b_priest--;
                            return stuff = false;
                        }
                    case 2:
                        return stuff = false;
                    default:
                        return stuff = false;
                }
            case 3:
                return stuff = false;
            default:
                return stuff = false;
        }
    }
    
    bool Pieces_H::villager(string board[][size], int num, int character){
        int direction, m_blocks = 1;
        bool space = false, no_chess = true;
        string ch_direc;
        while (!v_move){
            while (!space){
                do{
                    cout << "Which direction?\n";
                    cout << "1)up \t";
                    cout << "2)down \t";
                    cout << "3)right \t";
                    cout << "4)left \t";
                    cout << "5)Exit \n";
                    cout << ">";
                    cin >> ch_direc;
                    cout << endl;
                    try {
                        direction = stoi(ch_direc);
                    }
                    catch (exception err) {
                        cout << "Invalid Input." << endl;
                        direction = 0;
                    }
                    if (direction == 5){
                        return stuff = false;
                    }
                }while(!((direction <= 4) && (isInteger(ch_direc) && (direction >=1))));//ask direction
                switch (direction) {
                    case 1://up
                        if ((num+1) < m_blocks){
                            cout << "There's no enough BABU! \n";
                            space = false;
                        }else if((num+1) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 2://down
                        if ((8-(num+1)) < m_blocks){
                            cout << "There's no enough BABU! \n";
                            space = false;
                        }else if((8-(num+1)) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 3://right
                        if ((8-(character+1)) < m_blocks){
                            cout << "There's no enough BABU! \n";
                            space = false;
                        }else if((8-(character+1)) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 4://left
                        if (character+1 < m_blocks){
                            cout << "There's no enough BABU! \n";
                            space = false;
                        }else if(character+1 >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                }//check space
            }
            move(direction, m_blocks, "ꆜ", board, num, character);
        }
        return stuff = true;
    }
    
    bool Pieces_H::babu(string board[][size], int num, int character){
        int direction, m_blocks = 2, ans, ans2;
        string ch_direc;
        bool space = false, no_chess = true, set_y;
        do{
            cout << "Do you want to move Babu or use Babu's BABU? \n1)move\t2)BABU\t3)Exit\n";
            cout << ">";
            cin >> ans;
        }while(ans != 1 && ans!= 2 && isdigit(ans));
        switch (ans) {
            case 1:
                while (!v_move){
                    do{
                        do{
                            cout << "Which direction?\n";
                            cout << "1)up right \t";//5
                            cout << "2)up left \n";//6
                            cout << "3)down left\t";//7
                            cout << "4)down right \n";//8
                            cout << "5)Exit \n";
                            cout << ">";
                            cin >> ch_direc;
                            cout << endl;
                            try {
                                direction = stoi(ch_direc);
                            }
                            catch (exception err) {
                                cout << "Invalid Input." << endl;
                                direction = 0;
                            }
                            if (direction == 5){
                                return stuff = false;
                            }
                        }while(!((direction <= 5) && (isInteger(ch_direc) && (direction >=1))));
                        //ask and check direction
                        switch (direction) {
                            case 1://up right
                                for (int i = num; i > num-m_blocks; i--){
                                    for(int j = character; j < character+m_blocks; j++){
                                        if (board[i][j] != "0"){
                                            cout << "You can't make the BABU! \n";
                                            space = false;
                                            no_chess = true;
                                            break;
                                        }
                                    }
                                }
                                if (((num+1) < m_blocks) && ((8-(character+1)) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(((num+1) >= m_blocks) && ((8-(character+1)) >= m_blocks) && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 2://up left
                                for (int i = num; i > num-m_blocks; i--){
                                    for(int j = character; j > character-m_blocks; j--){
                                        if (board[i][j] != "0"){
                                            cout << "You can't make the BABU! \n";
                                            space = false;
                                            no_chess = true;
                                            break;
                                        }
                                    }
                                }
                                if (((num+1) < m_blocks) && ((character+1) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(((num+1) >= m_blocks) && ((character+1) >= m_blocks) && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 3:
                                for (int i = num; i < num+m_blocks; i++){
                                    for(int j = character; j > character-m_blocks; j--){
                                        if (board[i][j] != "0"){
                                            cout << "You can't make the BABU! \n";
                                            space = false;
                                            no_chess = true;
                                            break;
                                        }
                                    }
                                }
                                if (((8-(num+1)) < m_blocks) && ((character+1) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(((8-(num+1)) >= m_blocks) && ((character+1) >= m_blocks) && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 4:
                                for (int i = num; i < num+m_blocks; i++){
                                    for(int j = character; j < character+m_blocks; j++){
                                        if (board[i][j] != "0"){
                                            cout << "You can't make the BABU! \n";
                                            space = false;
                                            no_chess = true;
                                            break;
                                        }
                                    }
                                }
                                if (((8-(num+1)) < m_blocks) && ((8-(character+1)) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(((8-(num+1)) >= m_blocks) && ((8-(character+1)) >= m_blocks) && no_chess == true){
                                    space = true;
                                }
                                break;
                                
                            default:
                                break;
                        }//checl m_block validation
                    }while (!space);
                    move((direction+4), m_blocks, "❦", board, character, num);
                }
                return stuff = true;
            case 2:
                do{
                    cout << "Do you want to use Babu's BABU? \n1)Yes\t2)No\n";
                    cout << ">";
                    cin >> ans2;
                }while(ans2 != 1 && ans2 != 2 && isdigit(ans2));
                if (ans2 == 1){
                    if(ba_bu < 1){
                        cout << "Babu has no more BABU to use.\n";
                        return stuff = false;
                    }else{
                        for (int i = 0; i < 8; i++){
                            for (int j = 0; j < 8; j++){
                                if (board[i][j] == "♕"){
                                    ask(board, "♕");
                                    board[i][j] = "0";
                                    set_y = true;
                                    break;
                                }
                            }
                            if (set_y == true){
                                break;
                            }
                        }
                        return stuff = false;
                    }
                }else if (ans2 == 2){
                    return stuff = false;
                }
            case 3:
                return stuff = false;
            default:
                return stuff = false;
        }
    }
    
    bool Pieces_H::champion(string board[][size], int num, int character){
        int ans, direction, m_blocks, ans2, j;
        bool space = true, no_chess = true;
        string ch_direc, ch_mblocks;
        do{
            cout << "Do you want to move Champion or use Champion's BABU? \n1)move\t2)BABU\t3)Exit\n";
            cout << ">";
            cin >> ans;
        }while(ans != 1 && ans!= 2 && isdigit(ans));
        switch (ans) {
            case 1:
                while (!v_move){
                    do{
                        cout << "Which direction?\n";
                        cout << "1)up \t";
                        cout << "2)right \n";
                        cout << "3)left \t";
                        cout << "4)up right \t";
                        cout << "5)up left \n";
                        cout << "6)Exit \n";
                        cout << ">";
                        cin >> ch_direc;
                        cout << endl;
                        try {
                            direction = stoi(ch_direc);
                        }
                        catch (exception err) {
                            cout << "Invalid Input." << endl;
                            direction = 0;
                        }
                        if (direction == 6){
                            return stuff = false;
                        }
                    }while(!((direction <= 6) && (isInteger(ch_direc) && (direction >=1))));
                    //ask and check direction
                    do{
                        do{//check for intergers
                            cout << "How many steps do you want to BABU? [9 to exit]" << endl;
                            cout << ">";
                            cin >> ch_mblocks;
                            try {
                                m_blocks = stoi(ch_mblocks);
                            }
                            catch (exception err) {
                                cout << "Invalid Input." << endl;
                                m_blocks = 0;
                            }
                            if (m_blocks == 9)
                                return stuff = false;
                        }while(!((m_blocks <= 9) && (isInteger(ch_mblocks) && (m_blocks >=1))));
                        switch (direction) {
                            case 1://up
                                
                                if ((num+1) < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((num+1) >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 2://right
                                
                                if ((8-(character+1)) < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(character+1)) >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                direction = direction+1;
                                break;
                            case 3://left
                                
                                if (character+1 < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(character+1 >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                direction = direction+1;
                                break;
                            case 4://up right
                                
                                if(((num+1) >= m_blocks) && ((8-(character+1)) >= m_blocks)){
                                    space = true;
                                }else if (((num+1) < m_blocks) && ((8-(character+1)) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                direction = direction+1;
                                break;
                            case 5://up left
                                
                                if(((num+1) >= m_blocks) && ((character+1) >= m_blocks)){
                                    space = true;
                                }
                                else if (((num+1) < m_blocks) && ((character+1) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                direction = direction+1;
                                break;
                            case 0:
                                return stuff = false;
                            default:
                                break;
                        }//checl m_block validation
                    }while (!space);
                    move(direction, m_blocks, "卍", board, character, num);
                }
                return stuff = true;
            case 2:
                do{
                    cout << "Do you want to use Champion's BABU? \n1)Yes\t2)No\n";
                    cout << ">";
                    cin >> ans2;
                }while(ans2 != 1 && ans2 != 2 && isdigit(ans2));
                if(ans2 == 1){
                    if(b_champ < 1){
                        cout << "Champion has no more BABU to use.\n";
                        return stuff = false;
                    }else{
                        do{
                            do{//check for intergers
                                cout << "How many steps do you want to move back BABU?" << endl;
                                cout << ">";
                                cin >> ch_mblocks;
                                try {
                                    m_blocks = stoi(ch_mblocks);
                                }
                                catch (exception err) {
                                    cout << "Invalid Input." << endl;
                                    m_blocks = 0;
                                }
                            }while(!((m_blocks <= 8) && (isInteger(ch_mblocks) && (m_blocks >=1))));
                            if ((8-(num+1)) < m_blocks){
                                cout << "There's no enough BABU! \n";
                                space = false;
                            }else if((8-(num+1)) >= m_blocks){
                                space = true;
                            }
                        }while(!space);
                        return stuff = false;
                    }
                }else if (ans2 == 2){
                    return stuff = false;
                }
            case 3:
                return stuff = false;
            default:
                return stuff = false;
        }
    }
    
    bool Pieces_H::fool(string board[][size], int num, int character){
        int direction, m_blocks, j;
        bool space = false, no_chess = true;
        srand(time(NULL));
        while (!v_move){
            do{
                direction = rand()%8;
                m_blocks = rand()%8;
                switch (direction) {
                    case 1://up
                       
                        if ((num+1) < m_blocks){
                            space = false;
                        }else if((num+1) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 2://down
                        
                        if ((8-(num+1)) < m_blocks){
                            space = false;
                        }else if((8-(num+1)) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 3://right
                        
                        if ((8-(character+1)) < m_blocks){
                            space = false;
                        }else if((8-(character+1)) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 4://left
                       
                        if (character+1 < m_blocks){
                            space = false;
                        }else if(character+1 >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 5://up right
                        
                        if(((num+1) >= m_blocks) && ((8-(character+1)) >= m_blocks)){
                            space = true;
                        
                        }else if (((num+1) < m_blocks) && ((8-(character+1)) < m_blocks)){
                            space = false;
                        }
                        break;
                    case 6://up left
                        
                        if(((num+1) >= m_blocks) && ((character+1) >= m_blocks)){
                            space = true;
                        }
                        else if (((num+1) < m_blocks) && ((character+1) < m_blocks)){
                            space = false;
                        }
                        break;
                    case 7:
                        
                        if(((8-(num+1)) >= m_blocks) && ((character+1) >= m_blocks )){
                            space = true;
                        }
                        else if (((8-(num+1)) < m_blocks) && ((character+1) < m_blocks)){
                            space = false;
                        }
                        break;
                    case 8:
                        
                        if(((8-(num+1)) >= m_blocks) && ((8-(character+1)) >= m_blocks) ){
                            space = true;
                        }
                        else if (((8-(num+1)) < m_blocks) && ((8-(character+1)) < m_blocks)){
                            space = false;
                        }
                        break;
                    default:
                        break;
                }//checl m_block validation
            }while (!space);
            move(direction, m_blocks, "Ѷ", board, num, character);
        }
        
        return stuff = true;
    }




    bool Pieces_A::isInteger(string str){
        int num;
        istringstream iss (str);
        
        iss >> num;
        
        return !iss.fail();
    }
    
    void Pieces_A::showBoard(string board[][size]){
        int character = 0;
        char ch = 'A';
        cout << "\t" << "\t";
        for (int k = 0; k < size; k++){
            character = int(ch);
            cout << ch << "\t";
            character++;
            ch = char(character);
        }
        cout << endl;
        cout << "\t" << "\t";
        for (int k = 0; k < size; k++){
            cout << "-" << "\t";
        }
        cout << endl;
        for (int i = 0; i < size; i++){
            cout << i+1 << "\t" << "|" << "\t";
            for (int j = 0; j < size; j++){
                cout << board[i][j] << "\t";
            }
            cout << "\n\n";
            if (i == 3){
                cout << "\t --------------------------------"<<"\n\n";
            }
        }
    }
    
    bool Pieces_A::validPieces(string symbol, string enemy){
        if (symbol == "♚" && (enemy == "♔"||enemy == "♢"||enemy == "♘"||enemy == "☽"||enemy == "✙"||enemy == "ꆜ"||enemy == "Ѷ"||enemy == "❦"))
            return true;
        else if ((symbol == "♚" && (enemy == "♔"||enemy == "♢"||enemy == "♘"||enemy == "☽"||enemy == "✙"||enemy == "ꆜ"||enemy == "Ѷ"||enemy == "❦")))
            return false;
        if (symbol == "웃" && (enemy == "♢"||enemy == "♘"||enemy == "☽"||enemy == "✙"||enemy == "ꆜ"||enemy == "Ѷ"||enemy == "❦"))
            return true;
        else if ((symbol == "웃" && (enemy == "♢"||enemy == "♘"||enemy == "☽"||enemy == "✙"||enemy == "ꆜ"||enemy == "Ѷ"||enemy == "❦")))
            return false;
        if (symbol == "↭" && (enemy == "♘"||enemy == "☽"||enemy == "✙"||enemy == "ꆜ"||enemy == "Ѷ"||enemy == "❦"))
            return true;
        else if ((symbol == "↭" && (enemy == "♘"||enemy == "☽"||enemy == "✙"||enemy == "ꆜ"||enemy == "Ѷ"||enemy == "❦")))
            return false;
        if (symbol == "𝕲" && (enemy == "♕"||enemy == "♔"||enemy == "♢"||enemy == "♘"||enemy == "☽"||enemy == "✙"||enemy == "ꆜ"||enemy == "Ѷ"||enemy == "❦"||enemy == "卍"))
            return true;
        else if ((symbol == "𝕲" && (enemy == "♕"||enemy == "♔"||enemy == "♢"||enemy == "♘"||enemy == "☽"||enemy == "✙"||enemy == "ꆜ"||enemy == "Ѷ"||enemy == "❦"||enemy == "卍")))
            return false;
        if (symbol == "✡" && (enemy == "♢"||enemy == "♘"||enemy == "☽"||enemy == "✙"||enemy == "ꆜ"||enemy == "Ѷ"||enemy == "❦"))
            return true;
        else if ((symbol == "✡" && (enemy == "♢"||enemy == "♘"||enemy == "☽"||enemy == "✙"||enemy == "ꆜ"||enemy == "Ѷ"||enemy == "❦")))
            return false;
        if (symbol == "⍢" && (enemy == "♕"||enemy == "Ѷ"||enemy == "ꆜ"))
            return true;
        else if ((symbol == "⍢" && (enemy == "♕"||enemy == "Ѷ"||enemy == "ꆜ")))
            return false;
        if (symbol == "☠" && (enemy == "Ѷ"||enemy == "ꆜ"))
            return true;
        else if ((symbol == "☠" && (enemy == "Ѷ"||enemy == "ꆜ")))
            return false;
        if (symbol == "☫" && (enemy == "♕"||enemy == "♔"||enemy == "♢"||enemy == "♘"||enemy == "☽"||enemy == "✙"||enemy == "ꆜ"||enemy == "Ѷ"||enemy == "❦"||enemy == "卍"))
            return true;
        else if ((symbol == "☫" && (enemy == "♕"||enemy == "♔"||enemy == "♢"||enemy == "♘"||enemy == "☽"||enemy == "✙"||enemy == "ꆜ"||enemy == "Ѷ"||enemy == "❦"||enemy == "卍")))
            return false;
        if (symbol == "❦" && (enemy == "♕"||enemy == "♔"||enemy == "♢"||enemy == "♘"||enemy == "☽"||enemy == "✙"||enemy == "ꆜ"||enemy == "Ѷ"||enemy == "❦"))
            return true;
        else if ((symbol == "❦" && (enemy == "♕"||enemy == "♔"||enemy == "♢"||enemy == "♘"||enemy == "☽"||enemy == "✙"||enemy == "ꆜ"||enemy == "Ѷ"||enemy == "❦"))){
            return false;
        }
        if (symbol == "〠" && (enemy == "♔"||enemy == "♢"||enemy == "♘"||enemy == "☽"||enemy == "✙"||enemy == "ꆜ"||enemy == "Ѷ"||enemy == "❦"))
            return true;
        else
            return false;
    }
    
    void Pieces_A::ask(string board[][size], string symbol){
        string ch_num, ch_ch;
        int num, character, num2;
        bool empty;
        char ch;
        do{
            do{
                cout << "Enter the location(num): ";
                cin >> ch_num;
                cout << endl;
                try {
                    num = stoi(ch_num);
                }
                catch (exception err) {
                    cout << "Invalid Input." << endl;
                    num = 0;
                }
            }while(!((num <= 8) && (isInteger(ch_num) && (num >=1))));
            getchar();
            do{
                system("stty raw");
                cout << "Enter the location(char): ";
                ch = getchar();
                cout << endl;
                ch = toupper(ch);
            }while(!((ch >= 'A') && (ch <= 'J')&& (!isInteger(ch_ch))));
            character = 0;
            character = (int(ch) - 64)-1;
            num2 = num-1;
            if (board[num2][character] != "0"){
                cout << "There's stuff at that spot BABU!" << endl;
                empty = false;
            }else{
                empty = true;
            }
        }while(!empty);
        board[num2][character] = symbol;
    }
    
    void Pieces_A::pieceType(string board[][size], string symbol){
        int x, y, fool_chance;
        srand(time(NULL));
        if (symbol == "♢"){
            Guar--;
        }else if (symbol == "♘"){
            kn_ight--;
        }else if(symbol == "ꆜ"){
            murabito--;
            if(murabito < 3 && the_fool == 1){
                fool_chance = rand()%2;
                if (fool_chance == 0){
                    do{
                        x = rand()%8;
                        y = rand()%8;
                    }while(board[y][x] != "0");
                    board[y][x] = "Ѷ";
                    the_fool--;
                }
            }else if (murabito == 0 && champ == 1){
                do{
                    x = rand()%8;
                    y = rand()%8;
                }while(board[y][x] != "0");
                board[y][x] = "卍";
                champ--;
                ch_ampion++;
            }
        }else if(symbol == "☽"){
            ass_assin--;
        }else if(symbol == "♕"){
            win = true;
        }
    }
    
    bool Pieces_A::move (int direction, int m_blocks, string symbol, string board[][size], int num, int character){
        string enemy;
        int j = character, i;
        switch (direction) {
            case 1://up
                enemy = board[num-m_blocks][character];
                symbol = board[num][character];
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num-m_blocks][character] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num-m_blocks][character] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 2://down
                enemy = board[num+m_blocks][character];
                symbol = board[num][character];
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num+m_blocks][character] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num+m_blocks][character] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 3://right
                enemy = board[num][character+m_blocks];
                symbol = board[num][character];
                if (board[num][character+m_blocks] != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num][character+m_blocks] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num][character+m_blocks] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 4://left
                enemy = board[num][character-m_blocks];
                symbol = board[num][character];
                if (board[num][character-m_blocks] != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num][character-m_blocks] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num][character-m_blocks] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 5://up right
                j = character;
                for (i = num; i > num-m_blocks; i--){
                    j++;
                }
                enemy = board[i][j];
                symbol = board[num][character];
                if (board[i][j] != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[i][j] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[i][j] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 6://up left
                j = character;
                for (i = num; i > num-m_blocks; i--){
                    j--;
                }
                enemy = board[i][j];
                symbol = board[num][character];
                if (board[i][j] != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[i][j] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[i][j] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 7://down left
                j = character;
                for (i = num; i < num+m_blocks; i++){
                    j--;
                }
                enemy = board[i][j];
                symbol = board[num][character];
                if (board[i][j] != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[i][j] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[i][j] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 8://down right
                j = character;
                for (i = num; i < num+m_blocks; i++){
                    j++;
                }
                enemy = board[i][j];
                symbol = board[num][character];
                if (board[i][j] != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[i][j] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[i][j] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            default:
                return v_move = true;
        }
    }
    
    bool Pieces_A::move2(int direction, string symbol, string board[][size], int num, int character){
        string enemy;
        switch (direction){
            case 1:
                symbol = board[num][character];
                enemy = board[num-2][character+1];
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num-2][character+1] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num-2][character+1] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 2:
                symbol = board[num][character];
                enemy = board[num-1][character+2];
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num-1][character+2] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num-1][character+2] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 3:
                symbol = board[num][character];
                enemy = board[num-2][character-1];
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num-2][character-1] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num-2][character-1] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 4:
                symbol = board[num][character];
                enemy = board[num-1][character-2];
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        enemy = board[num-1][character-2] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    enemy = board[num-1][character-2] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 5:
                symbol = board[num][character];
                enemy = board[num+2][character+1];
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num+2][character+1] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num+2][character+1] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 6:
                symbol = board[num][character];
                enemy = board[num+1][character+2];
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num+1][character+2] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num+1][character+2] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 7:
                symbol = board[num][character];
                enemy = board[num+2][character-1];
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num+2][character-1] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num+2][character-1] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            case 8:
                symbol = board[num][character];
                enemy = board[num+1][character-2];
                if (enemy != "0"){
                    if (validPieces(symbol, enemy)){
                        cout << enemy << " killed by " << symbol << " BABU!" << endl;
                        board[num+1][character-2] = board [num][character];
                        board[num][character] = "0";
                        pieceType(board,enemy);
                        return v_move = true;
                    }else if (!validPieces(symbol, enemy)){
                        cout << symbol << " cannot kill " << enemy << endl;
                        return v_move = false;//try again
                    }
                }else{
                    board[num+1][character-2] = board [num][character];
                    board[num][character] = "0";
                    return v_move = true;
                }
            default:
                return v_move = true;
        }
    }
    
    void Pieces_A::move_jump (int direction, string symbol, string board[][size], int num, int character){
        int count, m_blocks;
        switch (direction){
            case 1: //up
                count = 0;
                m_blocks = 1;
                for (int i = num-1; i > 0; i--){
                    m_blocks++;
                    if (board [i][character] != "0"){
                        count++;
                    }
                    if (count == 2){
                        break;
                    }
                }
                move(1, m_blocks, symbol, board, num, character);
                break;
            case 2: //down
                count = 0;
                m_blocks = 1;
                for (int i = num; i < (8-num); i++){
                    m_blocks++;
                    if (board [i][character] != "0"){
                        count++;
                    }
                    if (count == 2){
                        break;
                    }
                }
                move(2, m_blocks, symbol, board, num, character);
                break;
            case 3: //right
                count = 0;
                m_blocks = 1;
                for (int i = character; i > (8-character); i++){
                    m_blocks++;
                    if (board [num][i] != "0"){
                        count++;
                    }
                    if (count == 2){
                        break;
                    }
                }
                move(3, m_blocks, symbol, board, num, character);
                break;
            case 4: //left
                count = 0;
                m_blocks = 1;
                for (int i = character; i > 0; i--){
                    m_blocks++;
                    if (board [num][i] != "0"){
                        count++;
                    }
                    if (count == 2){
                        break;
                    }
                }
                move(4, m_blocks, symbol, board, num, character);
                break;
        }
    }

    
    string trap_piece;
    
    bool Pieces_A::lord(string board[][size], int num, int character){
        int ans;
        do{
            cout << "Do you want to use Lord's BABU? \n1)Yes\t2)No\n";
            cout << ">";
            cin >> ans;
        }while(ans != 1 && ans!= 2 && isdigit(ans));
        switch (ans) {
            case 1:
                if (b_lord != 1){
                    cout << "Lord has no more BABU to use.\n";
                }else{
                    cout << "Summon Skeleton x4 BABU!" << endl;
                    for (int i = 0; i < 4; i++){
                        ask(board, "☠");
                        cout << "Skeleton summoned." << (4-(i+1)) << " more ☠ left." << endl;
                        showBoard(board);
                    }
                    b_lord--;
                }
                return stuff = false;
                break;
            case 2:
                return stuff = false;
                break;
            default:
                return stuff = false;
                break;
        }
    }
    
    bool Pieces_A::gabriel(string board[][size], int num, int character, int round){
        int ans, direction, m_blocks, ans2, x, y, j;
        bool space = true, no_chess = true;
        string ch_direc, ch_mblocks;
        srand(time(NULL));
        do{
            cout << "Do you want to move Gabriel or use Gabriel's BABU? \n1)move\t2)BABU\t3)Exit\n";
            cout << ">";
            cin >> ans;
        }while(ans != 1 && ans!= 2 && isdigit(ans));
        switch (ans) {
            case 1:
                while (!v_move){
                    do{
                        cout << "Which direction?\n";
                        cout << "1)up \t";
                        cout << "2)down \t";
                        cout << "3)right \n";
                        cout << "4)left \t";
                        cout << "5)up right \t";
                        cout << "6)up left \n";
                        cout << "7)down left\t";
                        cout << "8)down right \t";
                        cout << "9)Exit \n";
                        cout << ">";
                        cin >> ch_direc;
                        cout << endl;
                        try {
                            direction = stoi(ch_direc);
                        }
                        catch (exception err) {
                            cout << "Invalid Input." << endl;
                            direction = 0;
                        }
                        if (direction == 9){
                            return stuff = false;
                        }
                    }while(!((direction <= 9) && (isInteger(ch_direc) && (direction >=1))));
                    //ask and check direction
                    do{
                        do{//check for intergers
                            cout << "How many steps do you want to BABU? [9 to exit]" << endl;
                            cout << ">";
                            cin >> ch_mblocks;
                            try {
                                m_blocks = stoi(ch_mblocks);
                            }
                            catch (exception err) {
                                cout << "Invalid Input." << endl;
                                m_blocks = 0;
                            }
                            if (m_blocks == 9)
                                return stuff = false;
                        }while(!((m_blocks <= 9) && (isInteger(ch_mblocks) && (m_blocks >=1))));
                        switch (direction) {
                            case 1://up
                                
                                if ((num+1) < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((num+1) >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 2://down
                                
                                if ((8-(num+1)) < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(num+1)) >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 3://right
                                
                                if ((8-(character+1)) < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(character+1)) >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 4://left
                                
                                if (character+1 < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(character+1 >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 5://up right
                                
                                if(((num+1) >= m_blocks) && ((8-(character+1)) >= m_blocks)){
                                    space = true;
                                }else if (((num+1) < m_blocks) && ((8-(character+1)) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                break;
                            case 6://up left
                                
                                if(((num+1) >= m_blocks) && ((character+1) >= m_blocks)){
                                    space = true;
                                }
                                else if (((num+1) < m_blocks) && ((character+1) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                break;
                            case 7:
                                
                                if(((8-(num+1)) >= m_blocks) && ((character+1) >= m_blocks )){
                                    space = true;
                                }
                                else if (((8-(num+1)) < m_blocks) && ((character+1) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                break;
                            case 8:
                                
                                if(((8-(num+1)) >= m_blocks) && ((8-(character+1)) >= m_blocks) ){
                                    space = true;
                                }
                                else if (((8-(num+1)) < m_blocks) && ((8-(character+1)) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                break;
                            default:
                                break;
                        }//checl m_block validation
                    }while (!space);
                    move(direction, m_blocks, "♚", board, character, num);
                }
                return stuff = true;
            case 2:
                if (round >= 5){
                    do{
                        cout << "Do you want to use Gabriel's BABU? \n1)Yes\t2)No\n";
                        cout << ">";
                        cin >> ans2;
                    }while(ans2 != 1 && ans2 != 2 && isdigit(ans2));
                    if (b_gabriel < 1){
                        cout << "Gabriel has no more BABU to use.\n";
                        return stuff = false;
                    }else{
                        if (ans2 == 1){
                            do{
                                x = rand()%8;
                                y = rand()%8;
                            }while(board[y][x] != "0");
                            bomb_x = x;
                            bomb_y = y;
                            cout << "Bomb randomly setted on BABU!\n";
                            b_gabriel--;
                            return stuff = false;
                        }else if (ans2 == 2){
                            return stuff = false;
                        }
                    }
                }else{
                    cout << "Gabriel's BABU is not avaliable right now." << endl;
                    return stuff = false;
                }
            case 3:
                return stuff = false;
            default:
                return stuff = false;
        }
    }
    
    bool Pieces_A::vampire(string board[][size], int num, int character){
        int ans, direction, ans2, x, y;
        string ch_direc, ch_num, ch_ch, symbol;
        bool space = false;
        srand (time(NULL));
        do{
            cout << "Do you want to move Vampire or use Vampire's BABU? \n1)move\t2)BABU\t3)Exit\n";
            cout << ">";
            cin >> ans;
        }while(ans != 1 && ans!= 2 && isdigit(ans));
        switch (ans){
            case 1:
                while (!v_move){
                    do{
                        do{
                            cout << "Which direction?\n";
                            cout << "1)up up right \t";
                            cout << "2)right up right \t";
                            cout << "3)up up left \n";
                            cout << "4)left up left \t";
                            cout << "5)down down right \t";
                            cout << "6)right down right \n";
                            cout << "7)down down left\t";
                            cout << "8)left down left \t";
                            cout << "9)Exit\n";
                            cout << ">";
                            cin >> ch_direc;
                            cout << endl;
                            try {
                                direction = stoi(ch_direc);
                            }
                            catch (exception err) {
                                cout << "Invalid Input." << endl;
                                direction = 0;
                            }
                            if (direction == 9){
                                return stuff = false;
                            }
                        }while(!((direction <= 8) && (isInteger(ch_direc) && (direction >=1))));
                        switch (direction) {
                            case 1://up up right
                                if (((num+1) < 2) && ((8-(character+1)) < 1)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(((num+1) >= 2) && ((8-(character+1)) >= 1)){
                                    space = true;
                                }
                                break;
                            case 2://right up right
                                if (((num+1) < 1) && ((8-(character+1)) < 2)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(((num+1) >= 1) && ((8-(character+1)) >= 2)){
                                    space = true;
                                }
                                break;
                            case 3://up up left
                                if (((num+1) < 2) && (character+1) < 1){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(((num+1) >= 2) && (character+1) >= 1){
                                    space = true;
                                }
                                break;
                            case 4://left up left
                                if (((num+1) < 1) && (character+1) < 2){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(((num+1) >= 1) && (character+1) >= 2){
                                    space = true;
                                }
                                break;
                            case 5://down down right
                                if ((8-(num+1) < 2) && (8-(character+1)) < 1){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(num+1) >= 2) && (8-(character+1)) >= 1){
                                    space = true;
                                }
                                break;
                            case 6://right down right
                                if ((8-(num+1) < 1) && (8-(character+1)) < 2){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(num+1) >= 1) && (8-(character+1)) >= 2){
                                    space = true;
                                }
                                break;
                            case 7://down down left
                                if ((8-(num+1) < 2) && (character+1) < 1){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(num+1) >= 2) && (character+1) >= 1){
                                    space = true;
                                }
                                break;
                            case 8://left down left
                                if ((8-(num+1) < 1) && (character+1) < 2){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(num+1) >= 1) && (character+1) >= 2){
                                    space = true;
                                }
                                break;
                            default:
                                break;
                        }
                    }while (!space);
                    move2(direction, "↭", board, num, character);
                }
                return stuff = true;
            case 2:
                if (vamp == 0){
                    do{
                        cout << "Do you want to use Vampire's BABU? \n1)Yes\t2)No\n";
                        cout << ">";
                        cin >> ans2;
                    }while(ans2 != 1 && ans2 != 2 && isdigit(ans2));
                    if (ans2 == 1){
                        if (b_vamp < 1){
                            cout << "Vampire has no more BABU to use.\n";
                            return stuff = false;
                        }else{
                            do{
                                x = rand()%8;
                                y = rand()%8;
                            }while (board[y][x] != "0");
                            board[x][y] = "☫";
                            cout << "Duke summoned!\n";
                            b_vamp--;
                            return stuff = false;
                        }
                    }else if (ans2 == 2){
                        return stuff = false;
                    }
                }else{
                    cout << "Vampire's BABU is not avaliable right now." << endl;
                    return stuff = false;
                }
            case 3:
                return stuff = false;
            default:
                return stuff = false;
        }
    }
    
    bool Pieces_A::ghost(string board[][size], int num, int character){
        int ans, direction, m_blocks, ans2, x, y;
        string ch_direc, ch_mblocks;
        bool space = false, no_chess = true;
        srand(time(NULL));
        do{
            cout << "Do you want to move Ghost or use Ghost's BABU? \n1)move\t2)move & attack\t3)BABU\t4)Exit\n";
            cout << ">";
            cin >> ans;
        }while(ans != 1 && ans!= 2 && isdigit(ans));
        switch (ans) {
            case 1:
                while (!v_move){
                    do{
                        cout << "Which direction?\n";
                        cout << "1)up \t";
                        cout << "2)down \t";
                        cout << "3)right \t";
                        cout << "4)left \n";
                        cout << "5)Exit \n";
                        cout << ">";
                        cin >> ch_direc;
                        cout << endl;
                        try {
                            direction = stoi(ch_direc);
                        }
                        catch (exception err) {
                            cout << "Invalid Input." << endl;
                            direction = 0;
                        }
                        if (direction == 5){
                            return stuff = false;
                        }
                    }while(!((direction <= 5) && (isInteger(ch_direc) && (direction >=1))));//ask direction
                    do{
                        do{//check for intergers
                            cout << "How many steps do you want to BABU? [9 to exit]" << endl;
                            cout << ">";
                            cin >> ch_mblocks;
                            try {
                                m_blocks = stoi(ch_mblocks);
                            }
                            catch (exception err) {
                                cout << "Invalid Input." << endl;
                                m_blocks = 0;
                            }
                            if (m_blocks == 9)
                                return stuff = false;
                        }while(!((m_blocks <= 9) && (isInteger(ch_mblocks) && (m_blocks >=1))));
                        switch (direction) {
                            case 1://up
                                if (board[num-m_blocks][character] != "0"){
                                    cout << "You can't make the BABU! \n";
                                    space = false;
                                    no_chess = false;
                                }else{
                                    for (int i = num; i > num-m_blocks; i--){
                                        if (board[i][character] != "0"){
                                            cout << "You can't make the BABU! \n";
                                            space = false;
                                            no_chess = false;
                                            break;
                                        }
                                    }
                                    if ((num+1) < m_blocks){
                                        cout << "There's no enough BABU! \n";
                                        space = false;
                                    }else if((num+1) >= m_blocks && no_chess == true){
                                        space = true;
                                    }
                                }
                                break;
                            case 2://down
                                if (board[num+m_blocks][character] != "0"){
                                    cout << "You can't make the BABU! \n";
                                    space = false;
                                    no_chess = false;
                                }else{
                                    for (int i = num; i < num+m_blocks; i++){
                                        if (board[i][character] != "0"){
                                            cout << "You can't make the BABU! \n";
                                            space = false;
                                            no_chess = false;
                                        }
                                    }
                                    if ((8-(num+1)) < m_blocks){
                                        cout << "There's no enough BABU! \n";
                                        space = false;
                                    }else if((8-(num+1)) >= m_blocks && no_chess == true){
                                        space = true;
                                    }
                                }
                                break;
                            case 3://right
                                if (board[num][character+m_blocks] != "0"){
                                    cout << "You can't make the BABU! \n";
                                    space = false;
                                    no_chess = false;
                                }else{
                                    for (int i = character; i < character+m_blocks; i--){
                                        if (board[num][i] != "0"){
                                            cout << "You can't make the BABU! \n";
                                            space = false;
                                            no_chess = false;
                                            break;
                                        }
                                    }
                                    if ((8-(character+1)) < m_blocks){
                                        cout << "There's no enough BABU! \n";
                                        space = false;
                                    }else if((8-(character+1)) >= m_blocks && no_chess == true){
                                        space = true;
                                    }
                                }
                                break;
                            case 4://left
                                if (board[num][character-m_blocks] != "0"){
                                    cout << "You can't make the BABU! \n";
                                    space = false;
                                    no_chess = false;
                                }else{
                                    for (int i = character; i > character-m_blocks; i--){
                                        if (board[num][i] != "0"){
                                            cout << "You can't make the BABU! \n";
                                            space = false;
                                            no_chess = false;
                                            break;
                                        }
                                    }
                                    if (character+1 < m_blocks){
                                        cout << "There's no enough BABU! \n";
                                        space = false;
                                    }else if(character+1 >= m_blocks && no_chess == true){
                                        space = true;
                                    }
                                }
                                break;
                            default:
                                break;
                        }
                    }while (!space);
                    move(direction, m_blocks, "𝕲", board, num, character);
                }
                return stuff = true;
            case 2:
                while(!v_move){
                    do{
                        do{
                            cout << "Which direction?\n";
                            cout << "1)up \t";
                            cout << "2)down \t";
                            cout << "3)right \t";
                            cout << "4)left \t";
                            cout << "5)Exit \n";
                            cout << ">";
                            cin >> ch_direc;
                            cout << endl;
                            try {
                                direction = stoi(ch_direc);
                            }
                            catch (exception err) {
                                cout << "Invalid Input." << endl;
                                direction = 0;
                            }
                            if (direction == 5){
                                return stuff = false;
                            }
                        }while(!((direction <= 5) && (isInteger(ch_direc) && (direction >=1))));//ask direction
                        switch (direction) {
                            case 1://up
                                if ((num+1) < 2){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((num+1) >= 2){
                                    space = true;
                                }
                                break;
                            case 2://down
                                if ((8-(num+1)) < 2){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(num+1)) >= 2){
                                    space = true;
                                }
                                break;
                            case 3://right
                                if ((8-(character+1)) < 2){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(character+1)) >= 2){
                                    space = true;
                                }
                                break;
                            case 4://left
                                if (character+1 < 2){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(character+1 >= 2){
                                    space = true;
                                }
                            default:
                                break;
                        }
                    }while (!space);
                    move_jump(direction, "𝕲", board, num, character);
                }
                return stuff = true;
            case 3:
                do{
                    cout << "Do you want to use Ghost's BABU? \n1)Yes\t2)No\n";
                    cout << ">";
                    cin >> ans2;
                }while(ans2 != 1 && ans2 != 2 && isdigit(ans2));
                switch (ans2) {
                    case 1:
                        if(b_ghost < 1){
                            cout << "Ghost has no more BABU to use.\n";
                            return stuff = false;
                        }else{
                            do{
                                x = rand()%8;
                                y = rand()%8;
                            }while (board[y][x] != "0");
                            board[y][x] = board[num][character];
                            board[num][character] = "0";
                            cout << "Ghost has been sent to a random block on the BABU!\n";
                            b_ghost--;
                            return stuff = false;
                        }
                    case 2:
                        return stuff = false;
                    default:
                        return stuff = false;
                }
            case 4:
                return stuff = false;
            default:
                return stuff = false;
        }
    }
    
    bool Pieces_A::magician(string board[][size], int num, int character){
        int ans, direction, m_blocks, ans2, x, y, chess, j;
        bool space = true, no_chess = true;
        string ch_direc, ch_mblocks;
        srand(time(NULL));
        do{
            cout << "Do you want to move Magician or use Magician's BABU? \n1)move\t2)BABU\t3)Exit\n";
            cout << ">";
            cin >> ans;
        }while(ans != 1 && ans!= 2 && isdigit(ans));
        switch (ans) {
            case 1:
                while (!v_move){
                    do{
                        cout << "Which direction?\n";
                        cout << "1)up right \t";//5
                        cout << "2)up left \n";//6
                        cout << "3)down left\t";//7
                        cout << "4)down right \n";//8
                        cout << "5)Exit \n";
                        cout << ">";
                        cin >> ch_direc;
                        cout << endl;
                        try {
                            direction = stoi(ch_direc);
                        }
                        catch (exception err) {
                            cout << "Invalid Input." << endl;
                            direction = 0;
                        }
                        if (direction == 5){
                            return stuff = false;
                        }
                    }while(!((direction <= 5) && (isInteger(ch_direc) && (direction >=1))));
                    //ask and check direction
                    do{
                        do{//check for intergers
                            cout << "How many steps do you want to BABU? [9 to exit]" << endl;
                            cout << ">";
                            cin >> ch_mblocks;
                            try {
                                m_blocks = stoi(ch_mblocks);
                            }
                            catch (exception err) {
                                cout << "Invalid Input." << endl;
                                m_blocks = 0;
                            }
                            if (m_blocks == 9)
                                return stuff = false;
                        }while(!((m_blocks <= 9) && (isInteger(ch_mblocks) && (m_blocks >=1))));
                        switch (direction) {
                            case 1://up right
                                
                                if(((num+1) >= m_blocks) && ((8-(character+1)) >= m_blocks)){
                                    space = true;
                                    
                                }else if (((num+1) < m_blocks) && ((8-(character+1)) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                break;
                            case 2://up left
                                
                                if(((num+1) >= m_blocks) && ((character+1) >= m_blocks)){
                                    space = true;
                                }
                                else if (((num+1) < m_blocks) && ((character+1) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                break;
                            case 3:
                                j = character-1;
                                
                                if(((8-(num+1)) >= m_blocks) && ((character+1) >= m_blocks )){
                                    space = true;
                                }
                                else if (((8-(num+1)) < m_blocks) && ((character+1) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                break;
                            case 4:
                                
                                if(((8-(num+1)) >= m_blocks) && ((8-(character+1)) >= m_blocks) ){
                                    space = true;
                                }
                                else if (((8-(num+1)) < m_blocks) && ((8-(character+1)) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }
                                break;
                            default:
                                break;
                        }//checl m_block validation
                    }while (!space);
                    move((direction+4), m_blocks, "✡", board, num, character);
                }
                return stuff = true;
                break;
            case 2:
                do{
                    cout << "Do you want to use Magician's BABU? \n1)Yes\t2)No\n";
                    cout << ">";
                    cin >> ans2;
                }while(ans2 != 1 && ans2 != 2 && isdigit(ans2));
                switch (ans2) {
                    case 1:
                        if (b_magician < 1){
                            cout << "Magician has no more BABU to use.\n";
                            return stuff = false;
                        }else{
                            do{
                                x = rand()%8;
                                y = rand()%8;
                            }while (board[y][x] != "0");
                            chess = rand()%4+1;
                            switch (chess) {
                                case 1:
                                    board[y][x] = "𝕲";
                                    cout << "Magician summoned a Ghost.\n";
                                    break;
                                case 2:
                                    board[y][x] = "↭";
                                    cout << "Magician summoned a Vampire.\n";
                                    break;
                                case 3:
                                    board[y][x] = "웃";
                                    cout << "Magician summoned a Titan.\n";
                                    break;
                                case 4:
                                    board[y][x] = "⍢";
                                    cout << "Magician summoned a Slime.\n";
                                    break;
                                default:
                                    break;
                            }
                            b_magician--;
                            return stuff = false;
                        }
                    case 2:
                        return stuff = false;
                    default:
                        return stuff = false;
                }
            case 3:
                return stuff = false;
            default:
                return stuff = false;
        }
    }
    
    bool Pieces_A::slime(string board[][size], int num, int character, int round){
        int direction, m_blocks = 1, trap;
        srand (time(NULL));
        bool space = false, no_chess = true;
        string ch_direc;
        while (!v_move){
            while (!space){
                do{
                    cout << "Which direction?\n";
                    cout << "1)up \t";
                    cout << "2)down \t";
                    cout << "3)right \t";
                    cout << "4)left \t";
                    cout << "5)Exit \n";
                    cout << ">";
                    cin >> ch_direc;
                    cout << endl;
                    try {
                        direction = stoi(ch_direc);
                    }
                    catch (exception err) {
                        cout << "Invalid Input." << endl;
                        direction = 0;
                    }
                    if (direction == 5){
                        return stuff = false;
                    }
                }while(!((direction <= 4) && (isInteger(ch_direc) && (direction >=1))));//ask direction
                switch (direction) {
                    case 1://up
                        if ((num+1) < m_blocks){
                            cout << "There's no enough BABU! \n";
                            space = false;
                        }else if((num+1) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 2://down
                        if ((8-(num+1)) < m_blocks){
                            cout << "There's no enough BABU! \n";
                            space = false;
                        }else if((8-(num+1)) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 3://right
                        if ((8-(character+1)) < m_blocks){
                            cout << "There's no enough BABU! \n";
                            space = false;
                        }else if((8-(character+1)) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 4://left
                        if (character+1 < m_blocks){
                            cout << "There's no enough BABU! \n";
                            space = false;
                        }else if(character+1 >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                }//check space
            }
            move(direction, m_blocks, "⍢", board, num, character);
        }
        if (round%3 == 0){
            trap = rand()%6;
            switch (trap) {
                case 0:
                    trap_piece = "♔";
                    break;
                case 1:
                    trap_piece = "♢";
                    break;
                case 2:
                    trap_piece = "♘";
                    break;
                case 3:
                    trap_piece = "☽";
                    break;
                case 4:
                    trap_piece = "✙";
                    break;
                case 5:
                    trap_piece = "ꆜ";
                    break;
                default:
                    break;
            }
        }
        return stuff = true;
    }
    
    bool Pieces_A::titan(string board[][size], int num, int character){
        int ans, direction, m_blocks = 2, x, y;
        string ch_direc;
        bool space = false, no_chess = true;
        srand(time(NULL));
        do{
            cout << "Do you want to move Titan or use Titan's BABU? \n1)move\t2)BABU\t3)Exit\n";
            cout << ">";
            cin >> ans;
        }while(ans != 1 && ans!= 2 && isdigit(ans));
        switch (ans) {
            case 1:
                while (!v_move){
                    while (!space){
                        do{
                            cout << "Which direction?\n";
                            cout << "1)up \t";
                            cout << "2)down \t";
                            cout << "3)right \t";
                            cout << "4)left \t";
                            cout << "5)Exit \n";
                            cout << ">";
                            cin >> ch_direc;
                            cout << endl;
                            try {
                                direction = stoi(ch_direc);
                            }
                            catch (exception err) {
                                cout << "Invalid Input." << endl;
                                direction = 0;
                            }
                            if (direction == 5){
                                return stuff = false;
                            }
                        }while(!((direction <= 4) && (isInteger(ch_direc) && (direction >=1))));//ask direction
                        switch (direction) {
                            case 1://up
                                for (int i = num; i > num-m_blocks; i--){
                                    if (board[i][character] != "0"){
                                        cout << "You can't make the BABU! \n";
                                        space = false;
                                        no_chess = false;
                                        break;
                                    }
                                }
                                if ((num+1) < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((num+1) >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 2://down
                                for (int i = num; i < num+m_blocks; i++){
                                    if (board[i][character] != "0"){
                                        cout << "You can't make the BABU! \n";
                                        space = false;
                                        no_chess = false;
                                        break;
                                    }
                                }
                                if ((8-(num+1)) < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(num+1)) >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 3://right
                                for (int i = character; i < character+m_blocks; i--){
                                    if (board[num][i] != "0"){
                                        cout << "You can't make the BABU! \n";
                                        space = false;
                                        no_chess = false;
                                        break;
                                    }
                                }
                                if ((8-(character+1)) < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if((8-(character+1)) >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 4://left
                                for (int i = character; i > character-m_blocks; i--){
                                    if (board[num][i] != "0"){
                                        cout << "You can't make the BABU! \n";
                                        space = false;
                                        no_chess = false;
                                        break;
                                    }
                                }
                                if (character+1 < m_blocks){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(character+1 >= m_blocks && no_chess == true){
                                    space = true;
                                }
                                break;
                        }//check space
                    }
                    move(direction, m_blocks, "웃", board, num, character);
                }
                return stuff = true;
            case 2:
                if (b_titan < 1){
                    cout << "Titan has no more BABU to use.\n";
                    return stuff = false;
                }else{
                    do{
                        cout << "Do you want to use Titan's BABU? \n1)Yes\t2)No\n";
                        cout << ">";
                        cin >> ans;
                    }while(ans != 1 && ans!= 2 && isdigit(ans));
                    if (ans == 1){
                        do{
                            x = rand()%8;
                            y = rand()%8;
                        }while (board[y][x] != "0");
                        board[y][x] = "❧";
                        cout << "BUBA [❧] is randomly set on the board." << endl;
                        b_titan--;
                        bu_ba++;
                        return stuff = false;
                    }else if (ans == 2){
                        return stuff = false;
                    }
                }
            case 3:
                return stuff = false;
            default:
                return stuff = false;
        }
    }
    
    bool Pieces_A::skeleton(string board[][size], int num, int character){
        int direction, m_blocks = 1;
        bool space = false, no_chess = true;
        string ch_direc;
        while (!v_move){
            while (!space){
                do{
                    cout << "Which direction?\n";
                    cout << "1)up \t";
                    cout << "2)down \t";
                    cout << "3)right \t";
                    cout << "4)left \t";
                    cout << "5)Exit \n";
                    cout << ">";
                    cin >> ch_direc;
                    cout << endl;
                    try {
                        direction = stoi(ch_direc);
                    }
                    catch (exception err) {
                        cout << "Invalid Input." << endl;
                        direction = 0;
                    }
                    if (direction == 5){
                        return stuff = false;
                    }
                }while(!((direction <= 4) && (isInteger(ch_direc) && (direction >=1))));//ask direction
                switch (direction) {
                    case 1://up
                        for (int i = num; i > num-m_blocks; i--){
                            if (board[i][character] != "0"){
                                cout << "You can't make the BABU! \n";
                                space = false;
                                no_chess = false;
                                break;
                            }
                        }
                        if ((num+1) < m_blocks){
                            cout << "There's no enough BABU! \n";
                            space = false;
                        }else if((num+1) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 2://down
                        for (int i = num; i < num+m_blocks; i++){
                            if (board[i][character] != "0"){
                                cout << "You can't make the BABU! \n";
                                space = false;
                                no_chess = false;
                                break;
                            }
                        }
                        if ((8-(num+1)) < m_blocks){
                            cout << "There's no enough BABU! \n";
                            space = false;
                        }else if((8-(num+1)) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 3://right
                        for (int i = character; i < character+m_blocks; i--){
                            if (board[num][i] != "0"){
                                cout << "You can't make the BABU! \n";
                                space = false;
                                no_chess = false;
                                break;
                            }
                        }
                        if ((8-(character+1)) < m_blocks){
                            cout << "There's no enough BABU! \n";
                            space = false;
                        }else if((8-(character+1)) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 4://left
                        for (int i = character; i > character-m_blocks; i--){
                            if (board[num][i] != "0"){
                                cout << "You can't make the BABU! \n";
                                space = false;
                                no_chess = false;
                                break;
                            }
                        }
                        if (character+1 < m_blocks){
                            cout << "There's no enough BABU! \n";
                            space = false;
                        }else if(character+1 >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                }//check space
            }
            move(direction, m_blocks, "☠", board, num, character);
        }
        return stuff = true;
    }
    
    bool Pieces_A::clown(string board[][size], int num, int character){
        int direction, m_blocks, j;
        bool space = false, no_chess = true;
        srand(time(NULL));
        while (!v_move){
            do{
                direction = rand()%8;
                m_blocks = rand()%8;
                switch (direction) {
                    case 1://up
                        for (int i = num; i > num-m_blocks; i--){
                            if (board[i][character] != "0"){
                                space = false;
                                no_chess = false;
                                break;
                            }
                        }
                        if ((num+1) < m_blocks){
                            space = false;
                        }else if((num+1) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 2://down
                        for (int i = num; i < num+m_blocks; i++){
                            if (board[i][character] != "0"){
                                space = false;
                                no_chess = false;
                                break;
                            }
                        }
                        if ((8-(num+1)) < m_blocks){
                            space = false;
                        }else if((8-(num+1)) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 3://right
                        for (int i = character; i < character+m_blocks; i--){
                            if (board[num][i] != "0"){
                                space = false;
                                no_chess = false;
                                break;
                            }
                        }
                        if ((8-(character+1)) < m_blocks){
                            space = false;
                        }else if((8-(character+1)) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 4://left
                        for (int i = character; i > character-m_blocks; i--){
                            if (board[num][i] != "0"){
                                space = false;
                                no_chess = false;
                                break;
                            }
                        }
                        if (character+1 < m_blocks){
                            space = false;
                        }else if(character+1 >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 5://up right
                        j = character+1;
                        for (int i = num-1; i > num-m_blocks; i--){
                            
                            if (board[i][j] != "0"){
                                
                                no_chess = false;
                                m_blocks = 0;
                            }
                            if (no_chess == false)
                                break;
                            j++;
                        }
                        if(((num+1) >= m_blocks) && ((8-(character+1)) >= m_blocks)){
                            space = true;
                        }
                        else if (!no_chess){
                            space = false;
                        }else if (((num+1) < m_blocks) && ((8-(character+1)) < m_blocks)){
                            space = false;
                        }
                        break;
                    case 6://up left
                        j = character-1;
                        for (int i = num-1; i > num-m_blocks; i--){
                            if (board[i][j] != "0"){
                                no_chess = false;
                                m_blocks = 0;
                                break;
                            }
                            j--;
                        }
                        if(((num+1) >= m_blocks) && ((character+1) >= m_blocks)){
                            space = true;
                        }
                        else if (!no_chess){
                            space = false;
                        }
                        else if (((num+1) < m_blocks) && ((character+1) < m_blocks)){
                            space = false;
                        }
                        break;
                    case 7:
                        j = character-1;
                        for (int i = num+1; i < num+m_blocks; i++){
                            if (board[i][j] != "0"){                                        no_chess = false;
                                m_blocks = 0;
                                break;
                            }
                            j--;
                        }
                        if(((8-(num+1)) >= m_blocks) && ((character+1) >= m_blocks )){
                            space = true;
                        }
                        else if (((8-(num+1)) < m_blocks) && ((character+1) < m_blocks)){
                            space = false;
                        }else if (!no_chess){
                            
                            space = false;
                        }
                        break;
                    case 8:
                        j = character+1;
                        for (int i = num+1; i < num+m_blocks; i++){
                            if (board[i][j] != "0"){
                                no_chess = false;
                                m_blocks = 0;
                            }
                            if (no_chess == false)
                                break;
                            j++;
                        }
                        if(((8-(num+1)) >= m_blocks) && ((8-(character+1)) >= m_blocks) ){
                            space = true;
                        }
                        else if (((8-(num+1)) < m_blocks) && ((8-(character+1)) < m_blocks)){
                            space = false;
                        }else if (!no_chess){
                            space = false;
                        }
                        break;
                    default:
                        break;
                }//checl m_block validation
            }while (!space);
            move(direction, m_blocks, "〠", board, num, character);
        }
        return stuff = true;
    }
    
    bool Pieces_A::duke(string board[][size], int num, int character){
        int direction, m_blocks = 1;
        bool space = false, no_chess = true;
        string ch_direc;
        while (!v_move){
            while (!space){
                do{
                    cout << "Which direction?\n";
                    cout << "1)up \t";
                    cout << "2)down \t";
                    cout << "3)right \t";
                    cout << "4)left \t";
                    cout << "5)Exit \n";
                    cout << ">";
                    cin >> ch_direc;
                    cout << endl;
                    try {
                        direction = stoi(ch_direc);
                    }
                    catch (exception err) {
                        cout << "Invalid Input." << endl;
                        direction = 0;
                    }
                    if (direction == 5){
                        return stuff = false;
                    }
                }while(!((direction <= 4) && (isInteger(ch_direc) && (direction >=1))));//ask direction
                switch (direction) {
                    case 1://up
                        
                        if ((num+1) < m_blocks){
                            cout << "There's no enough BABU! \n";
                            space = false;
                        }else if((num+1) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 2://down
                        
                        if ((8-(num+1)) < m_blocks){
                            cout << "There's no enough BABU! \n";
                            space = false;
                        }else if((8-(num+1)) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 3://right
                        
                        if ((8-(character+1)) < m_blocks){
                            cout << "There's no enough BABU! \n";
                            space = false;
                        }else if((8-(character+1)) >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                    case 4://left
                        
                        if (character+1 < m_blocks){
                            cout << "There's no enough BABU! \n";
                            space = false;
                        }else if(character+1 >= m_blocks && no_chess == true){
                            space = true;
                        }
                        break;
                }//check space
            }
            move(direction, m_blocks, "☫", board, num, character);
            switch (direction) {
                case 1:
                    do{
                       move(direction, m_blocks, "☫", board, num-1, character);
                    }while(!v_move);
                    break;
                case 2:
                    do{
                        move(direction, m_blocks, "☫", board, num+1, character);
                    }while(!v_move);
                    break;
                case 3:
                    do{
                        move(direction, m_blocks, "☫", board, num, character+1);
                    }while(!v_move);
                    break;
                case 4:
                    do{
                        move(direction, m_blocks, "☫", board, num, character-1);
                    }while(!v_move);
                    break;

                    
                default:
                    break;
            }
        }
        return stuff = true;
    }
    
    bool Pieces_A::buba(string board[][size], int num, int character){
        int direction, m_blocks = 2, ans, ans2;
        string ch_direc;
        bool space = false, no_chess = true, set_y;
        do{
            cout << "Do you want to move Buba or use Buba's BABU? \n1)move\t2)BABU\t3)Exit\n";
            cout << ">";
            cin >> ans;
        }while(ans != 1 && ans!= 2 && isdigit(ans));
        switch (ans) {
            case 1:
                while (!v_move){
                    do{
                        do{
                            cout << "Which direction?\n";
                            cout << "1)up right \t";//5
                            cout << "2)up left \n";//6
                            cout << "3)down left\t";//7
                            cout << "4)down right \n";//8
                            cout << "5)Exit \n";
                            cout << ">";
                            cin >> ch_direc;
                            cout << endl;
                            try {
                                direction = stoi(ch_direc);
                            }
                            catch (exception err) {
                                cout << "Invalid Input." << endl;
                                direction = 0;
                            }
                            if (direction == 5){
                                return stuff = false;
                            }
                        }while(!((direction <= 5) && (isInteger(ch_direc) && (direction >=1))));
                        //ask and check direction
                        switch (direction) {
                            case 1://up right
                                for (int i = num; i > num-m_blocks; i--){
                                    for(int j = character; j < character+m_blocks; j++){
                                        if (board[i][j] != "0"){
                                            cout << "You can't make the BABU! \n";
                                            space = false;
                                            no_chess = true;
                                            break;
                                        }
                                    }
                                }
                                if (((num+1) < m_blocks) && ((8-(character+1)) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(((num+1) >= m_blocks) && ((8-(character+1)) >= m_blocks) && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 2://up left
                                for (int i = num; i > num-m_blocks; i--){
                                    for(int j = character; j > character-m_blocks; j--){
                                        if (board[i][j] != "0"){
                                            cout << "You can't make the BABU! \n";
                                            space = false;
                                            no_chess = true;
                                            break;
                                        }
                                    }
                                }
                                if (((num+1) < m_blocks) && ((character+1) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(((num+1) >= m_blocks) && ((character+1) >= m_blocks) && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 3:
                                for (int i = num; i < num+m_blocks; i++){
                                    for(int j = character; j > character-m_blocks; j--){
                                        if (board[i][j] != "0"){
                                            cout << "You can't make the BABU! \n";
                                            space = false;
                                            no_chess = true;
                                            break;
                                        }
                                    }
                                }
                                if (((8-(num+1)) < m_blocks) && ((character+1) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(((8-(num+1)) >= m_blocks) && ((character+1) >= m_blocks) && no_chess == true){
                                    space = true;
                                }
                                break;
                            case 4:
                                for (int i = num; i < num+m_blocks; i++){
                                    for(int j = character; j < character+m_blocks; j++){
                                        if (board[i][j] != "0"){
                                            cout << "You can't make the BABU! \n";
                                            space = false;
                                            no_chess = true;
                                            break;
                                        }
                                    }
                                }
                                if (((8-(num+1)) < m_blocks) && ((8-(character+1)) < m_blocks)){
                                    cout << "There's no enough BABU! \n";
                                    space = false;
                                }else if(((8-(num+1)) >= m_blocks) && ((8-(character+1)) >= m_blocks) && no_chess == true){
                                    space = true;
                                }
                                break;
                                
                            default:
                                break;
                        }//checl m_block validation
                    }while (!space);
                    move((direction+4), m_blocks, "❧", board, character, num);
                }
                return stuff = true;
            case 2:
                do{
                    cout << "Do you want to use Buba's BABU? \n1)Yes\t2)No\n";
                    cout << ">";
                    cin >> ans2;
                }while(ans2 != 1 && ans2 != 2 && isdigit(ans2));
                if (ans2 == 1){
                    if(b_buba < 1){
                        cout << "Buba has no more BABU to use.\n";
                        return stuff = false;
                    }else{
                        for (int i = 0; i < 8; i++){
                            for (int j = 0; j < 8; j++){
                                if (board[i][j] == "♛"){
                                    ask(board, "♛");
                                    board[i][j] = "0";
                                    set_y = true;
                                    b_buba--;
                                    break;
                                }
                            }
                            if (set_y == true){
                                break;
                            }
                        }
                        return stuff = false;
                    }
                }else if (ans2 == 2){
                    return stuff = false;
                }
            case 3:
                return stuff = false;
            default:
                return stuff = false;
        }
    }

Pieces_H::Pieces_H()//constructor
{
    this -> stuff = false;
    this -> v_move = false;
    this -> win = false;
}

Pieces_A::Pieces_A()//constructor
{
    this -> stuff = false;
    this -> v_move = false;
    this -> win = false;
}
