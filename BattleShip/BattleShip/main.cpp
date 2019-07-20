#include <iostream>
#include <array>
#include "Stuff.hpp"
using namespace std;

int main()
{
    char p_board[size][size];
    char e_board[size][size];
    char p_attack[size][size];
    char e_attack[size][size];
    int ans;
    
    cout << "Welcome to the にゃんにゃん Battlefield!" << endl;
    do{
        cout << "What type of にゃん are you?"<< endl;
        cout << "1) ダメ人間" << endl;
        cout << "2) リア充" << endl;
        cout << "> ";
        cin >> ans;
        if ((ans != 1)&&(ans != 2))
            cout << "ふざけないでにゃん OUO" << endl;
    }while ((ans != 1) && (ans != 2));
    
    cout << "\nにゃんの世界えへ行こう！" << endl;
    
    if (ans == 1){
        Board ai;
        ai.genBoard(e_board);
        ai.genBoard(e_attack);
        ai.ai_genBoard(e_board, 5, 'C');
        
        ai.ai_genBoard(e_board, 4, 'B');
        ai.ai_genBoard(e_board, 4, 'B');
        for (int i = 0; i < 3; i++)
            ai.ai_genBoard(e_board, 3, 'F');
        for (int i = 0; i < 4; i++)
            ai.ai_genBoard(e_board, 3, 'S');
        for (int i = 0; i < 5; i++)
            ai.ai_genBoard(e_board, 2, 'D');
        
        Board player;
        player.genBoard(p_board);
        
        cout << "Carrier (x1)(size 5): " << endl;
        player.ask(p_board, 5, 'C');
        
        cout << "Battleship (x2)(size 4): " << endl;
        for (int i = 0; i < 2; i++){
            player.ask(p_board, 4, 'B');
        }
        
        for (int i = 0; i < 3; i++){
            cout << "Cruiser (x3)(size 3): " << endl;
            player.ask(p_board, 3, 'F');
        }
        
        for (int i = 0; i < 4; i++){
            cout << "Submarine (x4)(size 3): " << endl;
            player.ask(p_board, 3, 'S');
        }
        
        for (int i = 0; i < 5; i++){
            cout << "Destroyer (x5)(size 2): " << endl;
            player.ask(p_board, 2, 'D');
        }
        
        player.genBoard(p_attack);
        
        while(true){
            cout << "\nIt's your turn to attack!" << endl;
            player.attackShip(e_board, p_attack, 'p');
            cout << "\n\n\n";
            cout << "AI's turn!" << endl;
            ai.ai_attack(p_board, e_attack);
        }
        
    }else if (ans == 2){
        
        cout << "\nBefore you go into the にゃんにゃん Battlefield,\nplease decide which にゃん you want to be.\nPlayer or Enemy??\n決めたら、行くのじゃ！\n" << endl;
        
        Board player;
        player.genBoard(p_board);
        
        cout << "Carrier (x1)(size 5): " << endl;
        player.ask(p_board, 5, 'C');
        
        cout << "Battleship (x2)(size 4): " << endl;
        for (int i = 0; i < 2; i++){
            player.ask(p_board, 4, 'B');
        }
        
        for (int i = 0; i < 3; i++){
            cout << "Cruiser (x3)(size 3): " << endl;
            player.ask(p_board, 3, 'F');
        }
        
        for (int i = 0; i < 4; i++){
            cout << "Submarine (x4)(size 3): " << endl;
            player.ask(p_board, 3, 'S');
        }
        
        for (int i = 0; i < 5; i++){
            cout << "Destroyer (x5)(size 2): " << endl;
            player.ask(p_board, 2, 'D');
        }
        
        player.genBoard(p_attack);
        for (int i = 0; i <= 150; i++)
            cout << "\n\n\n\n\n\n\n\n\n\n";
        
        
        cout << "It's the enemy's turn!" << endl;
        Board enemy;
        enemy.genBoard(e_board);
        
        cout << "Carrier (x1)(size 5): " << endl;
        enemy.ask(e_board, 5, 'C');
        
        cout << "Battleship (x2)(size 4): " << endl;
        for (int i = 0; i < 2; i++){
            enemy.ask(e_board, 4, 'B');
        }
        
        for (int i = 0; i < 3; i++){
            cout << "Cruiser (x3)(size 3): " << endl;
            enemy.ask(e_board, 3, 'F');
        }
        
        for (int i = 0; i < 4; i++){
            cout << "Submarine (x4)(size 3): " << endl;
            enemy.ask(e_board, 3, 'S');
        }
        
        for (int i = 0; i < 5; i++){
            cout << "Destroyer (x5)(size 2): " << endl;
            enemy.ask(e_board, 2, 'D');
        }
        
        enemy.genBoard(e_attack);
        for (int i = 0; i <= 150; i++)
            cout << "\n\n\n\n\n\n\n\n\n\n";
        
        while(true){
            cout << "It's the player's turn!" << endl;
            player.attackShip(e_board, p_attack, 'p');
            cout << "\n\n\n";
            cout << "It's the enemy's turn!" << endl;
            enemy.attackShip(p_board, e_attack, 'e');
        }
    }
    
    /**/
    
    
}
