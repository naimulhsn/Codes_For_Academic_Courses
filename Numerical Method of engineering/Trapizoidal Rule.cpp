#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x[]={-2,0,2,4,6,8,10};
    double fx[]={35,5,-10,2,5,3,20};
    double ans=0;
    for(int i=0; i<6; i++){
        ans+=(x[i+1]-x[i])*(fx[i]+fx[i+1])/2.0;
    }
    cout<<"I = "<<ans<<endl;
    return 0;
}
