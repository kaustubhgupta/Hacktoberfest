//Program to insert a node at a given position in the Linked List

#include <stdio.h>
#include <stdlib.h>

// Creating node with data and a pointer
struct node
{
    int data;
    struct node *next;
} * head;
void createList(int n);
void insert_at_given_position(int data, int position);
void displayList();

int main()
{
    int n, data, pos;
    printf("\nEnter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("\nThe List is \n");
    displayList();
    printf("\nEnter the position : ");
    scanf("%d", &pos);
    printf("\nEnter data to insert at position %d of the list: ", pos);
    scanf("%d", &data);
    insert_at_given_position(data, pos);
    printf("\n\nThe List is \n");
    displayList();
    return 0;
}

// A function to create a linked list with the specified number of nodes

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    // When the list is empty
    if (head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("\nEnter the data of node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        temp = head;
        for (i = 2; i <= n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if (newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("\nEnter the data of node %d: ", i);
                scanf("%d", &data);
                newNode->data = data;
                newNode->next = NULL;
                temp->next = newNode;
                temp = temp->next;
            }
        }
    }
}

/* Function for inserting data at given position in the list */

void insert_at_given_position(int data, int position)
{
    int count = 0;
    struct node *newNode, *temp;
    newNode = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the node
    if (newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        temp = head;
        // Traverse to the given position in the list
        while (temp->next != NULL && ((position - 1) != count))
        {
            temp = temp->next;
            count = count + 1;
        }
        //Insert the element at the position
        if ((position - 1) == count)
        {
            newNode->data = data;
            newNode->next = temp->next; //Link the inserted node with the next node
            temp->next = newNode;       // Link the previous node and the inserted node
        }
    }
}

void displayList()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        //Print the list
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}