#include "fraction.h"
#include <iostream>
#include <ostream>
#include <cmath>
using namespace std;

    void fraction::print () const
    {
        cout <<n<<'/'<<d;
    }

    ostream& operator << (ostream& out, const fraction& a)
    {
        out << a.n <<'/'<<a.d;
    return out;
    }

    istream& operator >> (istream& in, fraction& a)
    {
        in  >> a.n;
        cout <<'/';
        in >> a.d;
    return in;
    }
    fraction operator - (const fraction &b, const fraction &a)
    {
        fraction aa (b);
        aa-=a;
        return aa;
    }
     fraction fraction::operator -= (const fraction &aa)
    {
        fraction a (aa);
        n *=a.d;
        a.n*=d;
        d*=a.d;
        a.d=d;
        n-=a.n;
        return *this;
    }
    fraction operator + (const fraction &b, const fraction &a)
    {
        fraction aa (b);
        aa+=a;
        return aa;
    }
     fraction fraction::operator += (const fraction &aa)
    {
        fraction a (aa);
        n *=a.d;
        a.n*=d;
        d*=a.d;
        a.d=d;
        n+=a.n;
        return *this;
    }
    fraction operator * (const fraction &b, const fraction &a)
    {
        fraction aa (b);
        aa*=a;
        return aa;
    }
    fraction operator / (const fraction &b, const fraction &a)
    {
        fraction aa (b);
        aa/=a;
        return aa;
    }
    fraction fraction::operator *= (const fraction &a)
    {
        n*=a.n;
        d*=a.d;
        return *this;
    }
    fraction fraction::operator /= (const fraction &a)
    {
        int _n = a.n;
        int _d = a.d;
        n *= _d;
        d *= _n;
        return *this;
    }
    bool fraction::operator > (const fraction &a)
    {
       double left = (double)n/d;
       double right = (double)a.n/a.d;
        if (left > right)
            return true;
        else
            return false;

    }
    bool fraction::operator < (const fraction &a)
    {
       double left = (double)n/d;
       double right = (double)a.n/a.d;
        if (left < right)
            return true;
        else
            return false;

    }
    bool fraction::operator == (const fraction &a)
    {
        double left = (double)n/d;
       double right = (double)a.n/a.d;
        if (left == right)
            return true;
        else
            return false;

    }
    bool fraction::operator != (const fraction &a)
    {
        double left = (double)n/d;
       double right = (double)a.n/a.d;
        if (left != right)
            return true;
        else
            return false;

    }
    bool fraction::operator >= (const fraction &a)
    {
        double left = (double)n/d;
       double right = (double)a.n/a.d;
        if (left >= right)
            return true;
        else
            return false;


    }
    bool fraction::operator <= (const fraction &a)
    {

        double left = (double)n/d;
       double right = (double)a.n/a.d;
        if (left <= right)
            return true;
        else
            return false;

    }
        void fraction::cell ()
    {
        if (n>d&&n%d!=0)
            cout << n/d<<'/'<<n%d<<'/'<<d;
        if (n>d&&n%d==0)
            cout << n/d;
    }
    int gcd(int a, int b){
    a = abs(a), b = abs(b);
    if (b == 0)return a;
    else return gcd(b, a%b);
}
    void fraction::sokrdrob(){
    int x = gcd(n, d);
    n /= x;
    d /= x;
    cout << n << "/" << d<<'\n';
    }
