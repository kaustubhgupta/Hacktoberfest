/* Aim of this program is to reverse the 
   doubly link list which is inputed from
   the user using a menu driven program */
#include<stdio.h>
#include<stdlib.h>
struct node  //structure of node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node* begin_add(struct node* head,int data)  // function to add node in the begining
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=head;
    return temp;
}
struct node* middle_add(struct node* head,int data,int n) // function to add node in middle i.e. at the specified location n
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    int i=1;
    struct node* p=head;
    while(i<n-1)
    {
        p=p->next;
        i++;
    }
    temp->next=p->next;
    p->next->prev=temp;
    p->next=temp;
    temp->prev=p;
    return head;
}
struct node* end_add(struct node* head,int data) // function to add the node in the end
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    struct node* p=head;
    while(p->next!=NULL)
      p=p->next;
    p->next=temp;
    temp->prev=p;
    return head;
}
void print_link_list(struct node* head) // function to print the whole link list
{
    struct node* temp=head;
    printf("\nData stored in the link list are\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n\n");
}
struct node* reverse(struct node* head) // function to reverse the doubly link list
{
    struct node* temp;
    while(head->next!=NULL)
    {
        temp=head->next;
        head->next=head->prev;
        head->prev=temp;
        head=head->prev;
    }
    head->next=head->prev;
    head->prev=NULL;
    return head;
}
int main()
{
    struct node* head=NULL;
    int c;     // variable for choice 
    int data;  // varianle to temporay store data 
    int n;    // variable for specified location n
    do 
    {
       printf("\n********INSERTING MENU********\n");
       printf("Enter 1 for adding node in the begining\n");
       printf("Enter 2 for adding node in the middele at nth position\n");
       printf("Enter 3 for adding node in the end\n");
       printf("Enter 4 for stop inserting\n");
       scanf("%d",&c);
       if((c==1)||(c==2)||(c==3))
       {
           printf("Enter the new data : ");
           scanf("%d",&data);
       }
       switch(c)
       {
           case 1:head=begin_add(head,data);
                break;
           case 2:
                printf("Enter the location at which you want to enter the data : ");
                scanf("%d",&n);
                head=middle_add(head,data,n);
                break;
            case 3:head=end_add(head,data);
                break;
            case 4:printf("Exiting inserting process\n");
                break;
            default:printf("Please enter a valid number\n");
       }
       print_link_list(head);
    }while(c!=4);

    printf("calling reverse doubly link list function\n");
    head=reverse(head);

    printf("link list after reversal");
    print_link_list(head);
    
    return 0;
}