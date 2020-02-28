#include<bits/stdc++.h>
using namespace std;
int chk(string s, int b, int e)
{
    while(b<e){
        if(s[b]!=s[e])
            return 0;
        b++; e--;
    }
    return 1;
}
int main()
{
    string s;
    cin>>s;
    int len=s.size();
    int lenn=s.size();
    while(len--){
        for(int i=0; i+len<lenn; i++)
        {
            if(chk(s,i,i+len)){
                for(int j=i; j<=i+len; j++)cout<<s[j];
                return 0;
            }
        }
    }
    return 0;

}
