#include<stdio.h>
int main()
{
int x[10],y,diff,j,num,lb,ub;
lb=0;
ub=9;
y=0;
while(y<=ub)
{
printf("Enter a number:");
scanf("%d",&x[y]);
y++;
}

diff=(ub-lb+1)/2;
while(diff>lb)
{
y=diff+lb;
while(y<=ub)
{
num=x[y];
j=y-diff;
while(j>=lb && x[j]>num)
{
x[j+diff]=x[j];
j=j-diff;
}
j=j+diff;
x[j]=num;
y=y+diff;
}
diff=diff/2;
}
y=0;
while(y<=9)
{
printf("%d\n",x[y]);
y++;
}
return 0;
}