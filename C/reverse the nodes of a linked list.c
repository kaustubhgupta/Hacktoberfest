#include <stdio.h> 
#include <stdlib.h> 
  
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
static void reverse(struct Node** head) 
{ 
    struct Node* prev = NULL; 
    struct Node* curr = *head; 
    struct Node* next = NULL; 
    while (curr != NULL) { 
        next = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = next; 
    } 
    *head = prev; 
} 
  
void push(struct Node** head, int new_data) 
{ 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    new_node->data = new_data; 
    new_node->next = (*head); 
    (*head) = new_node; 
} 
  
void printList(struct Node* head) 
{ 
    struct Node* temp = head; 
    while (temp != NULL) { 
        printf("%d  ", temp->data); 
        temp = temp->next; 
    } 
} 
  
int main() 
{ 
    struct Node* head = NULL; 
    int n=0,p=0;
    while(1)
    {
    printf("1.Append data to linked list\n2.Reverse the linked list\n3.Display the linked list\nAny other number to exit");
    scanf("%d",&n);
    switch(n)
    {
        case 1 : printf("Enter the data\n");
                 scanf("%d",&p);
                 push(&head,p);
                 break;
        case 2 : reverse(&head);
                 break;
        case 3 : printList(head);
                 break;
        default: exit(0);
    }
    }
} 