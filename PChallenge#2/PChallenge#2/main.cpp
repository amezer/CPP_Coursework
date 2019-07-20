#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

int main(){
    
    int start, end, dlen;
    
    cout << "Please enter the starting point: ";
    cin >> start;
    
    do{
        cout << "Please enter the ending point: ";
        cin >> end;
        if (end < start)
        cout << "Invalid input." << endl;
    }while (end < start);
    
    long result = 0;
    long modulo = 10000000000;
    
    for (int i = start; i <= end; i++) {
        long temp = i;
        for (int j = 1; j < i; j++) {
            temp *= i;
            if (temp >= (LONG_MAX/end)) {
            temp %= modulo;
            }
        }
        result += temp;
        result %= modulo;
    }
    if ((dlen = ceil(log10(result+1))) < 10) {
        for (int j = 0; j < (10-dlen); j++)
        cout << "0";
    }
    cout << "The last 10 digit is " << result << "." << endl;
}
