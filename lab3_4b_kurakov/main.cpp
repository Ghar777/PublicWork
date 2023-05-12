#include <iostream>

using namespace std;

int main()
{
    for (int q=1;q<101;q++){
        const int n = 100;
        int a[n]={1,};
        int next =0, baza = 10;
        for (int i=0;i<q;i++)
        {
            for (int j=0;j<n;j++)
            {
                a[j]*=5;
                if(next)
                {
                    a[j]+=next;
                    next=0;
                }
                if (a[j]>= baza)
                {
                    next = a[j]/baza;
                    a[j]%=baza;
                }
            }
        }
        for (int j=n-1;j>=0;j--)
        {
            if (a[j]!=0)
            {
                for (int i=j;i>=0;i--)
                {
                    cout << a[i];
                }
                cout <<'\n';
                break;
            }
        }
    }
    return 0;
}
