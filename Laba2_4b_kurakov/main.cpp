#include <iostream>
#include <ostream>
#include "fraction.h"
using namespace std;


int main()
{
    fraction a(1,4);
    fraction d(a);
    cin >> a;
    cout <<(a!=d)<<'\n';

    //cout <<a<<" "<<d<<'\n';
    //a.sokrdrob();
    //a.cell();
    return 0;

}
