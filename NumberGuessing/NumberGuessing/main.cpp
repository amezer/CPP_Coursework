//43    Random Numbers    A Number-Guessing Game    20   Jocelyn Ho

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int guess, ans;
    srand(time(NULL));
    ans = rand()%10+1;
    cout << "I'm thinking of a number from 1 to 10." << endl;
    cout << "Your guess: ";
    cin >> guess;
    if (guess == ans){
        cout << "Yay!" << endl;
    }else if (guess > 10 || guess < 1){
        cout << "Invalid guess." << endl;
    }else if (guess != ans){
        cout << "Wrong." << endl;
    }
    cout << "The answer is " << ans << endl;
    return 0;
}
