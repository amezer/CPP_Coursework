// 8 Basics and Printing Numbers and Math 7 Jocelyn Ho
//if one uses 57/3 then java will use "interger division" [which will not show the decimal place], but if one uses 57.0/3.0, then it will use "decimal point division" [which will show the decimal place]
#include <iostream>
using namespace std;

int main()
{
    //states the question
    cout << "I will count how many bags of potato chips I own \n";
    //calculating the bags of Pringles by using floating point division
    cout << "Pringles: " << (57.0/3.0) << "\n";
    //calculating the bags of Lays by using floating point division
    cout << "Lays: " << (35.0/7.0) << "\n";
    //states the question
    cout << "Do I have more Pringles than Lays \n";
    //comparing the bags of potato chips and print out the result as true/false
    if ((57.0/3.0) > (35.0/7.0) == true)
        cout << "Yes. \n";
}
