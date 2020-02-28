#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s[50];
    map<string, string> value, variable;
    map<string,int>check;
    for(int i=0; i<5 ;i++){
        cin>>s[i];
    }
    for(int i=0; i<5; i++){
        string e="";
        for(int j=2; j<s[i].size(); j++){
            e+=s[i][j];
        }
        if(check[e]==1){
            value[s[i][0]]=variable[e];
        }else{
            value[s[i][0]]=e;
            check[e]=1;
            variable[e]=s[i][0];
        }
    }
    for(auto x: value){
        cout<<x.first()<<" = "<<x.second<<"\n";
    }

}
