#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+5],b[n+m+5];
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<m; i++)cin>>b[i];

    int i=n+m-1,j=n-1,k=m-1;
    while(j>=0 && k>=0){
        if(a[j]>b[k]){
            b[i--]=a[j--];
        }
        else{
            b[i--]=b[k--];
        }
    }
    while(j>=0){
        b[i--]=a[j--];
    }
    while(k>=0){
        b[i--]=b[k--];
    }
    for(int i=0; i<n+m; i++)cout<<b[i]<<" ";
}
