#include <iostream>

#include <cmath>
using namespace std;

int main()
{
    setlocale (LC_ALL, "Russian");
    int k,n,num;
    double y;
    cout <<"k ";
    cin >>k;
    cout <<"n ";
    cin >>n;
    cout <<"������� ����� ";
    cin >> y;
    y = y - int(y);
//cout << y<<'\n';
    int n1 = int(y*pow(10,k+n));
//cout << y<<'\n';
/////////////////////////////////////
    int sum1 = 0,   sum2 = 0;
    for (int i=0;i<n; i++)
        {
            sum1 += n1%10;
            n1 /= 10;
        }
    for (int i=0;i<k;i++)
        {
            sum2 += n1%10;
            n1 /=10;
        }
//////////////////////////////////////
    cout <<"����� ������ ����: "<<sum2<<"\n����� ��������� ����: "<<sum1<<'\n';
    if (sum1==sum2)
        cout<<"��";
    else
        cout <<"���";
    return 0;
}
