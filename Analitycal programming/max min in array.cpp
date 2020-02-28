#include<bits/stdc++.h>
using namespace std;
int a[100000];
int MX(int n)
{
    if(n<=0)return INT_MIN;
    return max(a[n],MX(n-1));
}
int MN(int n)
{
    if(n<=0)return INT_MAX;
    return min(a[n],MN(n-1));
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    cout<<"Max : "<<MX(n)<<"\n";
    cout<<"Min : "<<MN(n)<<"\n";
    return 0;
}
