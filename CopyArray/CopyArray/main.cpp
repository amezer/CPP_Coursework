//142    Arrays    Copying Arrays    55  Jocelyn Ho

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <array>
using namespace std;

int main()
{
    srand(time(NULL));
    const int size = 10;
    int array[size];
        int array2[size];
    for (int i = 0; i < size; i++){
        array[i] = rand()%100+1;
        array2[i] = array[i];
    }
    array2[9] = -7;
    cout << "Array1 : ";
    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Array2 : ";
    for (int i = 0; i < size; i++){
        cout << array2[i] << " ";
    }
    cout << endl;
}
