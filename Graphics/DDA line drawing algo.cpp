#include<bits/stdc++.h>
#include<stdio.h>
#include<graphics.h>
int col;
int abs (int n)
{
    return ( (n>0) ? n : ( n * (-1)));
}

void DDA(int X0, int Y0, int X1, int Y1)
{
    int dx = X1 - X0;
    int dy = Y1 - Y0;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;

    float X = X0;
    float Y = Y0;
    if(col>9)col=1;
    for (int i = 0; i <= steps; i++)
    {
        putpixel (X,Y,col);
        //putpixel (X,Y+1,col);
        //putpixel (X,Y-1,col);
        X += Xinc;
        Y += Yinc;
        //delay(2);

    }
    col++;
}

int main()
{
    int gd = DETECT, gm;
    initgraph (&gd, &gm, "");
    int x0,x1,y0,y1;
    col=1;
    while(0){
        std::cout<<"\t\t\t\t\t\t\t\tEnter two points, x0, y0, x1, y1 : ";
        std::cin>>x0>>y0>>x1>>y1;
        DDA(x0, y0, x1, y1);
    }
    for(int i=0; i<500; i++){
        int rem=501;
        x0=rand()%rem;
        x1=rand()%rem;
        y0=rand()%rem;
        y1=rand()%rem;
        DDA(x0, y0, x1, y1);
    }
    //int X0 = 2, Y0 = 2, X1 = 14, Y1 = 16;

    getchar();
    return 0;
}
/*  Points:::



5 50 400 150
65 5 150 500
200 300 2 0
65 629 25 829
98 321 4 652
121 25 454 234
549 532 235 352
58 21 652 65
206 326 21 32
54 32 659 1226


*/
