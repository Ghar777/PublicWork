#include <iostream>
#include <list>
#include <time.h>
using namespace std;
double summ(list<double> &l,int n)
{
    auto first = l.begin();
    auto last = l.end();
    last--;
    int x1;
    int x2;
    int x3;
    int sum = 0;

    while (last != l.begin())
    {
        x1 = *first;
        first++;
        x2 = *first;
        x3 = *last;
        sum += x1 + x2 + n*x3;
        last--;
        n--;
    }
    return sum;
}
int main()
{
    setlocale (LC_ALL, "Russian");
    srand(time(NULL));

    cout << "введите размер списка" << endl;
    int n;
    cin >> n;
    int n1 = n;
    list<double> l;
    for (int i=0;i<n;i++)
    {
        double bofer = 0;
        cin >> bofer;
        l.push_back(bofer);
    }
    for (double i : l)
        cout <<i<<"  ";

    cout << "результат: " << summ(l,n1) << endl;
}
/*int main()
{
     setlocale (LC_ALL, "Russian");
    srand(time(NULL));

    int a [256] {0};
    list<char> L1(0);
    list<char> L2(0);
    cout << "исходный список" << endl;
    L1.push_back('c');
    L1.push_back('c');
    L1.push_back('3');
    L1.push_back('f');
    L1.push_back('f');
    L1.push_back('c');
    for (char i : L1)
        cout <<i<<'\n';
    for (char i : L1)
        a[i]++;
    for (int i = 0; i < 256; i++)
    {
        if(a[i]==2)
        {
            char c = char(i);
            L2.push_back(c);
        }
    }

    cout << "результат" << endl;
    for (auto i = L2.begin(); i!=L2.end();i++)
        cout <<*i<<'\n';
    return 0;
}*/
