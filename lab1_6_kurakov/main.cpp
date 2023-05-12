#include <iostream>

#include <cmath>
using namespace std;

int main()
{
    setlocale (LC_ALL, "Russian");
    double x;
    cout << "x = ";
    cin >> x;
    int s, t;
    cout << "s = ";
    cin >> s;
    cout << "t = ";
    cin >> t;
    if (x+s*log(pow(x,t))>0 && pow(x,t)>0 && x!=1)
    {
        double y;
        y = (sqrt(exp(x)))/(sqrt(x+s*log(pow(x,t))));
        cout << "y = "<<y<<'\n';
    }
    else
        cout << "Не входит в область допустимых значений";
    return 0;
}
