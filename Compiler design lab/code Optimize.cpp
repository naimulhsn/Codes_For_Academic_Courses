#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s[50];
    map<char, string> ex,excnt,value, variable,optimized;
    map<string,int>check;
    for(int i=0; i<5 ;i++){
        cin>>s[i];
        string right="";
        for(int k=2; k<s[i].size(); k++)right+=s[i][k];
        if(check[right]==0){
            check[right]=1;
            char left=s[i][0];
            ex[left]=right;
        }
    }

    cout<<"\nSubexpression Eliminated :\n";
    for (auto it = ex.rbegin(); it != ex.rend(); it++) {
        cout << it->first<< " = "<< it->second<< endl;
    }
    cout<<endl;
    map<char,int> need;
    need['e']=1;
    for (auto it = ex.rbegin(); it != ex.rend(); it++) {
        if(need[it->first]==1){
            string s=it->second;
            if(s.size()==1){
                char c=s[0];
                if(ex[c]!=""){
                    optimized[it->first]=ex[c];
                    string ss=ex[c];
                    if(ss.size()>2){
                        need[ss[0]]=1;
                        need[ss[2]]=1;
                    }else{
                        optimized[it->first]=ex[ss[0]];
                    }
                }
                else optimized[it->first]=it->second;
            }
        }
    }
    cout<<"\nDead code Eliminated :\n";
    for(auto x: optimized){
        cout << x.first<< " = "<< x.second<< endl;
    }

}

