//55    While Loops    Adding Values in a Loop    30   Jocelyn Ho

#include <iostream>
using namespace std;

int main()
{
    int num, sum = 0;
    cout << "I will sum up all the values you give me." << endl;
    cout << "Number: ";
    cin >> num;
    while(num != 0){
        sum += num;
        cout << "The total so far is " << sum << endl;
        cout << "Number: ";
        cin >> num;
    }
    cout << "The total is " << sum << endl;
}
