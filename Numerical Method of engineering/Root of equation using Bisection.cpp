#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    double val=x*x*x - x - 4;
    return val;
}
double ERROR(double m, double oldM){
    return  fabs((m-oldM)/m)*100;
}
int main()
{
    double a=1.0, b=2.0, m;
    if(f(a)*f(b)>0){
        cout<<"value of a, b is invalid\n";
        return 0;
    }
    double error=.05;
    int i=0;
    double oldM=(a+b)/2;
    m=oldM;
    if(f(a)*f(m)<0)b=m;
    else if(f(m)*f(b)<0)a=m;

    while(1){
        i++;
        m=(a+b)/2;
        cout<<ERROR(m,oldM)<<"  aaa\n";
        if(ERROR(m,oldM)<=error)break;
        else if(f(a)*f(m)<0)b=m;
        else if(f(m)*f(b)<0)a=m;
        oldM=m;
    }
    cout<<"Number of iteration : "<<i<<endl;
    cout<<"Ans : "<<m;
    return 0;
}
