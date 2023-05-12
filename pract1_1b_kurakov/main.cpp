#include <iostream>
#include <iomanip>
using namespace std;

void vvod (int n, int *arr)
{

    for (int i = 0; i<n; i++)
        cin >> *(arr+i);

}
void raspolog (int n, int *arr_s,int **arr_f)
{
    for (int i = 0; i<n; i++)
        for (int j=0; j<n; j++)
                    arr_f  [i][j]=0;
    int s = 0;
    int krug = 0;
    for (krug;krug<n/2;krug++)
    {
       for (int levo =krug;levo <n-1-krug; levo++)
        {
            *(*(arr_f+levo)+krug)=arr_s[s];
            s++;
        }
       for (int niz =krug;niz <n-krug-1; niz++)
        {
            arr_f[n-krug-1][niz]=arr_s[s];
            s++;
        }
        for (int pravo =krug;pravo <n-1-krug; pravo++)
        {
            arr_f[n-1-pravo][n-1-krug]=arr_s[s];
            s++;
        }
        for (int vverh =krug;vverh <n-krug-1; vverh++)
        {
            arr_f[krug][n-1-vverh]=arr_s[s];
            s++;
        }
    }
    if (n%2==1)
        arr_f[n/2][n/2]=arr_s[s];
    //cout <<s<<'\n';
}
void vivod (int n, int **arr)
{
    for (int i = 0; i<n; i++){
        for (int j=0; j<n; j++)
            cout << arr [i][j]<<setw(3);
            cout << '\n';
    }
}
int main()
{
    int n;
    cin >> n;
    //cout <<"y"<<'\n';
    int a = n*n;
    int* arr_start = new int [a];
    int** arr_finish = new int* [n];
    for (int i=0;i<n;i++)
        arr_finish[i] = new int [n];

    vvod (a,arr_start);
    raspolog (n,arr_start,arr_finish);
    vivod (n,arr_finish);
    delete [] arr_start;
    for (int i=0;i<n;i++)
        delete [] arr_finish[i];
    delete [] arr_finish;
    return 0;
}
