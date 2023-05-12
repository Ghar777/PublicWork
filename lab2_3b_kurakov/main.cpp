#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale (LC_ALL, "Russian");
    int n, max0, kolvo0 =0, kolvo0max = 0;
    cout << "n=";
    cin >>n;
    for (int i=2;i<=n;i++)
    {
        int t=0;
        for (int j=2;j<=sqrt(i);j++)
        {
            if (i%j==0)
            {
                t++;
                break;
            }
        }
        if (t==0)
        {
            cout <<i << ' ';
            kolvo0 =0;
            int i0=i;
            while (i0>=1)
            {
                if (i0%2==0)
                    {
                        kolvo0++;
                        cout << '0';
                    }
                else
                    cout << '1';
                i0/=2;

            }
            if (kolvo0>kolvo0max)
               {
                    kolvo0max = kolvo0;
                    max0=i;
               }
               cout << '\n';
        }

    }
    cout << max0;
    return 0;
}
