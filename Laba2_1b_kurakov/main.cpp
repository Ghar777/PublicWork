#include <time.h>
#include <ostream>
#include <iostream>
#include <cassert>
#include "my_vector.h"
using namespace std;

int main()
{
    setlocale (0,"Russian");

    int n;
    cout << "������� ������ �������" << endl;
    cin >> n;
    Vector a(n);
    Vector shab;
    shab.Set_size(mass+1);

    for (int i = 0; i < mass + 1; i++ )
        shab[i] = 0;

    cout << "�������� ������" << endl;
    cout << a;

    for (int i = 0; i < n; i++)
        shab[a[i]]++;

    int size = 0;
    for (int i = 1; i < mass+1; i++ )
        if (shab[i] == 0)
            size++;

    Vector res(size);
    size = 0;
    for (int i = 1 ; i < mass; i++)
    {
        if (shab[i] == 0)
        {
            res[size] = i;
            size++;
        }
    }

    cout << "���������" << endl;
    cout << res;
}


















