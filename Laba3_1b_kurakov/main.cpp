#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int main()
{
    string a;
    cin >>a;
    double end = 0;
    ////////////////////////////////////////////////////
    int polog=0;
    for (int i=0; a[i]!='.';i++)
        polog++;
    ////////////////////////////////////////////////////
    for (int i=polog-1; i>=0;i--)
        if (a[i]=='1')
            end += pow(2,(polog-i-1));
    ////////////////////////////////////////////////////
    for (int i=a.length()-1;i>polog;i--)
        if (a[i]=='1')
            end += 1/pow(2,i-polog);
    ////////////////////////////////////////////////////
    cout <<end;
    return 0;
}
/*int main()
{
    string a;
    int b [256] {};
    cin>>a;
    for (int i=0; i<a.length(); i++)
        b[(int)a[i]]++;
    for (int i=0; i<a.length(); i++)
        if (b[(int)a[i]]==1)
            a.erase(i,i+1);

    cout<<a;
    return 0;
}*/
