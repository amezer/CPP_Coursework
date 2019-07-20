//104    Functions    Area Calculator    110   Jocelyn Ho

#include <iostream>
#include <math.h>
using namespace std;

static int area_square(int side)
{
    return side*side;
}

static int area_rectangle(int length, int width)
{
    return length*width;
}

static double area_triangle(int base, int height)
{
    return (base*height)/2;
}

static double area_circle(int radius)
{
    return M_PI*radius*radius;
}

static int f_question(int ans)
{
    cout << "===========================" << endl;
    cout << "1) Square" << endl;
    cout << "2) Rectangle" << endl;
    cout << "3) Triangle" << endl;
    cout << "4) Circle" << endl;
    cout << "5) Quit" << endl;
    cout << "Which shape: ";
    cin >> ans;
    return ans;
}

int main()
{
    while (true) {
        int side, radius, length, width, base, height, ans;
        int type = f_question(ans);
        
        switch (type) {
            case 1:
            cout << "Side: ";
            cin >> side;
            cout << endl;
            cout << "The area is: " << area_square(side) << endl;
            break;
            case 2:
            cout << "Length: ";
            cin >> length;
            cout << endl;
            cout << "Width: ";
            cin >> width;
            cout << endl;
            cout << "The area is: " << area_rectangle(length, width) << endl;
            break;
            case 3:
            cout << "Base: ";
            cin >> base;
            cout << endl;
            cout << "Height: ";
            cin >> height;
            cout << endl;
            cout << "The area is: " << area_triangle(base, height) << endl;
            break;
            case 4:
            cout << "Radius: ";
            cin >> radius;
            cout << "The area is: " << area_circle(radius) << endl;
            break;
            case 5:
            cout << "Bye." << endl;
            return 0;
            default:
            cout << "Invalid input. Please try again.";
        }
    }
    return 0;
}
