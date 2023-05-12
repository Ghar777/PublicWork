#include <time.h>
#include <ostream>
#include <iostream>
#include <cassert>
#include <windows.h>
#include "my_vector.h"
using namespace std;

 Vector::Vector() : arr(0), size(0){}
 Vector::Vector(int size) : arr(new int[size]), size(size)
{
    srand(time(0));
    for (int i = 0; i < this -> size; i++)
    {
        arr[i] = rand() % mass + 1;
    }
}

Vector::Vector(const Vector & a) : size(a.size), arr(new int[a.size])
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = a.arr[i];
    }
}

Vector::~Vector()
{
    delete[] arr;
}

void Vector::Set_size(int size)
{
    delete[] arr;
    this -> size = size;
    arr = new int[this->size];
}

void Vector::Get_vector() const
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Vector::Get_size() const
{
    return size;
}

Vector Vector::operator = (const Vector &a)
{
    delete [] arr;
    this -> size = a.size;
    for (int i = 0; i < size; i++)
    {
        arr[i] = a.arr[i];
    }
}


 ostream& operator << (ostream& out, const Vector a)
{
    for (int i = 0; i < a.size; i++)
    {
        out << a.arr[i] << " ";
    }
    out << endl;
    return out;
}

 istream& operator >> (istream& in, Vector& a)
{
    for (int i = 0; i < a.size; i++)
    {
        in >> a.arr[i];
    }
    return in;
}


int& Vector::operator[](int ind)
{
    assert (ind >= 0 && ind < size);
    return arr[ind];
}

const int& Vector::operator[](int ind) const
{
    assert(ind >= 0 && ind < size);
    return arr[ind];
}



















