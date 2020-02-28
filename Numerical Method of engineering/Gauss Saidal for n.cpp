/// Naimul Hasan Naim ///
/// ID: 16CSE030   ///
/// Gauss Saidal For n variable ///
#include<bits/stdc++.h>
using namespace std;
#define dbg(x)  cerr<<#x<<" is "<<x<<"\n";
double a[100][100];
long double asum[100];
double b[100][100];
double err[100];
double val[100];
double mx_err(int n) /// This function calculates the max error for all variables.
{
    double mx=0;
    for(int i=1; i<=n; i++)mx=max(mx,err[i]);
    return mx;
}
int main()
{
    int n;
    cin>>n; /// Number of variables

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j]; /// Here i take the inputs
            asum[i] += a[i][j];
        }
        cin>>a[i][n+1];
    }
    int vis[100]={0};
    int big=0;

    for(int i=1; i<=n; i++){ /// Here i checking if it is converging or not
        int f=-1;
        for(int j=1; j<=n; j++){
            if( a[i][j] > (asum[i]-a[i][j]) ) big=1;
            if( a[i][j] >= (asum[i]-a[i][j]) ){
                if(vis[j]){
                    f=-1;
                }
                else{
                    vis[j]=1;
                    f=j;
                }
                break;
            }
        }
        if(f==-1){
            cout<<"Not converging!!!\n";
            return 0;
        }
        else{ /// I rearrange it in an another array b[][]
            for(int j=1; j<=n+1; j++){
                b[f][j]=a[i][j];
            }
        }
    }
    cout<<"after rearranging:\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n+1; j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=1; i<=n; i++)err[i]=100;/// Initial error to 100%
    /// here i will declare the error rate i need .
    double target_err=0.5;

    int loop=0,ff=0;
    while(1){
        loop++;
        if(loop>100000)break;
        for(int i=1; i<=n; i++){
            if(mx_err(n)<target_err){ff=1; break;}/// check if all error is bellow target error
            double tmp =b[i][n+1];
            for(int j=1; j<=n; j++)if(i!=j)tmp+= (b[i][j]*val[j]*-1); ///calculate value
            tmp/=b[i][i];
            err[i]= abs(tmp-val[i])*100/tmp; ///update error for this variable
            val[i]=tmp; /// update value

        }
    }
    cout<<"The Output :\n";   ///Here is the final output.
    for(int i=1; i<=n; i++){
        cout<<"x"<<i<<" = "<<val[i]<<endl;
    }
    return 0;
}

/*

3
4 1 -1 3
2 7 1 19
1 -3 12 31


*/
