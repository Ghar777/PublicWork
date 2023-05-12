#include <cassert>
#include <time.h>
#include <ostream>
#include <iostream>
using namespace std;

#ifndef MYCLASS_H
#define MYCLASS_H

int mass = 100;
class Vector
{
    int* arr;
    int size;

public:

    Vector();
    Vector(int size);
    Vector(const Vector & a);
    ~Vector();
    void Set_size(int size);
    void Get_vector() const;
    int Get_size() const;
    Vector operator = (const Vector &a);
    friend ostream& operator << (ostream& out, const Vector a);
    friend istream& operator >> (istream& in, Vector& a);
    int& operator[](int ind);
    const int& operator[](int ind) const;
};
#endif
