#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int data;
node*next;
};
 node*start=NULL;
 void push()
 {
  node*temp;
  temp=(node*)malloc(sizeof(node));
  scanf("%d",&temp->data);
  temp->next=start;
  start=temp;
  }
  void pop()
  {
   node*temp;
   temp=start;
   start=start->next;
   delete temp;
   }
   void disp()
   {
    node*temp;
    temp=start;
    if(temp==NULL)
    printf("\n empty");
    else
    {
     while(temp!=NULL)
     {
      printf("%d", temp->data);
      temp=temp->next;
      }
      printf("\n end of list");
      }
      }
      void main()
      {
       node n;
       int ch=0;
       printf("\n 1.push ");
       printf("\n 2. pop");
       printf("\n enter choice");
       scanf("%d",&ch);
       switch(ch)
       {
	case 1: push(); disp();
		break;
       case 2: pop(); disp();
	       break;
	default:printf("\n invalid choice");
	}
	getch();
	}