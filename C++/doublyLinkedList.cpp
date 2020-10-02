#include <stdio.h>
#include <stdlib.h>
struct Node // structure for linked list
{
    struct Node *prev; // pointer to previous node
    int data; // data in linkedlist
    struct Node *next; // pointer to next node
} *first = NULL;

void Create(int A[], int n) // function for creating the Linked List
{
    struct Node *t, *last;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node)); // initializing the first pointer using malloc function
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++) 
    {
        t = (struct Node *)malloc(sizeof(struct Node)); // allocating memory to a temp variable
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p) // function for displaying the elememnts of a linked list
{
    while (p) // loop runs while the pointer does'nt reach the end of the linked list
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n"); // to seaperate each element of a linkedlist in a ne wline
}

int Length(struct Node *p) // function for finding the length of a linked list
{
    // logic for finding the length
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Insert(struct Node *p, int index, int x) // function for creatintg a linked list
{
    struct Node *t;
    int i;

    if (index < 0 || index > Length(p))
        return;
    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;

        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        t->prev = p;
        if (p->next) // if next node is present
            p->next->prev = t;
        p->next = t;
    }
}

int Delete(struct Node *p, int index) // function for deleting the node in a linked list
{
    struct Node *q;
    int x = -1, i;
    if (index < 1 || index > Length(p))
        return -1;
    if (index == 1)
    {
        first = first->next;
        if (first)
            first->prev = NULL;
        x = p->data;
        free(p);
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}

void Reverse(struct Node *p) // function for reversing the elements of doubly linked list
{
    struct Node *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        p = p->prev;

        if (p != NULL && p->next == NULL)
            first = p;
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    Create(A, 5);
    Reverse(first);
    Display(first);

    return 0;
}

// Ouput : 50 40 30 20 10
