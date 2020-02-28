#include<bits/stdc++.h>
#include<graphics.h>
int color;
void bresenham(int x1, int y1, int x2, int y2)
{
    if(color>12)color=1;
   int m_new = 2 * (y2 - y1);
   int slope_error_new = m_new - (x2 - x1);
   for (int x = x1, y = y1; x <= x2; x++)
   {
        putpixel(x,y,color);
        putpixel(x,y+1,color);
        putpixel(x,y+2,color);
      slope_error_new += m_new;

      if (slope_error_new >= 0)
      {
         y++;
         slope_error_new  -= 2 * (x2 - x1);
      }
   }
   color++;
   delay(200);
}

// driver function
int main()
{
    int gd=DETECT,gm;
	initgraph(&gd, &gm, "");
  int x1, y1, x0, y0;
  color=1;
  for(int i=0; i<19; i++){
    int rem=300;
    x1=rand()%rem;
    y0=rand()%rem;
    x0=rand()%rem;
    y1=rand()%rem;
    bresenham(x0, y0, x1, y1);
  }
  getchar();
  getchar();

  return 0;
}
