//Program to insert a node at the beginning of the Linked List

#include <stdio.h>
#include <stdlib.h>

// Creating node with data and a pointer
struct node
{
    int data;
    struct node *next;
} * head;
void createList(int n);
void insert_at_beginning(int data);
void displayList();

int main()
{
    int n, data;
    printf("\nEnter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("\nThe List is \n");
    displayList();
    printf("\nEnter data to insert at beginning of the list: ");
    scanf("%d", &data);
    insert_at_beginning(data);
    printf("\n\nThe List is \n");
    displayList();
    return 0;
}

/* A function to create a linked list with the specified number of nodes */

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

/* Function for inserting data at the beginning of the list */

void insert_at_beginning(int data_value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node)); // Allocating memory to the node
    temp->data = data_value;                                        // Assigning the given data to the newNode
    temp->next = head;                                              //newNode is added
    head = temp;                                                    //newNode is made as the head node
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
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}