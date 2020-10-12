#include<stdio.h>
int main()
{
int x[10];
int queue[10][10],rear[10],front[10],y,num,e,f,i,j,largest,dc,digit;
y=0;
while(y<=9)
{
front[y]=0;
rear[y]=0;
y++;
}

y=0;
while(y<=9)
{
printf("Enter a number:");
scanf("%d",&x[y]);
y++;
}
largest=x[0];
y=1;
while(y<=9) //loop to find out the largest number
{
if(x[y]>largest)
{
largest=x[y];
}
y++;
}

num=largest;
dc=1;          //to count number of digits in the largest number
while(num>9)
{
num=num/10;
dc++;
}

e=10;
f=1;
y=1;
while(y<=dc)
{
  //logic to spread elements in queue on the basis of digit at a position
  i=0;
  while(i<=9)
  {
     num=x[i];
     digit=(num%e)/f; //to get the digit on the ones place when loop is executed for the first time.To et the digit on the Tens place for the second time and so on...

     queue[digit][rear[digit]]=num;
     rear[digit]++;
     i++;
   }

  //logic to spread elements rom queue and put them back in array that is to be sorted
  j=0;
  i=0;
  while(i<=9)
  {
     while(rear[i]!=0)
     {
         num=queue[i][front[i]];
         front[i]++;
         x[j]=num;
         j++;
         if(front[i]==rear[i])
         {
           front[i]=0;
           rear[i]=0;
         }
     }
  i++;
  }
  e=e*10;
  f=f*10;
  y++;
}

y=0;
while(y<=9)
{
printf("%d\n",x[y]);
y++;
}

return 0;
}