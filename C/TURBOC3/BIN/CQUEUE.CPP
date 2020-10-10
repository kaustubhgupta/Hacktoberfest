#include<stdio.h>
#include<conio.h>
int insert();
int del();
void disp();
int cq[5];
int front=-1,rear=-1;
int ch;
void main()
{
do
{
printf("\n 1.insert()");
printf("\n 2. del()");
printf("\n 3.disp()");
printf("\n 4. exit");
printf("\n enter choice");
scanf("%d",&ch );
switch(ch)
{
case 1: insert();
break;
case 2: del();
break;
case 3: disp();
break;
case 4: printf("\n exit");
break;
default: printf("\n invalid choice");
}
}
while(ch!=4);
getch();
}
int insert()
{
int num;
if(front==(rear+1)%5)
{
printf("\n queue is full");

}
else
{
printf("\n enter element");
scanf("%d",&num);
if(front==-1)
front=rear=0;
else
rear=(rear+1)%5;
cq[rear]=num;
}
return 0;
}
int del()
{
    int num;
if (front==-1)
{
printf("\n empty");
return 0;
}
else
{
num=cq[front];
printf("\n deleted element is %d", cq[front]);
if(front==rear)
front=rear-1;
else
front =(front+1)%5;
}
return 0;
}
void disp()
{
int i;
if (front==-1)
{
printf("\n empty");

}
else
{
 printf ("\n status of queue is %d", cq[i]) ;
 for(i=front;i<=rear;i++)
 {
 printf("\n %d",cq[i]);
 getch();
 }
 }
 }