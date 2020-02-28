#include <graphics.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
   int gd = DETECT, gm;
   int x = 320, y = 240, radius;

   initgraph(&gd, &gm, "");
    int a=1;
    for(int i=0; i<300; i+=a){
        cleardevice();
        for ( radius = 25; radius <= 100 ; radius = radius + 20)
          circle(x+i, y+i, radius);
          for(int j=0; j<1000; j++);
          if(i>200)a*=-1;
          if(i<-200)a*=-1;

    }

   getch();
   closegraph();
   return 0;
}

