#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int A [n][n], B [n][n];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            A[i][j]=rand()%100;
            cout <<setw(5)<<A[i][j];
        }
        cout <<'\n';
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            int max =0;
            for (int ii=i;ii<n;ii++)
            {
                for (int jj=0;jj<=j;jj++)
                {
                    if (A[ii][jj]>max)
                        max=A[ii][jj];
                }
            }
            B[i][j]= max;
        }
    }
    cout <<'\n';
        for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
         cout << setw(5)<<B[i][j];
        }
        cout << '\n';
    }
    return 0;
}
