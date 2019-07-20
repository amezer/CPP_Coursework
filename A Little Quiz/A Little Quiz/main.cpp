// 27    If Statements    A Little Quiz    40  Jocelyn Ho
#include <iostream>
using namespace std;

int main()
{
    int a1, a2, a3;
    
    double s = 0;
    
    cout << "Are you ready for a pop quiz?";
    string ans;
    cin >> ans;
    cout << "No matter what, let's start the quiz! \n";
    
    cout << "Q1) Which is better? \n";
    cout << "1) Milk Chocolate \n";
    cout << "2) Dark Chocolate \n";
    cout << "3) White Chocolate \n";
    cin >> a1;
    if (a1 == 1){
        cout << "Correct! \n";
        s++;
    }
    else{
        cout << "Incorrect! \n";
    }
    
    cout << "Q2) Which is better? \n";
    cout << "1) Drama \n";
    cout << "2) Movie \n";
    cout << "3) Animation \n";
    cin >> a2;
    if (a2 == 3){
        cout << "Correct! \n";
        s++;
    }
    else{
        cout << "Incorrect! \n";
    }
    
    cout << "Q3) Which is better? \n";
    cout << "1) Cherry \n";
    cout << "2) Apple \n";
    cout << "3) Grape \n";
    cin >> a3;
    if (a3 == 1){
        cout << "Correct! \n";
        s++;
    }
    else{
        cout << "Incorrect! \n";
    }
    
    cout << "Congratulation! You scored " << s << " out of 3! Which is " << ((s/3)*100) << "%.";
}
