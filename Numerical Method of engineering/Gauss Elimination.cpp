#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a[4][5]={0};
    for(int i=1; i<=3; i++){
        cout<<"Enter coefficients of row "<<i<<" -> [a,b,c,d] : ";
        for(int j=1; j<=4; j++){
            cin>>a[i][j];
        }
        cout<<endl;
    }
    double c=a[1][1];
    for(int i=1; i<=3; i++){
        for(int j=1; j<=4; j++){
            a[i][j]/=c;
        }
        for(int k=i+1; k<=3; k++ ){

        }
    }
}
