#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double varianta (double x)
{
    return (x-1)*(x-1)-3;
}
double variantb (double x,double i)
{
        return exp(x-i)-sqrt(x+1);

}
void findotveta (double (*varianta)(double),double a, double b, double Exp)
{
    cout<<"x"<<setw(15)<<"F(x)"<<setw(11)<<"k_iter"<<endl;
    int i = 0;
    double c;
    while ((b-a)/2>Exp)
    {
        c=(a+b)/2;
        if ((varianta(a)*varianta(c))>0)
            a=c;
        else
            b=c;
        i++;
        cout<<c<<setw(15)<<varianta(c)<<setw(6)<<i<<setw(4)<<"    "<<(b-a)/2<<endl;
    }
  // return c;
}
double findotvetb(double (*variantb)(double, double), double a, double b, double eps, double s,double& c,int& i){
        double n=a;
        double m=b;
        while ((m-n)/2>eps)
        {
            c=(n+m)/2;
            if((variantb(n,s)* variantb(c,s))>0)
                n=c;
            else
                m=c;
            i++;
    }

        return c;
}


int main()
{
   char var ;
   double a, b, Exp = pow(10,-6), ds = 0.1, s=0.3,c;
   cin >> var;
   cin >> a >> b;
   if (var == 'a')
    for (int i = 0; i<=2; i=+Exp){
   //cout << varianta(i);
   findotveta( varianta, a,b,Exp);
   }
   else if (var == 'b'){
        cout<<"s"<<setw(11)<<"x"<<setw(15)<<"F(x)"<<setw(11)<<"k_iter"<<endl;
        int i = 0;
        for ( ; s<=0.7; s+=ds){
            i = 0;
            c =findotvetb( variantb, a,b,Exp,s,c,i);
cout<<s<<setw(11)<<c<<setw(15)<<variantb(c,s)<<setw(6)<<i<<setw(4)<<endl;
        }

        //7ocout<< findotvetb( variantb, a,b,Exp,s,c,i);
   }
   else
    cout << "Error";

    return 0;
}
