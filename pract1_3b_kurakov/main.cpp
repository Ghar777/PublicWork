#include <iostream>

using namespace std;
int& poisk (int n, int* arr)
{

    int max = 0, k =0;
    //for (int j=0; j<n; j++)
    for (int i=0; i<n; i++)
        if (arr[max]< arr[i])
           max =i;
    for (int i=0; i<n; i++)
        if (arr[max]==arr[i])
        k++;

    if (k==2)
        return arr[max];
    else
        {
            int i = 0;
            for (int j=0;j<n;j++)
            for (i; i<n;i++)
                if (arr[max]< arr[i])
                    swap(arr[max], arr[i]);
            return arr [max +1];
        }
    //cout << arr[max];

}
int main()
{
    int n,k;
    cin >> n;
    cin >> k;
    int* arr = new int [n];
    int &z=arr[0];
    for (int i =0; i<n; i++)
        cin >> arr[i];
    poisk (n, arr) = k;
    for (int i =0; i<n; i++)
        cout << arr[i]<<"  ";
    return 0;
}
