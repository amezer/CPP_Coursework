//67    For Loops    Counting Machine Revisited    25  Jocelyn Ho

#include <iostream>
using namespace std;

int main()
{
    int countf, countt, countb;
    cout << "Count from: ";
    cin >> countf;
    cout << "Count to: ";
    cin >> countt;
    cout << "Count by: ";
    cin >> countb;
    
    for (int i = countf; i <= countt; i += countb){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
