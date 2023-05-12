#include <iostream>

using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////
void vector_vichsl (double** arr, double* vrr, int size_a)
{
    double** aarr = new double* [size_a];
        for (int i=0; i<size_a; i++)
            aarr[i]= new double [size_a];
    double* vvrr = new double [size_a];
    for (int i =0; i<size_a;i++)
        for (int j =0; j<size_a;j++){
            aarr [i][j]=arr[i][j];
            arr[i][j]=0;
        }
    for (int i =0; i<size_a;i++)
        for (int j =0; j<size_a;j++)
            for (int u =0; u<size_a;u++)
             arr [i][j]+=aarr[u][j]*aarr[i][u];
    for (int i =0; i<size_a;i++){
        vvrr[i]=vrr[i];
        vrr[i]=0;
    }
        for (int i =0; i<size_a;i++)
            for (int u =0; u<size_a;u++)
             vrr [i]+=arr[i][u]*vvrr[i];
     for (int i =0; i<size_a;i++)
      delete [] aarr[i];
     delete [] aarr;
     delete [] vvrr;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
double vector_vichsl (double* arr, double* aarr, double* vrr, double* vvrr, int size_a)
{
    for (int i =0; i<size_a;i++)
        for (int j =0; j<size_a;j++){
            aarr [i*size_a+j]=arr[i*size_a+j];
            arr[i*size_a+j]=0;
        }
    for (int i =0; i<size_a;i++)
        for (int j =0; j<size_a;j++)
            for (int u =0; u<size_a;u++)
             arr [i*size_a+j]+=aarr[u*size_a+j]*aarr[i*size_a+u];
    for (int i =0; i<size_a;i++){
        vvrr[i]=vrr[i];
        vrr[i]=0;
    }
        for (int i =0; i<size_a;i++)
            for (int u =0; u<size_a;u++)
             vrr [i]+=arr[i*size_a+u]*vvrr[i];
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int n;
    cin >>n;

//////////////////////////////////////////////////////////////////////////////////////////////////////
    if (n==1)
    {
        int size_a;
        cin >> size_a;
        double** arr = new double* [size_a];
        double* vrr = new double [size_a];
        for (int i=0; i<size_a; i++)
            arr[i]= new double [size_a];

        cout << "vvedite matricy A: ";
        for (int i =0; i<size_a;i++)
            for (int j =0; j<size_a;j++)
                cin >> arr[i][j];
        cout << "vvedite vector b: ";
        for (int i =0; i<size_a;i++)
            cin >> vrr[i];
        vector_vichsl(arr,vrr, size_a);
        for (int i =0; i<size_a;i++){
                cout << vrr[i];
                cout<<'\n';
        }
        for (int i =0; i<size_a;i++)
            delete [] arr[i];
        delete [] arr;
        delete [] vrr;

    }
    ///////////////////////////////////////////////////////////////////////////////////////
    else if (n==2)
    {
        int size_a;
        cin >> size_a;
        double* arr;
        arr = new double [size_a*size_a];
        double* aarr;
        aarr = new double [size_a*size_a];
        double* vrr = new double [size_a];
        double* vvrr = new double [size_a];
        cout << "vvedite matricy A: ";
        for (int i =0; i<size_a;i++)
            for (int j =0; j<size_a;j++)
                cin >> arr[i*size_a+j];
        cout << "vvedite vector b: ";
        for (int i =0; i<size_a;i++)
            cin >> vrr[i];
        vector_vichsl (arr, aarr,vrr, vvrr, size_a);
        for (int i =0; i<size_a;i++){
            cout << vrr[i]<< "   ";
        }
        delete [] arr;
        delete [] aarr;
        delete [] vrr;
        delete [] vvrr;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////
    else
        {
            cout << "Error";
                return 0;
        }

    return 0;
}
