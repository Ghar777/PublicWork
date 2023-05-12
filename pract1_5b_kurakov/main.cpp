#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double F_x(double x, double t, double s)
{
    return pow(1+x*x,1/t)/exp(sin(x)+s);
}
double S_x_M1 (double (*F_x)(double, double, double),double& summ, double& shag,int number)
{
    shag = shag/number;
    summ =0;
    double x =-1;
    double as =0;
    double aat=2;
    for (;as<2; as+=0.5)
        for (;aat<5;aat++)
            while (x<=1){
                summ+=F_x(x,aat,as)*shag;
                x+=shag;
     //cout <<s <<"  "<<t<<"   "<<summ;

    }
    x= -1;
   // cout <<s <<"  "<<t<<"   ";
    return summ;
}
int main()
{
    double eps = pow (10,-6);
    double a =-1,b=1;
    double shag = (b-a)/1000;
    double summ =0;
    int i=1;
    int n =2;
    while (abs(S_x_M1(F_x, summ,shag,n-1)-S_x_M1(F_x, summ,shag,n))>=eps){

        shag/=2;
        i++;
    }
     for (double k= 0;k<2; k+=0.5){
                for (int q = 2;q<5;q++)
                        cout <<setw(3)<<k<<setw(2)<<q<<setw(8)<<S_x_M1(F_x, summ,shag,n-1)<<setw(3) << i<<"\n";
         }
    //cout <<S_x_M1(F_x, summ,shag,n-1)<<"     " << i;
    return 0;
}
