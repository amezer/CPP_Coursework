//
//  Stuff.cpp
//  BattleShip
//
//  Created by レン on 2019/7/15.
//  Copyright © 2019 レン. All rights reserved.
//

#include "Stuff.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
using namespace std;





    bool Board::isInteger(string str)
    {
        int num;
        istringstream iss (str);
        
        iss >> num;
        
        return !iss.fail();
    }
    
    void Board::victoryCheck(int sunk, char side){
        if (sunk == 15 && side == 'p'){
            cout << "\nPlayer wins the game!" << endl;
            exit(0);
        }
        else if (sunk == 15 && side == 'e'){
            cout << "\nEnemy wins the game!" << endl;
            exit(0);
        }
        else if (sunk == 15 && side == 'a'){
            cout << "\nAI wins the game!" << endl;
            exit(0);
        }
    }

    void Board::ai_genBoard(char arr[][size], int b_length, char symbol){
        srand(time(NULL));
        int direction, character, num, count = 0;
        bool valid = false;
        while (!valid){
            direction = rand()%2+1;
            character = rand()%10;
            num = rand()%10;
            if(direction == 1){
                if ((9-character) < (b_length-1)){
                    valid = false;
                }
                else {
                    for (int i = 0; i < b_length; i++){
                        if(arr[num][character+i] == '0'){
                            count++;
                        }
                        else{
                            valid = false;
                        }
                    }
                    if(count == b_length)
                        valid = true;
                    else{
                        valid = false;
                    }
                }
                count = 0;
            }
            if(direction == 2){
                if (9-num < b_length-1){
                    valid = false;
                }
                else{
                    for (int i = 0; i < b_length; i++){
                        if(arr[num+i][character] == '0'){
                            count++;
                        }
                        else{
                            valid = false;
                        }
                    }
                    if (count == b_length)
                        valid = true;
                    else{
                        valid = false;
                    }
                }
            }
            count = 0;
        }
        if (direction == 1){
            for (int i = character; i < (character+b_length); i++){
                arr[num][i] = symbol;
            }
        }
        if (direction == 2){
            for (int i = num; i < (num+b_length); i++){
                arr[i][character] = symbol;
            }
        }
    }
    
    void Board::genBoard(char arr[][size]){
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                arr[i][j] = '0';
            }
        }
    }
    
    void Board::showBoard(char arr[][size]){
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
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }
    
    void Board::set(int num, char ch, char direction, char arr[][size], char symbol, int b_length){
        int character = 0;
        character = (int(ch) - 64)-1;
        num = num-1;
        
        if (direction == 'h' || direction == 'H'){
            for (int i = character; i < (character+b_length); i++){
                arr[num][i] = symbol;
            }
        }
        if (direction == 'v' || direction == 'V'){
            for (int i = num; i < (num+b_length); i++){
                arr[i][character] = symbol;
            }
        }
    }
    
    void Board::ask(char arr[][size], int b_length, char symbol){
        int num, character, num2, count;
        bool valid = false;
        char ch, direction;
        string ch_num, ch_ch;
        while (!valid){
            count = 0;
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
            }while(!((num <= 10) && (isInteger(ch_num) && (num >=1))));
            getchar();
            do{
                system("stty raw");
                cout << "Enter the location(char): ";
                ch = getchar();
                cout << endl;
                ch = toupper(ch);
            }while(!((ch >= 'A') && (ch <= 'J')&& (!isInteger(ch_ch))));
            do{
                cout << endl;
                cout << "Horizontal(h) or Vertical(v): ";
                cin >> direction;
                cout << endl;
                direction = toupper(direction);
            }while((direction != 'H')&&(direction != 'V'));
            character = 0;
            character = (int(ch) - 64)-1;//character is the index
            num2 = num-1;//num2 is the index
            if(direction == 'H'){
                if ((9-character) < (b_length-1)){
                    cout << "Invalid input." << endl;
                    valid = false;
                }
                else {
                    for (int i = 0; i < b_length; i++){
                        if(arr[num2][character+i] == '0'){
                            count++;
                        }
                        else{
                            cout << "Invalid input." << endl;
                            valid = false;
                        }
                    }
                    if(count == b_length)
                        valid = true;
                    else{
                        cout << "Invalid input." << endl;
                        valid = false;
                    }
                }
            }
            if(direction == 'V'){
                if (9-num < b_length-1){
                    cout << "Invalid input.";
                    valid = false;
                }
                else{
                    for (int i = 0; i < b_length; i++){
                        if(arr[num2+i][character] == '0'){
                            count++;
                        }
                        else{
                            cout << "Invalid input";
                            valid = false;
                        }
                    }
                    if (count == b_length)
                        valid = true;
                    else{
                        cout << "Invalid input." << endl;
                        valid = false;
                    }
                }
            }
            cout << endl;
        }
        set(num, ch, direction, arr, symbol, b_length);
        showBoard(arr);
    }
    
    void Board::ai_attack(char arr[][size], char result_b[][size]){
        srand(time(NULL));
        int num, character, b_length = 0, num1, ch1, ran, gg;
        char side = 'a';
        do{
            num = rand()%9;
            character = rand()%9;
            if (arr[num+1][character] != '0')
                num = num+1;
            else if (arr[num-1][character] != '0')
                num = num-1;
            else if (arr[num][character+1] != '0')
                character = character+1;
            else if (arr[num][character-1] != '0')
                character = character-1;
            num1 = num;
            ch1 = character;
            gg = rand()%2;
            if ((result_b[num1][ch1] == 'H')&&(gg==0)){
                ran = rand()%4+1;
                switch (ran){
                    case 1:
                        num = num1+1;
                        character = ch1;
                        break;
                    case 2:
                        num = num1-1;
                        character = ch1;
                        break;
                    case 3:
                        num = num1;
                        character = ch1+1;
                        break;
                    case 4:
                        num = num1;
                        character = ch1-1;
                        break;
                }
            }
        }while(result_b[num][character] != '0');
        if (arr[num][character] == '0'){
            cout << "It's a miss!" << endl;
            result_b[num][character] = 'M';
        }else if ((result_b[num][character] != 'M')&&(result_b[num][character] != 'H')&&(arr[num][character] != '0')){
            cout << "Opps! It's a hit!" << endl;
            result_b[num][character] = 'H';
            
            switch (arr[num][character]){
                case 'C':
                    b_length = 5;
                    break;
                case 'B':
                    b_length = 4;
                    break;
                case 'F':
                    b_length = 3;
                    break;
                case 'S':
                    b_length = 3;
                    break;
                case 'D':
                    b_length = 2;
                    break;
            }
            checkShip(num, character, arr, b_length, result_b, side);
        }
        showBoard(result_b);
    }
    
    
    void Board::attackShip(char arr[][size], char result_b[][size], char side){
        int num, character, num2, count, b_length = 0;
        bool valid = false;
        char ch;
        string ch_num, ch_ch;
        while (!valid){
            count = 0;
            do{
                cout << "Enter the location(num) to attack: ";
                cin >> ch_num;
                cout << endl;
                try {
                    num = stoi(ch_num);
                }
                catch (exception err) {
                    cout << "Invalid Input." << endl;
                    num = 0;
                }
            }while(!((num <= 10) && (isInteger(ch_num) && (num >=1))));
            getchar();
            do{
                system("stty raw");
                cout << "Enter the location(char) to attack: ";
                ch = getchar();
                cout << endl;
                ch = toupper(ch);
            }while(!((ch >= 'A') && (ch <= 'J')&& (!isInteger(ch_ch))));
            character = 0;
            character = (int(ch) - 64)-1;
            num2 = num-1;//index
            if (result_b[num2][character] != '0'){
                cout << "This location had already been attacked."<< endl;
                valid = false;
            }else
                valid = true;
        }
        if (arr[num2][character] == '0'){
            cout << "Miss" << endl;
            result_b[num2][character] = 'M';
        }else if ((result_b[num2][character] != 'M')&&(result_b[num2][character] != 'H')&&(arr[num2][character] != '0')){
            cout << "Hit" << endl;
            result_b[num2][character] = 'H';
            if (arr[num2][character] == 'D'){
                if (side == 'p')
                    Destroyer_p--;
                else if (side == 'e')
                    Destroyer_e--;
            }if (side == 'p'){
                if (Destroyer_p% 2 == 0 && Destroyer_p != 10){
                    cout << "\n" << side_check(side) << " destroyed a Destroyer!" << endl;
                    
                    p_sunk++;
                    cout << 15-p_sunk << " more ships left! OUO" << endl;
                    victoryCheck(p_sunk, side);
                    
                }
            }else if (side == 'e'){
                if (Destroyer_e% 2 == 0 && Destroyer_e != 10){
                    cout << "\n" << side_check(side) << " destroyed a Destroyer!" << endl;
                    
                    e_sunk++;
                    cout << 15-e_sunk << " more ships left! OUO" << endl;
                    victoryCheck(e_sunk, side);
                    
                }
            }
            
            switch (arr[num2][character]){
                case 'C':
                    b_length = 5;
                    break;
                case 'B':
                    b_length = 4;
                    break;
                case 'F':
                    b_length = 3;
                    break;
                case 'S':
                    b_length = 3;
                    break;
                case 'D':
                    b_length = 2;
                    break;
            }
            checkShip(num2, character, arr, b_length, result_b, side);
        }
        if (side == 'p')
            cout << "Player's board:" << endl;
        else if (side == 'e')
            cout << "Enemy's board:"<< endl;
        showBoard(result_b);
    }
    
    string Board::side_check(char side){
        string attacker;
        if (side == 'p')
            return attacker = "Player";
        else if (side == 'e')
            return attacker = "Enemy";
        else if (side == 'a')
            return attacker = "AI";
        else
            return 0;
    }
    
    void Board::shipType(char ch, char side){
        switch (ch){
            case 'C':
                cout << "\n" << side_check(side) << " destroyed a Carrier!" << endl;
                if (side == 'p'){
                    p_sunk++;
                    cout << 15-p_sunk << " more ships left! OUO" << endl;
                    victoryCheck(p_sunk, side);
                }else if (side == 'e'){
                    e_sunk++;
                    cout << 15-e_sunk << " more ships left! OUO" << endl;
                    victoryCheck(e_sunk, side);
                }else if (side == 'a'){
                    a_sunk++;
                    cout << 15-a_sunk << " more ships left! OUO" << endl;
                    victoryCheck(a_sunk, side);
                }
                break;
            case 'B':
                cout << "\n" << side_check(side) << " destroyed a Battleship!" << endl;
                if (side == 'p'){
                    p_sunk++;
                    cout << 15-p_sunk << " more ships left! OUO" << endl;
                    victoryCheck(p_sunk, side);
                }else if (side == 'e'){
                    e_sunk++;
                    cout << 15-e_sunk << " more ships left! OUO" << endl;
                    victoryCheck(e_sunk, side);
                }else if (side == 'a'){
                    a_sunk++;
                    cout << 15-a_sunk << " more ships left! OUO" << endl;
                    victoryCheck(a_sunk, side);
                }
                break;
            case 'F':
                cout << "\n" << side_check(side) << " destroyed a Cruiser!" << endl;
                if (side == 'p'){
                    p_sunk++;
                    cout << 15-p_sunk << " more ships left! OUO" << endl;
                    victoryCheck(p_sunk, side);
                }else if (side == 'e'){
                    e_sunk++;
                    cout << 15-e_sunk << " more ships left! OUO" << endl;
                    victoryCheck(e_sunk, side);
                }else if (side == 'a'){
                    a_sunk++;
                    cout << 15-a_sunk << " more ships left! OUO" << endl;
                    victoryCheck(a_sunk, side);
                }
                break;
            case 'S':
                cout << "\n" << side_check(side) << " destroyed a Submarine!" << endl;
                if (side == 'p'){
                    p_sunk++;
                    cout << 15-p_sunk << " more ships left! OUO" << endl;
                    victoryCheck(p_sunk, side);
                }else if (side == 'e'){
                    e_sunk++;
                    cout << 15-e_sunk << " more ships left! OUO" << endl;
                    victoryCheck(e_sunk, side);
                }else if (side == 'a'){
                    a_sunk++;
                    cout << 15-a_sunk << " more ships left! OUO" << endl;
                    victoryCheck(a_sunk, side);
                }
                break;
        }
        
    }
    
    void Board::checkShip(int num, int character, char play_b[][size], int b_length, char result_b[][size], char side){
        int count = 0;
        char ch = play_b[num][character];
        //num & character are indexs
        if (result_b[num+1][character] != '0'){
            for (int i = 0; i < b_length; i++){
                if((result_b[(num+1)+i][character] == 'H')&&(play_b[num+1+i][character] == ch))
                    count ++;
                else
                    break;
            }
            if (count == (b_length-1))
                shipType(ch, side);
            count = 0;
        }else if (result_b[num-1][character] != '0'){
            for (int i = 0; i < b_length; i++){
                if((result_b[(num-1)-i][character] == 'H')&&(play_b[num-1-i][character] == ch))
                    count ++;
                else
                    break;
            }
            if (count == (b_length-1))
                shipType(ch, side);
            count = 0;
        }else if (result_b[num][character+1] != '0'){
            for (int i = 0; i < b_length; i++){
                if((result_b[num][character+1+i] == 'H')&&(play_b[num][character+1+i] == ch))
                    count ++;
                else
                    break;
            }
            if (count == (b_length-1))
                shipType(ch, side);
            count = 0;
        }else if (result_b[num][character-1] != '0'){
            for (int i = 0; i < b_length; i++){
                if((result_b[num][character-1-i] == 'H')&&(play_b[num][character-1-i] == ch))
                    count ++;
                else
                    break;
            }
            if (count == (b_length-1))
                shipType(ch, side);
            count = 0;
        }
    }


Board::Board()
{
    this -> Destroyer_p = 10;
    this -> Destroyer_e = 10;
    this -> score = 0;
    this -> p_sunk = 0;
    this -> e_sunk = 0;
    this -> a_sunk = 0;
}
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
