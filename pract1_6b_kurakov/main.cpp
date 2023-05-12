#include <iostream>
#include <windows.h>
#include <ctime>
#include <string.h>
using namespace std;

void FillArray(int *A, int size)
{
    for (int i=0; i<size; i++)
        A[i]=rand()%100;
}

void FillArray(double *A, int size)
{
    for (int i=0; i<size; i++)
        A[i]=double(rand())/RAND_MAX;
}

void FillArray(char *A, int size)
{
    for (int i=0; i<size; i++)
        A[i] = char (rand()%70 + 73);
}

template <typename T> void OutPutArray(T *A, int size)
{
    for (int i=0;i<size; i++){
        cout<<A[i];
    cout<<endl;}
}
void OutPutArray(char *A, int size)
{
    for (int i=0;i<size; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

void FillArray(char **A, int size)
{
    for (int i=0; i<size; i++)
    {
        A[i] = new char[10];
        cin.getline(A[i], 10, ' ');
    }
}


template <typename T> bool gt (T a, T b)
{
    return a > b;
}

bool gt (char* a, char* b)
{
    return strcmp(a, b) >=0;
}

void Sort(char **A,int start, int end)
{
    if (end - start < 2)
        return;
    if (end - start == 2)
    {
        if (gt(A[start],A[start + 1]))
            swap(A[start], A[start + 1]);
        return;
    }

    Sort(A, start, start + (end - start) / 2);
    Sort(A, start + (end - start) / 2, end);

    char **B = new char *[end - start];
    for (int i = 0; i < end - start; i++)
        B[i] = new char[10];

    int b1 = start;
    int e1 = start + (end - start) / 2;
    int b2 = e1;

    for (int i = 0; i < end - start; i++) {
        if (b1 >= e1 || (b2 < end && gt(A[b1], A[b2])))
        {
            B[i] = A[b2];
            b2++;
        }
        else
        {
            B[i] = A[b1];
            b1++;
        }
    }
for (int i=start;i<end; i++)
    A[i]=B[i-start];
}
template <typename T> void Sort(T *A,int start, int end)
{
    if (end - start < 2)
        return;

    if (end-start==2)
    {
        if(A[start]>A[start+1])
        {
            T a=A[start];
            A[start]=A[start+1];
            A[start+1]=a;
        }
        return;
    }

    Sort(A, start, start + (end-start)/2);
    Sort(A, start + (end-start)/2, end);

    T *B = new T[end-start];
    int b1 = start;
    int e1 = start + (end-start)/2;
    int b2 = e1;

    for (int i=0; i< end -start; i++)
    {
        if (b1>=e1 || (b2 < end && A[b2] <= A[b1]))
        {
            B[i]=A[b2];
            b2++;
        }
        else
        {
          B[i]=A[b1];
          b1++;
        }
    }

    for (int i=start; i<end ; i++)
    {
        A[i] = B[i - start];
    }

    delete [] B;
}



int main()
{
    SetConsoleOutputCP(CP_UTF8);

    cout<<"введите размер массива"<<endl;
    int size;
    cin>>size;

    char *A = new char [size];

    srand(time(NULL));
    FillArray(A,size);
    OutPutArray(A, size);

    Sort(A, 0, size);

    OutPutArray(A,size);
    delete [] A;
}
