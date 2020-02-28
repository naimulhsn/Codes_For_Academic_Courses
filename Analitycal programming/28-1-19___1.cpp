#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int len=s.size();
        int b,e,ans=0;
        map<string,int> mp;
        for(int i=0; i<len; i++){
            for(int j=i; j<len; j++){
                b=i; e=j;
                while(b<=e && s[b]==s[e]){
                    b++; e--;
                }
                if(b>e){
                    string tmp="";
                    for(int k=i; k<=j;k++ ){
                        tmp+=s[i];
                    }
                    if(mp[tmp]!=1){
                        mp[tmp]=1;
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<"\n\n";
    }
    return 0;
}
