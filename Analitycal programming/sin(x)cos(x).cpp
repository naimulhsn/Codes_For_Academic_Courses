#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x;
    cin>>x;
    x=x*3.14159/180;
    double currSin=x,currCos=1,sinx=x,cosx=1;
    int num=1;
    for(int i=1; i<=30; i++){
        currSin=((-currSin*x*x)/(double)((num+1)*(num+2)));
        currCos=((-currCos*x*x)/(double)(num*(num+1)));
        num+=2;
        sinx+=currSin;
        cosx+=currCos;

    //cout<<"Sin(x) : "<<sinx;
    //cout<<"        Cos(x) : "<<cosx<<endl;

    }

    cout<<"Values from Maclorens series :\n    Sin(x) : "<<sinx<<endl;
    cout<<"    Cos(x) : "<<cosx<<endl;
    cout<<"\n\nValues Using built in function:\n   Sin(x) : "<<sin(x)<<endl;
    cout<<"    Cos(x) : "<<cos(x)<<endl;
    return 0;
}
