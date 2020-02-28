#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int what;
struct NODE{
    int data;
    NODE *left, *right;
    NODE(){
        left=NULL;
        right=NULL;
    }
};
NODE* root=NULL;
void Insert(int x)
{
    NODE* node=new NODE();
    node->data=x;
    if(root==NULL){
        root=node;
    }
    else{
        NODE* tmp=root;
        NODE* parent;
        int f=0;
        while(tmp!=NULL){
            if(x==tmp->data){
                parent=tmp;
                tmp=tmp->left;
                f=1;
            }
            else if(x<tmp->data){
                parent=tmp;
                tmp=tmp->left;
            }
            else {
                parent=tmp;
                tmp=tmp->right;
            }
        }
        if(x<=parent->data)parent->left=node;
        else parent->right=node;
        if(what){
            if(f)cout<<"YES\n";
            else cout<<"NO\n";
        }

    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,x;
        cin>>n>>m;
        int a[n+5];
        what=0;
        root=NULL;
        for(int i=0; i<n; i++){
            cin>>a[i];
            Insert(a[i]);
        }
        what=1;
        for(int i=0; i<m; i++){
            cin>>x;
            Insert(x);
        }
        cout<<"\n\n";
    }
    return 0;
}

