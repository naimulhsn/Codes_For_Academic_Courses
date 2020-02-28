#include<bits/stdc++.h>

using namespace std;
const double pi=2* acos(0.0);

long long fa[100];
int main()
{
    double x,res=0.0;
    cin>>x;
    x=(x*pi)/180.0;
    fa[0]=1;
    for(long long i=1;i<=10;i++){
        fa[i]=fa[i-1]*i;
        cout<<fa[i]<<endl;
    }
    double p=x;
    int po=1.0;
    for(int i=1,j=0;i<=10;i+=2,j++){
       res+=po*(x/(double)fa[i]);
       x*=p;
       x*=p;
       po*=(-1.0);
    }
    cout<<res<<endl;

    return 0;
}

