#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
 struct node*next;
 int data;
 struct node*prev;
 };
 struct node*start=NULL;
 void createll();
 void disp();
 void main()
 { int ch;
 do
 {
 printf("\n 1. create");
 printf("\n 2. display");
 printf("\n 3. exit");
 printf("\n enter ur choice");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:createll();
 break;
 case 2:disp();
 break;
 case 3:printf("\n exit");
 break;
 }
 }
 while(ch!=3);
 getch();
 }
 void createll()
 {
 struct node*newnode,*ptr;
 int num;
 printf("\n enter -1 to end");
 printf("\n enter the data");
 scanf("%d", &num);
 while(num!=-1)
 {
 if(start==NULL)
 {
 newnode=(struct node*)malloc(sizeof (struct node));
 newnode->prev=NULL;
 newnode->data=num;
 newnode->next=NULL;
 start=newnode;
 }
 else
 {
 ptr=start;
 newnode=(struct node*)malloc(sizeof (struct node));
 newnode->data=num;
 while(ptr->next!=NULL)
 ptr=ptr->next;
 ptr->next=newnode;
 newnode->prev=ptr;
 newnode->next=NULL;
 }
 printf("\n enter data");
 scanf("%d", &num);

 }
 getch();
 }
 void disp()
 {
 struct node*ptr;
 ptr=start;
 while(ptr!=NULL)
 {
 printf("\t %d", ptr->data) ;
 ptr=ptr->next;
 }
 getch();
 }