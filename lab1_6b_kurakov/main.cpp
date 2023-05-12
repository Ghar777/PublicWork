#include <iostream>

#include <cmath>
using namespace std;

int main()
{
    //setlocale (LC_ALL, "Russian");
    signed char x;
    cout << "x = ";
    cin >> x;
////////////////////////////////////////////1011 1001
    cout << "№0 = " << (x&1) << '\n';
    cout << "№3 = " << ((x>>3)&1) << '\n';
    cout << "№7 = " << ((x>>7)&1) << '\n';
////////////////////////////////////////////
    x=x^8;
    x=x^128;
    cout << x;
    return 0;
}
