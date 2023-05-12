#include <iostream>
using namespace std;

    const int n = 45000;
    bool a[n];

int main()
{
    int max = 0;
    int max0 = 0, kolvo0 =0, kolvo0max = 0;

    for (int i = 0; i < n; i++)
        a[i] = 1;
/////////////////////////////////////////////////
    for (int i = 2; i < n; i++)
        for (int j = i*i; j < n; j += i)
            {
                a[j] = 0;
                //cout << j << "  ";
            }
    //for (int i=0;i<n;i++)
       // cout <<a[i]<<"  ";
/////////////////////////////////////////////////
    for (int i = 2; i < n; i++)
    {
        if (a[i]==1)
        {
           // cout <<i << ' ';
            kolvo0 =0;
            int i0=i;
            while (i0>=1)
            {
                if (i0%2==0)
                    {
                        kolvo0++;
                        i0/=2;
                    }
                else
                i0/=2;

            }
            if (kolvo0>kolvo0max)
               {
                    kolvo0max = kolvo0;
                    max0=i;
               }
               //cout << '\n';
        }

    }
    /////////////////////////////////////////////
    for (int i = 2; i < n; i++)
        if (max < i&&a[i]==1)
            max = i;
    cout <<  "max prost: "<<max<<'\n';
    cout << "max 0:"<< max0;
}
