#include <iomanip>    // setw
#include <iostream>   //  cin cout
#include <stdio.h>
#include <stdlib.h>
#include <clocale>
#include <algorithm>
#define N n
using namespace std;

int main()
{
    const int n = 6;
    const int m = 4;
    int  a[n] = { 0 };
    int  b[m] = { 0 };
    setlocale(LC_ALL, "rus");
        enum eArrayInit
    {   Uninited = 0, WithConst, WithRand, ByUser, };

    cout << " �������� ��� �������������:\n"
        << WithConst << ".�����������\n"
        << WithRand  << ".���������� �������\n"
        << ByUser    << ".������ �������\n";
    cout << "����� ������ ������ �������� ���������\n ��� �����: ";

    int ch = 0;    cin >> ch;
    switch (ch)
    {
      case WithConst:
      { // ���������� ������� ���������� ��������
        for (int i = 0; i < N; i++){ a[i] = i; b[i]=i+1;}
        break;
      }
      case WithRand:
      { // ������������� ������� ���������� �������
        for (int i = 0; i < N; i++) { a[i] = rand() % 100; b[i] = rand() % 150;}
        sort(begin(a),end(a));
        sort(begin(b),end(b));
        break;
      }
      case ByUser:
      {   // ���� ��������� ������� � ����������
        for (int i = 0; i < N; i++)  cin >> a[i];
        for (int i = 0; i < N; i++)  cin >> b[i];
        break;
      }
      default:  cout << "��������� �����������" << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) cout <<"   " << a[i]; cout<<'\n';
    for (int i = 0; i < N; i++) cout <<"   " << b[i];
    cout << endl;

    int k=m+n, c[k];
    int q=0,w=0,e=0;
    for (;w<m&&q<n;e++)
    {
        if (a[q]<b[w])
            {
                c[e]=a[q];
                q++;
            }
        else
            {
                c[e]=b[w];
                w++;
            }
    }
    if (w>=m)
                for (int i =e;i<k;i++)
                        c[i] = a [i-w];
    if (q>=n)
                for (int i =e;i<k;i++)
                        c[i] = b[i-q];

    for (int i=0;i<k;i++)
              cout <<c[i]<<"   ";
}
