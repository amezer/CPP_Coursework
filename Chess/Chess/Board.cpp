#include <iostream>
#include <sstream>
#include <string>
#include <ctype.h>
#include "Board.hpp"
#include "Pieces.hpp"
using namespace std;

    bool Board::isInteger(string str)//check if its interger
    {
        int num;
        istringstream iss (str);
        
        iss >> num;
        
        return !iss.fail();
    }
    void Board::genBoard(string board[][size]){//initialize the big board
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                board[i][j] = '0';
            }
        }
    }
    
    void Board::genBoard2(string board[4][8]){//initialize the small board
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 8; j++){
                board[i][j] = "0";
            }
        }
    }
    
    void Board::showBoard(string board[][size]){//prints the big board [8*8]
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
    
    void Board::showBoard2(string board[4][8]){//shows the small board
        int character = 0;
        char ch = 'A';
        cout << "\t" << "\t";
        for (int k = 0; k < 8; k++){
            character = int(ch);
            cout << ch << "\t";
            character++;
            ch = char(character);
        }
        cout << endl;
        cout << "\t" << "\t";
        for (int k = 0; k < 8; k++){
            cout << "-" << "\t";
        }
        cout << endl;
        for (int i = 0; i < 4; i++){
            cout << i+1 << "\t" << "|" << "\t";
            for (int j = 0; j < 8; j++){
                cout << board[i][j] << "\t";
            }
            cout << "\n\n";
        }
    }
    
    void Board::setPieces(string board[4][8], char side){//asks players to set their pieces and check for the remaining pieces
        string ch_num, ch_ch, symbol, stuff;
        int num, character, num2;
        int count = 0;
        bool empty, more=false;
        char ch;
        int c_1 = 0, c_2 = 0, c_3 = 0, c_4 = 0, c_5 = 0, c_6 = 0, c_7 = 0;
        cout << "Choose a piece to place on BABU!"<<endl;
        do{
            if(side == 'H'){
                do{
                    do{
                        cout << "1)King x1 [♕] \t 2)Queen x1 [♔] \t 3)Guardian x2 [♢] \n4)Knight x4 [♘] 5)Assassin x2 [☽] 6)Priest x1 [✙] \n7)Villager x5 [ꆜ] \n";
                        cout << ">";
                        cin >> ch_num;
                        cout << endl;
                        try {
                            num = stoi(ch_num);
                        }
                        catch (exception err) {
                            cout << "Invalid Input." << endl;
                            num = 0;
                        }
                    }while(!((num <= 7) && (isInteger(ch_num) && (num >=1))));
                    switch(num){
                        case 1:
                            symbol = "♕";
                            c_1++;
                            if (c_1 >= 2){
                                cout << "There's no more " << symbol << " desu!";
                                more = false;
                            }else{
                                more = true;
                            }
                            break;
                        case 2:
                            symbol = "♔";
                            c_2++;
                            if (c_2 >= 2){
                                cout << "There's no more " << symbol << " desu!";
                                more = false;
                            }else{
                                more = true;
                            }
                            break;
                        case 3:
                            symbol = "♢";
                            c_3++;
                            if (c_3 >= 3){
                                cout << "There's no more " << symbol << " desu!";
                                more = false;
                            }else{
                                more = true;
                            }
                            break;
                        case 4:
                            symbol = "♘";
                            c_4++;
                            if (c_4 >= 5){
                                cout << "There's no more " << symbol << " desu!";
                                more = false;
                            }else{
                                more = true;
                            }
                            break;
                        case 5:
                            symbol = "☽";
                            c_5++;
                            if (c_5 >= 3){
                                cout << "There's no more " << symbol << " desu!";
                                more = false;
                            }else{
                                more = true;
                            }
                            break;
                        case 6:
                            symbol = "✙";
                            c_6++;
                            if (c_6 >= 2){
                                cout << "There's no more " << symbol << " desu!";
                                more = false;
                            }else{
                                more = true;
                            }
                            break;
                        case 7:
                            symbol = "ꆜ";
                            c_7++;
                            if (c_7 >= 6){
                                cout << "There's no more " << symbol << " desu!";
                                more = false;
                            }else{
                                more = true;
                            }
                            break;
                    }
                    cout << endl;
                }while (!more);
            }else if(side == 'A'){
                do{
                    do{
                        cout << "1)Lord x1 [♛] \t 2)Gabriel x1 [♚] \t 3)Titan x2 [웃] \n4)Vampire x4 [↭] 5)Ghost x2 [𝕲] 6)Magician x1 [✡] \n7)Slime x5 [⍢] \n";
                        cout << ">";
                        cin >> ch_num;
                        cout << endl;
                        try {
                            num = stoi(ch_num);
                        }
                        catch (exception err) {
                            cout << "Invalid Input." << endl;
                            num = 0;
                        }
                    }while(!((num <= 7) && (isInteger(ch_num) && (num >=1))));
                    switch(num){
                        case 1:
                            symbol = "♛";
                            c_1++;
                            if (c_1 >= 2){
                                cout << "There's no more " << symbol << " desu!";
                                more = false;
                            }else{
                                more = true;
                            }
                            break;
                        case 2:
                            symbol = "♚";
                            c_2++;
                            if (c_2 >= 2){
                                cout << "There's no more " << symbol << " desu!";
                                more = false;
                            }else{
                                more = true;
                            }
                            break;
                        case 3:
                            symbol = "웃";
                            c_3++;
                            if (c_3 >= 3){
                                cout << "There's no more " << symbol << " desu!";
                                more = false;
                            }else{
                                more = true;
                            }
                            break;
                        case 4:
                            symbol = "↭";
                            c_4++;
                            if (c_4 >= 5){
                                cout << "There's no more " << symbol << " desu!";
                                more = false;
                            }else{
                                more = true;
                            }
                            break;
                        case 5:
                            symbol = "𝕲";
                            c_5++;
                            if (c_5 >= 3){
                                cout << "There's no more " << symbol << " desu!";
                                more = false;
                            }else{
                                more = true;
                            }
                            break;
                        case 6:
                            symbol = "✡";
                            c_6++;
                            if (c_6 >= 2){
                                cout << "There's no more " << symbol << " desu!";
                                more = false;
                            }else{
                                more = true;
                            }
                            break;
                        case 7:
                            symbol = "⍢";
                            c_7++;
                            if (c_7 >= 6){
                                cout << "There's no more " << symbol << " desu!";
                                more = false;
                            }else{
                                more = true;
                            }
                            break;
                    }
                    cout << endl;
                }while (!more);
            }

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
                }while(!((num <= 4) && (isInteger(ch_num) && (num >=1))));
                getchar();
                do{
                    system("stty raw");
                    cout << "Enter the location(char): ";
                    ch = getchar();
                    cout << endl;
                    ch = toupper(ch);
                }while(!((ch >= 'A') && (ch <= 'H')&& (!isInteger(ch_ch))));
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
            count++;
            board[num2][character] = symbol;
            showBoard2(board);
        }while (count != 16);
    }
    
    void Board::combine_board(string t_board[][size], string boardA[4][8], string boardH[4][8])//combines the two small boards together after setting their pieces
    {
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 8; j++){
                t_board[i][j] = boardA[i][j];
            }
        }
        
        for (int i = 4; i < 8; i++){
            for (int j = 0; j < 8; j++){
                t_board[i][j] = boardH[i-4][j];
            }
        }
    }
    
void Board::ask_move(string board[][size], char side, int round)//asks for players to choose their piece and make their move
{
        int num, num2, character;
        char ch;
        bool n_chess = false;
        string ch_num, ch_ch, symbol;
        if (side == 'H'){
            while (!Human.stuff){
                
                do{
                    cout << "Choose one piece to make your BABU:" << endl;
                    do{
                        cout << "Enter the location of the piece (num): ";
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
                        cout << "Enter the location of the piece (char): ";
                        ch = getchar();
                        cout << endl;
                        ch = toupper(ch);
                    }while(!((ch >= 'A') && (ch <= 'H')&& (!isInteger(ch_ch))));
                    character = 0;
                    character = (int(ch) - 64)-1;
                    num2 = num-1;
                    symbol = board[num2][character];
                    if(symbol != "♕" && symbol != "♔" && symbol != "♢" && symbol != "♘" && symbol != "☽" && symbol != "✙" && symbol != "ꆜ" && symbol != "Ѷ" && symbol != "卍" && symbol != "❦" && symbol == Asmodians.trap_piece){
                        n_chess = false;
                    }else{
                        n_chess = true;
                    }
                }while (!n_chess);
                if (symbol == "♕"){
                    Human.king(board);
                    showBoard(board);
                }else if (symbol == "♔"){
                    Human.queen(board, num2, character);
                    showBoard(board);
                }else if(symbol == "♢"){
                    Human.guardian(board, num2, character);
                    showBoard(board);
                }else if(symbol == "♘"){
                    Human.knight(board, num2, character);
                    showBoard(board);
                }else if(symbol == "☽"){
                    Human.assassin(board, num2, character);
                    showBoard(board);
                }else if(symbol == "✙"){
                    Human.priest(board, num2, character);
                    showBoard(board);
                }else if(symbol == "ꆜ"){
                    Human.villager(board, num2, character);
                    showBoard(board);
                }else if(symbol == "卍"){
                    Human.champion(board, num2, character);
                    showBoard(board);
                }else if(symbol == "❦"){
                    Human.babu(board, num2, character);
                    showBoard(board);
                }
            }
            Human.stuff = false;
            Human.v_move = false;
            this->win = Human.win;
            if (win)
                this->wside = 'H';
        } else if (side == 'A'){
            while (!Asmodians.stuff) {
                
                do{
                    cout << "Choose one piece to make your BABU:" << endl;
                    do {
                        cout << "Enter the location of the piece (num): ";
                        cin >> ch_num;
                        cout << endl;
                        try {
                            num = stoi(ch_num);
                        }
                        catch (exception err) {
                            cout << "Invalid Input." << endl;
                            num = 0;
                        }
                    } while(!((num <= 8) && (isInteger(ch_num) && (num >=1))));
                    getchar();
                    do {
                        system("stty raw");
                        cout << "Enter the location of the piece (char): ";
                        ch = getchar();
                        cout << endl;
                        ch = toupper(ch);
                    } while(!((ch >= 'A') && (ch <= 'H')&& (!isInteger(ch_ch))));
                    character = 0;
                    character = (int(ch) - 64)-1;
                    num2 = num-1;
                    symbol = board[num2][character];
                    if(symbol != "♛" && symbol != "♚" && symbol != "웃" && symbol != "↭" && symbol != "𝕲" && symbol != "✡" && symbol != "⍢" && symbol != "☠" && symbol != "〠" && symbol != "☫" && symbol != "❧"){
                        n_chess = false;
                    } else {
                        n_chess = true;
                    }
                } while (!n_chess);
                if (symbol == "♛"){
                    Asmodians.lord(board, num2, character);
                    showBoard(board);
                }else if (symbol == "♚"){
                    Asmodians.gabriel(board, num2, character, round);
                    showBoard(board);
                }else if (symbol == "웃"){
                    Asmodians.titan(board, num2, character);
                    showBoard(board);
                }else if (symbol == "↭"){
                    Asmodians.vampire(board, num2, character);
                    showBoard(board);
                }else if (symbol == "𝕲"){
                    Asmodians.ghost(board, num2, character);
                    showBoard(board);
                }else if (symbol == "✡"){
                    Asmodians.magician(board, num2, character);
                    showBoard(board);
                }else if (symbol == "⍢"){
                    Asmodians.slime(board, num2, character, round);
                    showBoard(board);
                }else if (symbol == "〠"){
                    Asmodians.clown(board, num2, character);
                    showBoard(board);
                }else if (symbol == "☫"){
                    Asmodians.duke(board, num2, character);
                    showBoard(board);
                }else if (symbol == "❧"){
                    Asmodians.buba(board, num2, character);
                    showBoard(board);
                }else if (symbol == "☠"){
                    Asmodians.skeleton(board, num2, character);
                    showBoard(board);
                }
            }
            Asmodians.stuff = false;
            Asmodians.v_move = false;
            this->win = Asmodians.win;
            if (win)//check for winning condition
                this->wside = 'A';
        }
        else {//exceptions
            cout << "wrong input.\n";
        }
}

Board::Board()//constructor
{
    this->win = false;
    this->wside = 'H';
}
