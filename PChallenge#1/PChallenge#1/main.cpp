#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <string>
#include <string.h>
#include <cstring>

#define DEBUG

using namespace std;

void showVec(vector<int> pvec [])
{
    for (int index = 0; index < pvec->size(); index++)
        cout << pvec->at(index) << " ";
    
    cout << endl;
} // end showArray

void swap(vector<int> pmults [], int i, int j)
{
    int temp = pmults->at(i);
    pmults->at(i) = pmults->at(j);
    pmults->at(j) = temp;
}

void sort(vector<int> pmults [], int size)
{
    for (int i = 0; i < size-1; i ++){
        for (int j = i; j < size; j ++){
            if (pmults->at(i)> pmults->at(j))
                swap(pmults, i, j);
        }
    }
}

int checkRedundant(vector<int> pmults [], int elmt)
{
    for (int i=0; i < pmults->size(); i++)
    {
        if (pmults->at(i) == elmt)
            return 1; // if exists
    }
    return 0; // if not exsits
}

bool isInteger(string str)
{
    int num;
    istringstream iss (str);
    
    iss >> num;
    
    return !iss.fail();
}

int main()
{
    vector<int> vec;
    vector<int> multiples;
    char tmp[256];
    int value;
    bool invalid;

    do{
        cout << "Enter the number to fill in the number set (to exit the number set, enter 0): " << endl;
        
        do {
            cin >> tmp;
            // check input validation
            if (isInteger(tmp)) {
                // convert the token into integers
                value = stoi(tmp, 0);
                if (value==0)
                    break;
                if (!checkRedundant(&vec, value))
                    vec.push_back(value);
                invalid = false;
            }
            else {
                cout << "Invalidate input." << endl;
                value = 0;
                invalid = true;
            }
        } while (!invalid);
    } while (invalid || value!=0);
    
    cout << "The number set is: ";
    showVec(&vec);
    cout << endl;
    
    int count;
    
    cout << "Please enter a number: ";
    cin >> count;
    
    
    for (int i = 0; i < vec.size(); i++){
        for (int j = 1; j <= count; j++){
            if (j%vec.at(i) == 0){
                if (!checkRedundant(&multiples, j))
                    multiples.push_back(j);
            }
        }
    }
    int sz = (int) multiples.size();
    sort(&multiples, sz);
    
#ifdef DEBUG
    showVec(&multiples);
#endif
    
    int sum = 0;
    
    for (int k = 0; k < multiples.size(); k++){
        sum += multiples.at(k);
    }
    
    cout << "The sum of the multiples of the number set below " << count << " is " << sum << "." << endl;
}
