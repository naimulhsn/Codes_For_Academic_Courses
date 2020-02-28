#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,s2;
    int op,address;
    map<string, int> mp;
    vector<string> v;
    vector<string>::iterator it;
    while(1){
        cout<<"Choose an option from here : \n";
        cout<<"                    1. Insert \n";
        cout<<"                    2. Display \n";
        cout<<"                    3. Delete \n";
        cout<<"                    4. Search \n";
        cout<<"                    5. Modify \n";
        cout<<"                    6. End \n your choice -> ";

        cin>>op;

        if(op==1){
            cin>>s>>address;
            mp[s]=address;
            v.push_back(s);
        }
        else if(op==2){
            cout<<"-----------------\nLevel |  Address \n-----------------\n";
            for(int i=0; i<v.size(); i++){
                cout<<"  "<<v[i]<<"   |   "<<mp[v[i]]<<endl;
            }
            cout<<"-----------------\n\n\n";
        }
        else if(op==3){
            cin>>s;
            mp.erase(s);
            for(it=v.begin(); it!=v.end(); it++){
                if((*it)==s){
                    v.erase(it);
                    break;
                }
            }
        }
        else if(op==4){
            cin>>s;
            cout<<s<<" : "<<mp[s]<<endl;
        }
        else if(op==5){
            cin>>s;
            mp.erase(s);
            cin>>s2>>address;
            mp[s2]=address;
            for(int i=0; i<v.size(); i++){
                if(v[i]==s){
                    v[i]=s2;
                    break;
                }
            }
        }
        else if(op==6){
            cout<<"THE END\n\n\n\n";
            break;
        }
        else cout<<"invalid option \n\n\n\n";

    }
}
