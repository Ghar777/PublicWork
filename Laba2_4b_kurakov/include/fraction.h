#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <ostream>
using namespace std;
class fraction
{
    int n;
    int d;
public:
    fraction():n(0),d(1){};
    fraction (int _n, int _d): n(_n), d(_d){};
    fraction (const fraction &a): n(a.n), d(a.d){}
    fraction (fraction &&a):n(a.n), d(a.d){}
    ~fraction(){}
    fraction& operator = (fraction &&a)
    {
        n=a.n;
        d=a.d;
        return *this;
    }
    fraction& operator = (const fraction &a)
    {
        n=a.n;
        d=a.d;
        return *this;
    }
    void print ()const;
    friend ostream& operator << (ostream& out, const fraction& a);
    friend istream& operator >> (istream& in, fraction& a);
    fraction operator -= (const fraction &a);
    fraction operator += (const fraction &a);
    fraction operator *= (const fraction &a);
    fraction operator /= (const fraction &a);
    bool operator > (const fraction &a);
    bool operator < (const fraction &a);
    bool operator == (const fraction &a);
    bool operator != (const fraction &a);
    bool operator >= (const fraction &a);
    bool operator <= (const fraction &a);
        void cell ();
        void sokrdrob();
};
    fraction operator - (const fraction &b, const fraction &a);
    fraction operator + (const fraction &b, const fraction &a);
    fraction operator * (const fraction &b, const fraction &a);
    fraction operator / (const fraction &b, const fraction &a);
#endif // FRACTION_H
