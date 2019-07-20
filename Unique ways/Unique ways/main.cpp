#include <iostream>
#include <string.h>
#include <array>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

void for_num()
{
    for (int i = 1; i <= 9; i++){
        cout << i << "\t";
        if ( i%3 == 0)
            cout << endl;
    }
}

void array_num()
{
    const int size = 8;
    int arr[size];
    for (int i = 0; i <= size; i++){
        arr[i] = (i+1);
        cout << arr[i] << "\t";
        if ((i+1)%3 == 0)
            cout << endl;
    }
}

void vec_num()
{
    vector<int> num;
    for (int i = 1; i <= 9; i++){
        num.push_back(i);
    }
    for (int j = 1; j <= 9; j++){
        cout << num.at(j) << "\t";
        if (j%3 == 0)
            cout << endl;
    }
}

static int math_num(int start)
{
    if (start < 1)
        return 0;
    else{
        cout << (10 - start);
        return (10 - start);
    }
}

void array2_num()
{
    const int size = 3;
    int arr[size][size] = {
        {1,2,3}
        ,{4,5,6}
        ,{7,8,9}};
    
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void stuptd_num()
{
    cout << "1" << "\t";
    cout << "2" << "\t";
    cout << "3" << "\t" << endl;
    cout << "4" << "\t";
    cout << "5" << "\t";
    cout << "6" << "\t" << endl;
    cout << "7" << "\t";
    cout << "8" << "\t";
    cout << "9" << "\t" << endl;
}

void while_num()
{
    int count = 0;
    while (count != 9){
        count ++;
        cout << count << "\t";
        if (count%3 == 0)
            cout << endl;
    }
}

void ask_num()
{
    int start, end;
    
    do{
        cout << "Please enter 1: ";
        cin >> start;
        cout << endl;
    }while (start != 1);
    
    do{
        cout << "Please enter 9: ";
        cin >> end;
        cout << endl;
    }while (end != 9);
    
    for (int i = start; i <= end; i++){
        cout << i << "\t";
        if (i%3 == 0)
            cout << endl;
    }
}

void sqrt_num()
{
    const int size = 8;
    int arr[size];
    for (int i = 0; i <= size; i++){
        arr[i] = pow((i+1), 2);
    }
    for (int j = 0; j <= size; j++){
        arr[j] = sqrt(arr[j]);
        cout << arr[j] << "\t";
        if ((j+1)%3 == 0)
            cout << endl;
    }
}

void rand_num()
{
    srand(time(NULL));
    int start = 0, end = 0;
    while (start != 1)
        start = rand()%9+1;
    while (end != 9)
        end = rand()%9+1;
    for (int i = start; i <= end; i++){
        cout << i << "\t";
        if (i%3 == 0)
            cout << endl;
    }
}

int rec_num(int num)
{
    if (num > 9)
        return 0;
    else{
        cout << num << "\t";
        if (num%3 == 0)
            cout << endl;
        num++;
        return rec_num(num);
    }
}

int main()
{
    //This method is one of the most unique method because it is very simple
    cout << "1. for loop:" << endl;
    for_num();
    cout << endl;
    //This method assigns each value to the array with a for loop, and prints the value out by its index
    cout << "2. array:" << endl;
    array_num();
    cout << endl;
    //vec_num();
    //This method uses the idea of the reverse list of numbers to get the number list [the sum of getting 10]
    cout << "3. sum:" << endl;
    for (int i = 9; i >= 1 ; i--){
        math_num(i);
        cout << "\t";
        if ((10-i)%3 == 0)
            cout << endl;
    }
    
    cout << endl;
    //This method uses 2D array to print out the items in the array
    cout << "4. 2D array:" << endl;
    array2_num();
    
    cout << endl;
    //This method is special because it does not involve with any loop or sort of things
    cout << "5. stupid method:" << endl;
    stuptd_num();
    cout << endl;
    //Again, this method is unique because is uses while loop to decide whether it is time to stop printing
    cout << "6. while loop:" << endl;
    while_num();
    cout << endl;
    //This method is unique because it asks for the user to input only 1 and 9, then to count and print the values
    cout << "7. ask:" << endl;
    ask_num();
    cout << endl;
    //This method first n^2, then sqrt the number and prints the answer out
    cout << "8. square root:" << endl;
    sqrt_num();
    cout << endl;
    //This method uses random number to get the starting point 1 and ending point 9, then prints out count the value
    cout << "9. random:" << endl;
    rand_num();
    cout << endl;
    //This method is special because it uses recursive to print out the results
    cout << "10. recursive:" << endl;
    rec_num(1);
}
