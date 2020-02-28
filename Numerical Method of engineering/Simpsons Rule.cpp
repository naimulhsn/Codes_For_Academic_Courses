#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x[]={-2,0,2,4,6,8,10};
    double fx[]={35,5,-10,2,5,3,20};
    double ans=0;
    for(int i=2; i<7; i+=2){
        ans+= ((x[i]-x[i-2])/6.0)*(fx[i]+ (4*fx[i-1]) +fx[i-2]);
    }
    cout<<"For Simpsons 1/3 Rule, I = "<<ans<<endl;
    return 0;
}

