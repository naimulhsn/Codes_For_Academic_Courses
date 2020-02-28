#include<bits/stdc++.h>
using namespace std;
long double a,b;
int main()
{
    cin>>a>>b;
    long double x0=0,x1;
    x1 = x0 - (((b*x0)-a)/b);
    while(abs(x0-x1)>0.000000001){
        x0 = x1;
        x1 = x0 - (((b*x0)-a)/b);
    }
    //cout<<x1;
    printf("%.8lf\n",x1);
}
