//147    Arrays    Where Is It?    90   Jocelyn Ho

#include <iostream>
#include <array>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
    const int size = 10;
    int array[size];
    
    srand(time(NULL));
    
    
    cout << "Array: ";
    for (int i = 0; i < size; i++){
        array[i] = rand()%50+1;
        cout << array[i] << " ";
    }

    cout << endl;
    
    int ans;
    cout << "Value to find: ";
    cin >> ans;
    
    int count = 0;
    for (int i = 0; i < size; i++){
        if (ans == array[i]){
            cout << ans << " is in slot " << i << "." << endl;
            count++;
        }
    }
    if (count == 0){
        cout << ans << " is not in the array." << endl;
    }
    return 0;
}
