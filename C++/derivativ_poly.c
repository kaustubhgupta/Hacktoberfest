#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
   int coeff;
   int exp;
   struct node* next;
} node;

void get_poly(node** head, node** tail)
{
  node *new;
  int ch;
  do {
     printf("Do you want to add data?(0/1) : ");
     scanf("%d",&ch);
     if(!ch) 
     {
         break;
     }
     new = (node*)malloc(sizeof(node));
     printf("\nEnter coeff : ");
     scanf("%d",&(new->coeff));
     printf("\nEnter exponent : ");
     scanf("%d",&(new->exp));
     new->next= NULL;

     if(*head == NULL)
     {
        new->next = new;
        *head = *tail = new;
     }

     else if(*head == *tail)
     {
        (*head)->next = new;
        new->next = *head;
        *tail = new;
     }

     else
     {  
         (*tail)->next = new;
         new->next = *head;
         *tail = new;
     }
  } while(ch);
}


void display1(node *head, node *tail)  /* FOR circular linked list that is used */ 
{
  while(head->next != tail->next)
  {
     printf("(%d.x^%d)+",head->coeff,head->exp);
     head = head->next; 
  }
  printf("(%d.x^%d)",head->coeff,head->exp);
  printf("\n");
}


void display2(node *head) 
{
  while(head->next != NULL)
  {
     printf("(%d.x^%d)+",head->coeff,head->exp);
     head = head->next; 
  }
  printf("(%d.x^%d)",head->coeff,head->exp);
  printf("\n");
}

void derivative(node *head, node* tail, node* deri)
{
  node* ptr;
  ptr = head;
  while(head->next != ptr)
  {
     deri->coeff = (head->coeff)*(head->exp);
     if(head->exp == 0)
     {
deri->exp = 0;
     }
     else 
        deri->exp = (head->exp)-1;
     deri->next = NULL;
     head = head->next;
     deri->next = (node*)malloc(sizeof(node));
     deri = deri->next;
     deri->next = NULL;
  }
} 
          

int main() 
{
  node *head = NULL;
  node *tail = NULL;
  node *deri = (node*)malloc(sizeof(node));
  
  get_poly(&head,&tail);
  display1(head,tail);

  derivative(head,tail,deri);
  display2(deri);
  return 0;
}
   