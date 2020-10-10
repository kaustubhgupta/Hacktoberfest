#include<stdio.h>
#include<conio.h>
int stk[10];
int top=-1;
int pop();
void push();
int main()
{
int val,n,i,arr[10];
printf("\n enter size of array");
scanf("%d",&n);
printf("\n enter elements");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);

for(i=0;i<n;i++)
{
 val=pop();
 arr[i]=val;
 }
 printf("\n reversed list ");
 for (i=0;i<n;i++)
 printf("%d",arr[i]);
 getch();
 return 0;
 }
 void push()
 { int val;
  stk[++top]=val;
 }
 int pop()
 {
 return(stk[top--]);
 }