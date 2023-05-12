#include <iostream>

#include <cmath>
using namespace std;

int main()
{
    setlocale (LC_ALL, "Russian");
    int R1 , R2;
    cout << "R1 = ";
    cin >> R1;
    cout << "R2 = ";
    cin >> R2;
    int x,y;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    if (x<=0 && y>=0 && x*x + y*y <= R2*R2)
        cout << "Точка принадлежит";
    else if (x>=0 && y<=0 && x*x + y*y >= R2*R2
             && x*x + y*y <= R1*R1)
                cout << "Точка принадлежит";
    else
        cout << "Точка не принадлежит";
    return 0;
}
