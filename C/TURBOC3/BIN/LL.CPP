#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
 int data;
 struct node*next;
 };
 struct node*start=NULL;
 void createll();
 void main()
 {
 int ch;
 do{
 printf("\n 1.create");
 printf("\n 2. exit");
 printf("\n enter ur choice");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: createll();
 break;
 case 2: printf("\n exit");
 break;

 }
 }
 while(ch!=2);
 getch();
 }

 void createll()
 {
 struct node*newnode,*ptr;
 int num;
 printf("\n enter -1 to end");
 printf("\n enter the data");
 scanf("%d", &num) ;
 while(num!=-1)
 {
 newnode=(struct node*)malloc(sizeof(struct node*));
 newnode->data=num;
 if(start==NULL)
 {
 newnode->next=newnode;
 start=newnode;
 }
 else
 {
 ptr=start;
 while(ptr->next!=start)
 ptr=ptr->next;
 ptr->next=newnode;
 newnode->next=start;
 }
 printf("\n enter the data");
 scanf("%d", &num);
 }
 getch();
 }