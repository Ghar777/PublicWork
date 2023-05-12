#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;
int main()
{
    srand(time(NULL));
    vector<int> arr;
    ///////////////////////////////////////////////
    for (int i =0;i<1000;i++)
        arr.push_back(rand()%100);
    //////////////////////////////////////////////
    vector <int> brr [100];
    for (int i =0;i<100;i++)
        brr[i]=0;
    ///////////////////////////////////////////////
    for (int i =0; i<arr.size(); i++){
        brr[arr[i]]=1;
    }
    ///////////////////////////////////////////////
   // Sort(arr,0,size);
    for (int i =0;i<brr.size();i++)
       cout << arr[i]<<"    ";
   cout<<'\n'<<'\n';

    int c_schet = 0;
    vector <int> crr;
    ////////////////////////////////////////////////
    for (int i =0;i<brr.size();i++)
        if (brr[i]==0){
            crr[c_schet]=i;
            c_schet++;
        }
    for (int i =0;i<crr.size();i++)
    cout << crr[i]<<"    ";
    return 0;
}
