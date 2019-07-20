//121    Nested Loops    Basic Nested Loops    50  Jocelyn Ho

#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i <= 5; i++){
        for (int j = 0; j <= 5; j++){
            cout << "(" << i << "," << j << ") ";
        }
        cout << endl;
    }
}
