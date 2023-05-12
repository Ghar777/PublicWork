#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*int main()
{
    int n;
    cin >>n;
    vector<vector<double>> A (n,vector<double>(n));
    vector <double> B(n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin >> A[i][j];
    for (int i=0;i<n;i++)
        cin >> B[i];
    vector <double> C(n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            C[i]=C[i]+(A[i][j]*B[j]);
    B.assign(C.begin(),C.end());
    cout <<'\n';
    for (int i=0;i<n;i++)
        C[i]=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            C[i]=C[i]+(A[i][j]*B[j]);
    for (int i=0;i<n;i++)
        cout << C[i]<<"  ";
    return 0;
}*/
int main()
{
    srand(time(NULL));
    vector<int> arr;
    ///////////////////////////////////////////////
    for (int i =0;i<200;i++)
        arr.push_back(rand()%100);
    //////////////////////////////////////////////
    vector <int> brr (100);
        for (vector<int> :: iterator i =brr.begin(); i<brr.end(); i++)
        *i=0;
    ///////////////////////////////////////////////
    for (int i =0; i<arr.size(); i++)
        brr[arr[i]]++;
    ///////////////////////////////////////////////

    for (int i =0;i<arr.size();i++)
       cout << arr[i]<<"    ";
   cout<<'\n'<<'\n';
    vector <int> crr;
    ////////////////////////////////////////////////
    for (int i =0;i<brr.size();i++)
        if (brr[i]==0)
            crr.push_back(i);
    for (int i =0;i<crr.size();i++)
    cout << crr[i]<<"    ";
    return 0;
}
