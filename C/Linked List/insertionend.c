//Program to insert a node at the end of the Linked List

#include <stdio.h>
#include <stdlib.h>

//Creating node with data and a pointer

struct node
{
    int data;
    struct node *next;
} * head;
void createList(int n);
void insert_node_end(int data);
void displayList();

int main()
{
    int n, data;
    printf("\nEnter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("\nThe List is \n");
    displayList();
    printf("\nEnter data to insert at end of the list: ");
    scanf("%d", &data);
    insert_node_end(data);
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

/* Function for inserting data at the end of the list */

void insert_node_end(int data)
{
    struct node *newNode, *temp;
    newNode = (struct node *)malloc(sizeof(struct node)); //Allocating memory to the node
    if (newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Assigning data to the newNode
        newNode->next = NULL;
        temp = head;
        // Traverse to the end of the list
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode; // newNode is made as the last node
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