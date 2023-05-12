#include <iostream>

#include <cmath>
using namespace std;

int main()
{
    setlocale (LC_ALL, "Russian");
    int n,n1,num,k;
    cout << "n = ";
    cin >> n;
    n1=n;
    k=0;
    /////////////////////////////////////
    while (n1%10 != 0)
        {
            n1=n1/10;
            num++;
        }
    int x[num];
    for (int i=0;i<num;i++)
    {
        x[i]=(n/int (pow (10,i)))%10;
    }
    /////////////////////////////////////
     for (int i=0;i<num;i++)
        {
            if (x[i]==x[num-1-i])
                    k++;
        }
    if (k == num)
        cout <<"Yes \n";
    else
        cout <<"No \n";
    return 0;
}
