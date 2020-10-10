#include<stdio.h>
#include<conio.h>
void push()
{
 int a[100],element,n,top=0;
 printf("\n enter n");
 scanf("%d",&n);
 if(top==n)
 printf("\n stack full");
 else
 {
 printf("\n enter element");
 scanf("%d",&element);
 a[top]=element;
 top=top+1;
 }
 }
 void pop()
 {
  int a[100],n,element,top=n-1;
  printf("\n enter n");
  scanf("%d", &n);
  if(top==0)
  printf("\n stack underflow");
  else
  {
   printf("\n enter element");
   scanf("%d", &element);
   element=a[top];
   top=top-1;
   }
   }
   void disp()
   {
    int a[100],n, i;
    printf("\n enter n");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    printf("%d", a[i]);
    }
    void main()
    {
     int a[100],n,element,ch=0;
     printf("\n enter n");
     scanf("%d", &n);
     printf("\n 1. push");
     printf("\n 2.pop");
     printf("\n enter choice");
     scanf("%d", &ch);
     switch(ch)
     { case1: push(); disp();
	      break;
      case 2: pop(); disp();
		break;
     default: printf("\n invalid choice");
     }
     getch();
     }
