#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    int lena=a.size();
    int lenb=b.size();
    if(lena!=lenb){
        cout<<"No\n";
        return 0;
    }
    int pre=0;
    for(int i=lena-1; i>=0; i--){
        if((b[i]-a[i])>=pre){
            pre=b[i]-a[i];
        }
        else {
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    return 0;
}


