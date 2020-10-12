#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node{
    int val;
    struct node * next;
};

// Helper functions
struct node* createNode(int value){
    struct node* ptr;
    ptr = (struct node *) malloc(sizeof(struct node));
    ptr -> val = value;
    ptr -> next = NULL;

    return ptr;
}

int GetNth(struct node* current, int index){
    while (current != NULL){
        if (index == 0){
            return current->val;
        }
        current = current->next;
        index--;
    }
    assert(0);
}

void printList(struct node *start){
    struct node * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->val);
        printf(" ");
        ptr = ptr->next;
    }
    printf("\n");
}

void freeListMemory(struct node* start){
    struct node* ptr = start;
    struct node* tmp;

    while (ptr != NULL){
        tmp = ptr -> next;
        free(ptr);
        ptr = tmp;
    }
}

// Insertion functions:

/*  Given an int and a reference to the head pointer (i.e. a struct
    node** pointer to the head pointer), add a new node at the head of the
    list and set its .next to point to the current head, 
    and finally change the head (of the whole list) to point to the new node.
*/
struct node* push(struct node** headRef, int data){
    struct node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void InsertAtHeadTest(){
    struct node* head = NULL; // start with the empty list
    push(&head, 7);
    push(&head, 5);
    push(&head, 6);

    printList(head);
    assert (head->val == 6);
    freeListMemory(head);
}

struct node * appendNodeAtTail(struct node** headRef, int data){
    struct node * current = *headRef;

    // special case for the empty list
    if (current == NULL) {
        push(headRef, data);
    } else {
        // Locate the last node
        while (current->next != NULL) {
            current = current->next;
        }
        push(&(current->next),data);
    }
    return (current->next);
}

void InsertAtEndTest(){
    struct node* head = NULL;
    struct node* tail;
    push(&head, 5);
    appendNodeAtTail(&head, 7);
    appendNodeAtTail(&head, 6);
    tail = appendNodeAtTail(&head, 200);

    printList(head);

    assert(tail->val == 200);
    freeListMemory(head);
}

/*
*   Insert value at nth position in the linked list
*/
void InsertNth(struct node** headRef, int index, int value){
    if (index == 0) push(headRef, value);
    else{
        struct node* current = *headRef;

        // Find node behind target position
        for (int i = 0; i < index - 1; i++){
            assert(current != NULL); // avoid overshooting index
            current = current->next;
        }
        assert(current!=NULL); // check for index = (lastIndex+2)

        // set .next of new node to current.next(index+1) and set current.next to new node;
        push(&(current->next), value);
    }   
}

void InsertNthTest() {
    struct node* head = NULL; // start with the empty list
    InsertNth(&head, 0, 13); // build {13)
    InsertNth(&head, 1, 42); // build {13, 42}
    InsertNth(&head, 1, 5); // build {13, 5, 42}
    
    printList(head);

    int find = GetNth(head, 2);
    assert(find == 42);
    freeListMemory(head);
}

int main (void){
    InsertAtHeadTest();
    InsertAtEndTest();
    InsertNthTest();
    return 0;
}