#include <iostream>
#include <array>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

bool repeat_num(int j, vector<int> num){
    bool repeat;
    for (int k = 0; k < num.size(); k++) {
        if (j == num.at(k))
            return repeat = true;
    }
    return 0;
}


int main()
{

    int ans, b_size;
    const int size = 9;
    int board[size][size];
    
    srand(time(NULL));
    
    for (int i = 0; i< size; i++){
        for (int j = 0; j < size; j++){
            board[i][j] = 0;
        }
    }
    
    vector<int> num;
    num.push_back(100);
    
    for (int n = 1; n <= 2; n++){
        for (int i = 0; i < size; i++){
            int j;
            j = rand()%9;
            while (repeat_num(j, num) && (board[i][j] == 0)){
                repeat_num(j, num);
                j = rand()%9;
            }
            num.push_back(j);
            board[i][j] = n;
        }
        num.clear();
    }
    
    
    for (int i = 0; i< size; i++){
        for (int j = 0; j < size; j++){
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
    
    

}
