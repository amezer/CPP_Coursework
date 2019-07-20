//162    Sorting    Selection Sort - code provided    130  Jocelyn Ho

#include <iostream>
#include <array>
#include <time.h>
#include <stdlib.h>
using namespace std;


void swap( int a[] , int i, int j )
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void selection_sort(int a[], int size)
{
    for (int i = 0; i < size-1; i++){
        int min = i;
        for (int j = i; j < size; j ++){
            if (a[j] < a[min]){
                min = j;
            }
        }
        swap (a,i,min);
    }
}

int main()
{
    srand(time(NULL));
    const int size = 10;
    int arr[size];
    
    int i;
    
    // Fill up the array with random numbers
    for ( i=0; i < size; i++ )
    arr[i] = rand()%100+1;
    
    // Display it
    cout << "before: ";
    for ( i=0; i< size; i++ )
    cout << arr[i] << " " ;
    cout << endl;
    
    // Sort it
    selection_sort( arr,size );
    
    // Display it again to confirm that it's sorted
    cout << "after : ";
    for ( i=0; i<size; i++ )
    cout << arr[i] << " ";
    cout << endl;
}
