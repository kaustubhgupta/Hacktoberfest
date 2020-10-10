#include<stdio.h>
#include<conio.h>
void insert();
void del();
void display();
int q[20];
int front=-1,rear=-1;
void main()
{
int ch,n;
do{
printf("\n 1.insert");
printf("\n 2.del");
printf("\n 3.display");
printf("\n 4.exit");
printf("\n enter the choice");
scanf("%d",&ch);
switch(ch)
{
case 1: insert();
break;
case 2: del();
break;
case 3: display();
break;
case 4: exit();
default: printf("invalid choice");
}
}
while(ch!=4)
getch();
}
void insert()
{
int element;
if(rear==20-1)
printf("\n queue full" );
else
{printf("\n enter element");
scanf("%d",&element);
rear=rear+1;
q[rear]=element;
}
if(front==-1)
front=0;
}
void del()
{
int item;
if (front==-1)
{
printf("\n queue is empty");
}
else
{
item=q[front];
front=front+1;
printf("\n deleted item is%d",item);
}
getch();
}
void display()
{
int i;
for(i=front;i<=rear;i++)
{
printf("\n%d", q[i]);
}
}
