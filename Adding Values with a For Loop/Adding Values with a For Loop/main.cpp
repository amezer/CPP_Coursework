//74    For Loops    Adding Values with a For Loop    30  Jocelyn Ho

#include <iostream>
using namespace std;

int main()
{
    int num, sum = 0;
    cout << "Number: ";
    cin >> num;
    for (int i = 1; i <= num; i++){
        cout << i << " ";
        sum += i;
    }
    cout << endl;
    cout << "The total is " << sum << endl;
    return 0;
}
