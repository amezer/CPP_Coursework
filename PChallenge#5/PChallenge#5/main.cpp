#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>

using namespace std;

#define SIDES 12
#define SUM 70
#define NUM_TOPS 10
#define NUM_DICES 20

int counts = 0;

void inner(int depth, vector<int> &numbers){
    if (depth > 0){
        for(int i = 0; i < SIDES; i++){
            numbers[depth-1] = i+1;
            inner(depth-1, numbers) ;
        }
    }else{
        int thesum = 0;
        vector<int> tops;
        // calculate sum of x,y,z:
        //cout << "dices: ";
        for(int i = 0; i < numbers.size(); i++){
            //cout << numbers[i] << " ";
            tops.push_back(numbers[i]);
        }
        
        // sort it
        sort(tops.begin(),tops.end(), greater<int>());
       // cout << "--> sorted: ";
        for(int i = 0; i < NUM_DICES; i++){
            //cout << tops[i] << " ";
        }
        
        // find the sum of the top most
        for(int i = 0; i < NUM_TOPS; i++){
            thesum += tops[i];
        }
        if (thesum == SUM){
            //cout << "hit! ";
            counts++;
        }
        //cout<<endl;
    }
}

int main(){
    vector<int>  numbers;
    numbers.resize(NUM_DICES);

    inner((int)numbers.size(),numbers);
    cout << "total = " << counts << " \n";
}

