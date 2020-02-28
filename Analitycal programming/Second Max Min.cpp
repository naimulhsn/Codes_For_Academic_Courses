#include<bits/stdc++.h>
using namespace std;
int a[100000];
int mx,smx;
int mn,smn;
void sMX(int n)
{
    if(n<=0){
        mx=smx=INT_MIN;
        return;
    }
    sMX(n-1);
    if(a[n]>mx)smx=mx,mx=a[n];
    else if(a[n]>smx && a[n]<mx)smx=a[n];
}
void sMN(int n)
{
    if(n<=0){
        mn=smn=INT_MAX;
        return;
    }
    sMN(n-1);
    if(a[n]<mn)smn=mn,mn=a[n];
    else if(a[n]<smn && a[n]>mn)smn=a[n];
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];
    sMX(n);
    cout<<"Second max : "<<smx<<"\n";
    sMN(n);
    cout<<"Second min : "<<smn<<"\n";
}
