#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    setlocale (LC_ALL, "Russian");
   double x[4];
   int n = sizeof(x)/sizeof(x[0]);
   for (int i=0; i<4; i++)
   {
       cout << "x["<<i<<"] =";
       cin >> x[i];
   }
   bool vibor;
   cout << "Как хотите отсортировать(1 - if; 0 - без if):";
   cin >> vibor;
   if (vibor == 0)
   sort (x, x+n);
   else if (vibor == 1)
   {
       for (int i=0; i<3; i++){
            for (int j=0; j<3; j++)
            {
                int q;
                (x[j]>x[j+1]) ?
                q = x[j+1],
                x[j+1]= x[j],
                x[j]=q
                : 0;

            }
       }
   }
   cout << "Отсортированно:\n";
   for (int i=0; i<4; i++)
    cout <<x[i]<<"; ";
    return 0;
}
