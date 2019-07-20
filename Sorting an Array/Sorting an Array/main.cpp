//159    Sorting    Sorting an Array - code provided    100   Jocelyn Ho

#include <iostream>
#include <array>
using namespace std;

int main()
{
    int size = 10;
    int arr[] = { 45, 87, 39, 32, 93, 86, 12, 44, 75, 50 };
    cout << "before: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    int swap = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < i; j++){
            if (arr[j] > arr[i]){
                swap = arr[j];
                arr[j] = arr[i];
                arr[i] = swap;
            }
        }
    }
    cout << "after: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
