//36    If Statements    BMI Categories    35-45  Jocelyn Ho
#include <iostream>
#include <string>
using namespace std;

int main ()
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
    
    double bmi;
    bmi = ((weight*0.453592)/((height*0.0254)*(height*0.0254)));
    
    string type;
    
    if (bmi < 15.0){
        type = "very severely underweight";
    }
    if ((bmi >= 15.0) && (bmi <= 16.0)){
        type = "severely underweight";
    }
    if ((bmi >= 16.1) && (bmi <= 18.4)){
        type = "underweight";
    }
    if ((bmi >= 18.5) && (bmi <= 24.9)){
        type = "normal weight";
    }
    if ((bmi >= 25.0) && (bmi <= 29.9)){
        type = "overweight";
    }
    if ((bmi >= 30.0) && (bmi <= 34.9)){
        type = "moderately obese";
    }
    if ((bmi >= 35.0) && (bmi <= 39.9)){
        type = "severely obese";
    }
    if (bmi >= 40.0){
        type = "very severely obese";
    }
    
    cout << "BMI Categories: " << type << " \n";
}
