#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale (LC_ALL, "rus");
    int k=0,number=0,x=1,i=0;
    for (k;k<13;k++){
    while (i<k)
    {
        x*=2;
        int xx = x;
        while (xx>0)
            {
                i++;
                xx/=10;
            }

    }

        if (i==k)
            number=x%10;
        if (i>k)
        {
            for (int j =0; j<i-k;j++)
                number = x/10;
            number %=10;
        }

    cout <<i<<"   "<<k<<"   "<<number<<'\n';
    }
    return 0;
}
//1248163264128...
