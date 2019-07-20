//100    Functions    Distance Formula - code provided    50   Jocelyn Ho

#include <iostream>
#include <cmath>
using namespace std;



double distance( double x1, double y1, double x2, double y2 )
{
    return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}

int main()
{
    double d1 = distance(-2.0,1.0 , 1.0,5.0);
    cout << " (-2,1) to (1,5) => " << d1 << endl;
    
    double d2 = distance(-2.0,-3.0 , -4.0,4.0);
    cout << " (-2,-3) to (-4,4) => " << d2 << endl;
    
    cout << " (2,-3) to (-1,-2) => " << distance(2.0,-3.0,-1.0,-2.0) << endl;
    
    cout << " (4,5) to (4,5) => " << distance(4.0,5.0,4.0,5.0) << endl;
    
    return 0;
}


