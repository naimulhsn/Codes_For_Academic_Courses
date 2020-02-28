#include<bits/stdc++.h>
using namespace std;
int mx;
string s;
int val[100000];
string op[100000];
string expression[100000];
int leftTree[100000];
int rightTree[100000];

void build(int i){
    mx=max(mx,i);
    int len=expression[i].size();
    int dep=0;
    if(len<=1){
        op[i]=expression[i];
        //cout<<expression[i]<<endl;
        return;
    }else{
        for(int j=0; j<len; j++){
            char c=expression[i][j];
            if(c=='(')dep++;
            else if(c==')')dep--;
            else if(dep==0 &&(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')){
                op[i]=c;
                string lft="";
                if(j-0+1>3){
                    for(int k=1; k<j-1; k++)lft+=expression[i][k];
                }else{
                    for(int k=0; k<j; k++)lft+=expression[i][k];
                }
                expression[i*2]=lft;
                string right="";
                if(len-j-1>3){
                    for(int k=j+2; k<len-1; k++)right+=expression[i][k];
                }
                else{
                    for(int k=j+1; k<len; k++)right+=expression[i][k];
                }
                expression[i*2+1]=right;
                build(i*2);
                build(i*2+1);
            }
        }
    }
}
int main()
{
    cin>>s;
    expression[1]=s;
    build(1);
    for(int i=1; i<=mx; i++){
        cout<<i<<"  -> "<<op[i]<<" \n";
    }
}

//((a-b)*c)+(a*(b-c))
