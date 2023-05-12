#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    setlocale (LC_ALL, "Russian");
    float x0,xm,dx, eps;
    eps = 1e-6;
    x0 = -4;
    xm = 6;
    dx = 0.5;
    int col = (xm-x0)/dx;
    cout <<setw(5)<<'x'<<setw(12)<<"yt"<<setw(12)<<"exp(x)-1"<<setw(5)<<'n'<<'\n';
    for (int i=0;i<=col;i++)
        {
            float x = x0+i*dx;
            int n=2;
            float yt=0;
            long long int fact =1;
            float px=x;
            for ( ;abs(px)/fact>eps; n++)
                {
                    yt += px/fact;
                    px *= x;
                    fact *= n;
                }
            cout <<setw(5)<<x<<setw(12)<<setprecision(6)<<yt<<setw(12)<<setprecision(6)<<exp(x)-1<<setw(5)<<n<<'\n';
        }
}

