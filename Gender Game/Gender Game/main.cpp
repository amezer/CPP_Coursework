//37    If Statements    Gender Game    50  Jocelyn Ho
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
    string fname, lname;
    char gen, mar;
    int age;
    
    cout << "What is your gender?(M or F) \n";
    cin >> gen;
    
    cout << "First Name:";
    cin >> fname;
    
    cout << "Last Name:";
    cin >> lname;
    
    cout << "Age:";
    cin >> age;
    
    if (age >= 20){
        cout << "Are you married?(Y or N)";
        cin >> mar;
        
        if ((mar == 'Y' || mar == 'y')&&(gen == 'M' || gen == 'm')){
            cout << "Then I should call you Mr. " <<lname << "."<<endl;
            return 0;
        }
        if ((mar == 'Y' || mar == 'y')&&(gen == 'F' || gen == 'f')){
            cout << "Then I should call you Mrs. "+ lname+ "."<<endl;
            return 0;
        }
        if ((mar == 'N' || mar == 'n')&&(gen == 'M' || gen == 'm')){
            cout << "Then I should call you Ms. "+ lname+ "."<< endl;
            return 0;
        }
        if ((mar == 'Y' || mar == 'y')&&(gen == 'F' || gen == 'f')){
            cout << "Then I should call you Miss "+ lname+ "."<< endl;
            return 0;
        }
    }
    else{
        cout << "Then I should call you "+ fname+ " "+ lname+ "."<<endl;
        return 0;
    }
}
