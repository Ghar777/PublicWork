#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    setlocale (LC_ALL, "Russian");
    int l, k;
    cout << "������� ���������� ����:";
    cin >> k >> l;
    int m, n;
    cout << "������� ���������� �������� ������:";
    cin >> m >> n;
    if ((abs(m-k)==2&&abs(n-l)==1)||(abs(m-k)==1&&abs(n-l)==2))
        cout << "���� �� ���� ���";
    if ((abs(m-k)==3 && abs(n-l)==1) || (abs(m-k)==1 && abs(n-l)==3) || (abs(m-k)==1 && abs(n-l)==1) || (abs(m-k)==2 && abs(n-l)==0) || (abs(m-k)==0 && abs(n-l)==2) || (abs(m-k)==4 && abs(n-l)==0) || (abs(m-k)==0&&abs(n-l)==4) || (abs(m-k)==4&&abs(n-l)==2) || (abs(m-k)==2&&abs(n-l)==4)||(abs(m-k)==3&&abs(n-l)==3))
        cout << "���� �� ��� ����";
        else
            cout <<"�� ���� ������";
    return 0;
}
