#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int len=s.size();
    int a[150]={0};
    for(int i=0; i<len; i++){
        a[s[i]]++;
    }
    for(int i='a'; i<='z'; i++)if(a[i]==1)cout<<(char)i<<"  ";
    for(int i='A'; i<='B'; i++)if(a[i]==1)cout<<(char)i<<"  ";
    return 0;
}

