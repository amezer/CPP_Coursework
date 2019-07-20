//20    Keyboard Input    BMI Calculator    15-28  Jocelyn Ho
#include <iostream>
using namespace std;

int main()
{
    cout << "Your height in inches: ";
    double height;
    cin >> height;
    cout << "\n";
    cout << "Your weight in pounds: ";
    double weight;
    cin >> weight;
    cout << "\n";
    
    cout << "Your BMI is " << ((weight*0.453592)/((height*0.0254)*(height*0.0254))) << "\n";
}
