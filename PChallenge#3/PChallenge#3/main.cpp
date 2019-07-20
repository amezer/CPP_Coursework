#include <iostream>
#include <cmath>
using namespace std;

//numbers over 7 may run very slow  U(ouo)U
int main()
{
    int dig = 1, pw, sum, n, count, num_sum = 0;
    
    cout << "Enter a number: ";
    cin >> pw;
    for (int num = pow(10, pw-1); num < pow(10, pw); num++){
        sum = 0;
        n = num;
        count = 0;
        while (count != pw)
        {
            dig = n%10;
            n = n/10;
            sum += pow(dig, pw);
            count++;
        }
        if(sum == num){
            cout << num << "\t";
            num_sum += num;
        }
    }
    cout << endl;
    cout << "The sum of the numbers is " << num_sum << "." << endl;
}
