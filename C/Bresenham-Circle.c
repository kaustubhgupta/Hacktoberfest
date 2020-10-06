#include <stdio.h>
#include <conio.h>
#include <graphics.h>

    void Circle(int xc,int yc,int x,int y)
   {
    putpixel(x+xc,y+yc,RED);
    putpixel(x+xc,-y+yc,BLUE);
    putpixel(-x+xc,-y+yc,GREEN);
    putpixel(-x+xc,y+yc,RED);
    putpixel(y+xc,x+yc,BLUE);
    putpixel(y+xc,-x+yc,GREEN);
    putpixel(-y+xc,-x+yc,RED);
    putpixel(-y+xc,x+yc,BLUE);
   }

    void BresenhamCircle(int xc,int yc,int r)
   {
    int x=0,y=r,d=3-(2*r);
    Circle(xc,yc,x,y);

    while(x<=y)
     {
      if(d<=0)
	     {
	d=d+(4*x)+6;
      }
     else
      {
	d=d+(4*x)-(4*y)+10;
	y=y-1;
      }
       x=x+1;
       Circle(xc,yc,x,y);
       delay(10);
      }
    }

    int main()
   {

    int xc,yc,r,gd = DETECT, gm;

     initgraph(&gd,&gm, "C:\\TURBOC3\\BGI");

       printf("Enter the value of xc and yc :");
       scanf("%d%d",&xc,&yc);
       printf("Enter the value of radius  :");
       scanf("%d",&r);
       BresenhamCircle(xc,yc,r);
       BresenhamCircle(xc+r,yc,r);
       BresenhamCircle(xc-r,yc,r);
       BresenhamCircle(xc,yc+r,r);
       BresenhamCircle(xc,yc-r,r);
     getch();
     closegraph();
     return 0;
    }
