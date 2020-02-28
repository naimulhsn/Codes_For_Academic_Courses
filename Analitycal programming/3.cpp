#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,pre;
    cin>>n>>x;
    cin>>pre;
    for(int i=0; i<n; i++){
        cin>>x;
        if(pre<x-1){
            cout<<x-1;
            return 0;
        }
        pre=x;
    }
    cout<<pre+1;
    return 0;
}

