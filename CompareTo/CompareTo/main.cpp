//38 If Statements compareTo() Challenge 35 Jocelyn Ho
#include <iostream>
#include <array>
using namespace std;

int main()
{
    string s[] = {"tea", "fog", "dog", "pop", "cat", "eye", "bee", "mad"};
    int size = 8;
    for (int i=0; i < size; i++)
    {
        for (int j=i+1; j < size; j++){
            cout << "Comparing " << s[i] << " with " << s[j] << " will produce ";
            cout << s[i].compare(s[j]) << endl;
        }
    }
    
    string cat = "cat";
    string frog = "frog";
    cout << "Comparing tree with tree will produce ";
    cout << cat.compare("cat") << endl;
    
    cout << "Comparing frog with frog will produce ";
    cout << frog.compare("frog") << endl;
}
