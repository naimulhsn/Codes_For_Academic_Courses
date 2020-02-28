#include <graphics.h>
#include <stdlib.h>
#include<bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define debug(x) cerr<<#x<<" is "<<x<< endl;
using namespace std;
pair<int,int> pi;
vector<pair<int,int> > p;

void drawMan(){
    cleardevice();
    line(p[0].ff, p[0].ss, p[1].ff, p[1].ss);
    line(p[0].ff, p[0].ss, p[2].ff, p[2].ss);
    line(p[1].ff, p[1].ss, p[2].ff, p[2].ss);
    line(p[3].ff, p[3].ss, p[4].ff, p[4].ss);
    line(p[4].ff, p[4].ss, p[5].ff, p[5].ss);
    line(p[4].ff, p[4].ss, p[5].ff, p[5].ss);
    line(p[5].ff, p[5].ss, p[6].ff, p[6].ss);
}
void translate(int tx, int ty);
void scale(double sx, double sy);
void shear(char c, double sh);
void rotate(int op,double dgree);
void reflect(int op);
void SpecialRotate(int op,int x, int y,double dgree);

int main()
{
    DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
    //int gd = DETECT, gm;
    //gd*=2; gm*=2;

    initwindow(screenWidth/1.5,screenHeight, "2D transformations primitive Graphics Software Designed by Naim using super advance Technologies :/");
    //initgraph(&gd,&gm,"");

    ///Giving the custom points input for my shape
    /// here i am storing the points in a vector by making them pair
    /// I have used macro(define) for writing some shortcut like pb instead of push_back
    p.pb({200,100});  //0
    p.pb({100,200});
    p.pb({300,200});
    p.pb({120,200});
    p.pb({120,300});
    p.pb({280,300});
    p.pb({280,200});  // 6
    drawMan();

    while(1){
        system("cls"); //clears console texts.

        cout<<" 1. Translate\n";
        cout<<" 2. Scale\n";
        cout<<" 3. Shear\n";
        cout<<" 4. Reflect\n";
        cout<<" 5. Rotate\n";
        cout<<" 6. Rotaion around a point\n";
        cout<<"Please choose and option:\n";
        int op;
        cin>>op;
        if(op==1){
            cout<<"Enter tx, ty : ";
            int tx,ty;
            cin>>tx>>ty;
            translate(tx,ty);
        }
        if(op==2){
            cout<<"Enter sx, sy : ";
            double sx,sy;
            cin>>sx>>sy;
            scale(sx,sy);
        }
        if(op==3){
            cout<<"Enter 'x' for shear in X-axis or 'y' for Y-axis : ";
            char c;
            cin>>c;
            cout<<"Enter sh (small value, eg:0.2 or 0.3) : ";
            double shh;
            cin>>shh;
            shear(c,shh);
        }
        if(op==4){
            cout<<"\nPress\n1.Reflect in X-axis\n";
            cout<<"2.Reflect in Y-axis\n";
            cout<<"Choose : ";
            cin>>op;
            reflect(op);
        }
        if(op==5){
            cout<<"\nPress\n1.for Clockwise\n";
            cout<<"2.for AntiClockwise\n";
            cout<<"Choose : ";
            cin>>op;
            cout<<"Enter degree : ";
            double dgree;
            cin>>dgree;
            if(op==1)rotate(1,dgree);
            else rotate(2,dgree);

        }

        if(op==6){
            cout<<"Enter the rotation center point x,y : ";
            int x,y;
            cin>>x>>y;
            circle(x,y,3);
            cout<<"\nPress\n1.for Clockwise\n";
            cout<<"2.for AntiClockwise\n";
            cout<<"Choose : ";
            cin>>op;
            cout<<"Enter degree : ";
            double dgree;
            cin>>dgree;
            if(op==1)SpecialRotate(1,x,y,dgree);
            else SpecialRotate(2,x,y,dgree);

        }

    }
    getch();
    closegraph();
    return 0;
}


void translate(int tx, int ty)
{
    //string s="Translated to  ( "  + tx + " , " + ty + " )";

    for(int i=0; i<p.size(); i++){
        p[i].ff+=tx;
        p[i].ss+=ty;
    }
    drawMan();
    outtextxy(300, 50, "Translated ");
}
void scale(double sx, double sy)
{
    for(int i=0; i<p.size(); i++){
        p[i].ff*=sx;
        p[i].ss*=sy;
    }
    drawMan();
    outtextxy(300, 50, "Scaled");

}


void shear(char c, double sh)
{

    if(c=='x'){
        for(int i=0; i<p.size(); i++){
            double tmpY = p[i].ss;
            p[i].ff+=(sh *tmpY );

        }
        drawMan();
        outtextxy(300, 50, "Shered to X axis");
    }
    else if(c=='y'){
        for(int i=0; i<p.size(); i++){
            double tmpX = p[i].ff;
            p[i].ss+=(sh*tmpX);
        }
        drawMan();
        outtextxy(300, 50, "Shered to Y axis");
    }
    else{
        drawMan();
        outtextxy(300, 50, "YOU can only press x or y !!! try again :| ");
    }

}

void reflect(int op)
{
    int minx=1000000,miny=100000;
    int minxx=1000000,minyy=100000;
    for(int i=0; i<p.size(); i++)
    {
        minx=min(minx,p[i].ff);
        miny=min(miny,p[i].ss);
        if(op==1)p[i].ff*=-1;
        else p[i].ss*=-1;
        minxx=min(minxx,p[i].ff);
        minyy=min(minyy,p[i].ss);
    }
    if(op==1){
        for(int i=0; i<p.size(); i++){
            p[i].ff+=(minx-minxx);
        }
    }
    else{
        for(int i=0; i<p.size(); i++){
            p[i].ss+=(miny-minyy);
        }
    }
    drawMan();
    outtextxy(300,50,"Reflected and repositioned");
}


void rotate(int op,double dgree)
{
    /// As Y-axis is reversed in the screen it Clockwise becomes AntiClockwise and vice-varsa.
    double rad= dgree*3.14159265359/(double)180;
    if(op==1){

        for(int i=0; i<p.size(); i++){
            double tempX=p[i].ff;
            double tempY=p[i].ss;
            p[i].ff = (tempX * cos(rad)) - (tempY * sin(rad));
            p[i].ss = (tempX * sin(rad)) + (tempY * cos(rad));
        }
        drawMan();
        outtextxy(300,50,"Rotated ClockWise");
    }
    else{
        for(int i=0; i<p.size(); i++){
            double tempX=p[i].ff;
            double tempY=p[i].ss;
            p[i].ff = (tempX * cos(rad)) + (tempY * sin(rad));
            p[i].ss = (tempY * cos(rad)) - (tempX * sin(rad));
        }
        drawMan();
        outtextxy(300,50,"Rotated AntiClockWise");
    }

}


void SpecialRotate(int op,int x, int y,double dgree)
{
    /// As Y-axis is reversed in the screen it Clockwise becomes AntiClockwise and vice-varsa.
    ///the idea is to temporarily transform the center to (0,0) and then add the (x,y) with all points to get actual points around (x,y)
    double rad= dgree*3.14159265359/(double)180;
    if(op==1){
        for(int i=0; i<p.size(); i++){
            double tempX=p[i].ff-x;
            double tempY=p[i].ss-y;
            p[i].ff = (tempX * cos(rad)) - (tempY * sin(rad))+x;
            p[i].ss = (tempX * sin(rad)) + (tempY * cos(rad))+y;
        }
        drawMan();
        outtextxy(300,50,"Rotated ClockWise around the point");
    }
    else{
        for(int i=0; i<p.size(); i++){
            double tempX=p[i].ff-x;
            double tempY=p[i].ss-y;
            p[i].ff = (tempX * cos(rad)) + (tempY * sin(rad))+x;
            p[i].ss = (tempY * cos(rad)) - (tempX * sin(rad))+y;
        }
        drawMan();
        outtextxy(300,50,"Rotated AntiClockWise around the point");
    }
    circle(x,y,3);

}
