#include<bits/stdc++.h>
using namespace std;
#define dbg(x)     cerr << #x << " is " << x << endl;
int main()
{
    int a[3][4]={0};
    int sm[3]={0};
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cin>>a[i][j];
            if(j!=3)sm[i]+=a[i][j];
        }
    }
    int f=0,mrk[3]={0};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if( a[i][j] > (sm[i]-a[i][j]) ){
                f=1;
                mrk[j]=1;
            }
            else if( a[i][j] == (sm[i]-a[i][j]) ){
                mrk[j]=1;
            }
        }
    }
    dbg(f);
    dbg(mrk[0]);
    dbg(mrk[1]);
    dbg(mrk[2]);
    if( !(mrk[0]==1 && mrk[1]==1 && mrk[2]==1) )cout<<"No convergence found\n";

    for(int i=0; i<3; i++){
        if( a[i][i]<(sm[i]-a[i][i]) ){
            for(int j=0; j<3; j++){
                if( a[j][i]>=(sm[j]-a[j][i]) ){
                    for(int k=0; k<4; k++){
                        swap(a[i][k],a[j][k]);
                    }
                    swap(sm[i],sm[j]);
                }
            }
        }
    }
    for(int i=0; i<3; i++){
        cout<<" | ";
        for(int j=0; j<4; j++){
            cout<<a[i][j]<<" | ";
        }
    cout<<"\n";
    }

}
/*
1 2 3 610
3 1 1 510
3 5 2 960


*/
