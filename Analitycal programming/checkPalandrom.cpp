#include<bits/stdc++.h>
using namespace std;
int recusrion(string s, int pos,int len)
{
    if(pos>=len/2)return 1;
    if(s[pos]!=s[len-1-pos])return 0;
    return recusrion(s,pos+1,len);
}
int main()
{
    string s;
    cin>>s;
    int res=recusrion(s,0,s.size());
    if(res)cout<<"Its a Palindrome\n";
    else cout<<"It's not a Palindrome\n";
    return 0;
}
