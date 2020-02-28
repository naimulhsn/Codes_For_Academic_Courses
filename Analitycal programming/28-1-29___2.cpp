#include<bits/stdc++.h>
using namespace std;
long long toNum(string s){
    long long num=0;
    for(int i=0; i<s.size(); i++){
        num=num*10+(s[i]-'0');
    }
    return num;
}
string toStr(long long x){
    string xx="";
    int i=0;
    while(x){
        xx+=(char)((x%10)+48);
        x/=10;
    }
    return xx;
}
int main()
{
    string s,asc,dsc;
    long long n,a,b,x;
    cin>>s;
    map<string,int> mp;
    mp[s]=1;
    vector<string> v;
    v.push_back(s);
    while(1){
        int len=s.size();
        sort(s.begin(),s.end());
        asc=s;
        reverse(s.begin(),s.end());
        dsc=s;
        a=toNum(dsc);
        b=toNum(asc);
        //cout<<"a: "<<a<<"\n";
        //cout<<"b: "<<b<<"\n";
        x=a-b;
        //cout<<"x: "<<x<<"\n";
        s=toStr(x);
        //cout<<s<<"\n";
        if(mp[s]!=1){
            v.push_back(s);
            mp[s]=1;
        }
        else break;
    }
    for(int i=v.size()-1; i>=0; i--){
        cout<<v[i]<<" - ";
    }
    cout<<"\n\n Chain size: "<<v.size()<<"\n";
    return 0;


}
