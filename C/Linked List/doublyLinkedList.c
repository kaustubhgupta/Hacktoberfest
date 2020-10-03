#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node * prev;
    struct node * next;
    int data;
};

// All Basic Operations of Doubly Linked List
struct node * head;
void insertAtStart();
void insertAtEnd();
void insertAtPos();
void deleteAtStart();
void deleteAtEnd();
void deleteAtPos();
void print();
void search();

void main() {
    int choice = 0;
    while (choice != 13) {
        printf("1.Insert At Start   | 2.Insert At Last   | 3.Insert At Position\n4.Delete From Start | 5.Delete From last | 6.Delete From Postition\n7.Find\n8.Length\n9.Middle\n10.Reverse & Show\n11.Show\n12.Exit\n");
        printf("\nEnter Choice: ");
        scanf("\n%d", & choice);
        switch (choice) {
        case 1:
            insertAtStart();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPos();
            break;
        case 4:
            deleteAtStart();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            deleteAtPos();
            break;
        case 7:
            search();
            break;
        case 8:
            size();
            break;
        case 9:
            middle(head);
            break;
        case 10:
            reverse( & head);
            print();
            break;
        case 11:
            print();
            break;
        case 12:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}

// Respective Function Codes
void insertAtStart() {
    struct node * ptr;
    int item;
    ptr = (struct node * ) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("OVERFLOW");
    } else {
        printf("Enter Item value: ");
        scanf("%d", & item);

        if (head == NULL) {
            ptr -> next = NULL;
            ptr -> prev = NULL;
            ptr -> data = item;
            head = ptr;
        } else {
            ptr -> data = item;
            ptr -> prev = NULL;
            ptr -> next = head;
            head -> prev = ptr;
            head = ptr;
        }
        printf("Node Inserted\n\n");
    }
}

void insertAtEnd() {
    struct node * ptr, * temp;
    int item;
    ptr = (struct node * ) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("OVERFLOW");
    } else {
        printf("Enter value: ");
        scanf("%d", & item);
        ptr -> data = item;
        if (head == NULL) {
            ptr -> next = NULL;
            ptr -> prev = NULL;
            head = ptr;
        } else {
            temp = head;
            while (temp -> next != NULL) {
                temp = temp -> next;
            }
            temp -> next = ptr;
            ptr -> prev = temp;
            ptr -> next = NULL;
        }

    }
    printf("Node Inserted\n\n");
}

void insertAtPos() {
    struct node * ptr, * temp;
    int item, loc, i;
    ptr = (struct node * ) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("OVERFLOW");
    } else {
        temp = head;
        printf("Enter the location: ");
        scanf("%d", & loc);
        for (i = 0; i < loc; i++) {
            temp = temp -> next;
            if (temp == NULL) {
                printf("There are less than %d elements", loc);
                return;
            }
        }
        printf("Enter value: ");
        scanf("%d", & item);
        ptr -> data = item;
        ptr -> next = temp -> next;
        ptr -> prev = temp;
        temp -> next = ptr;
        temp -> next -> prev = ptr;
        printf("Node Inserted\n\n");
    }
}

void deleteAtStart() {
    struct node * ptr;
    if (head == NULL) {
        printf("\n UNDERFLOW");
    } else if (head -> next == NULL) {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    } else {
        ptr = head;
        head = head -> next;
        head -> prev = NULL;
        free(ptr);
        printf("\nnode deleted\n");
    }

}

void deleteAtEnd() {
    struct node * ptr;
    if (head == NULL) {
        printf("\n UNDERFLOW");
    } else if (head -> next == NULL) {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    } else {
        ptr = head;
        if (ptr -> next != NULL) {
            ptr = ptr -> next;
        }
        ptr -> prev -> next = NULL;
        free(ptr);
        printf("\nnode deleted\n");
    }
}

void deleteAtPos() {
    struct node * ptr, * temp;
    int val;
    printf("\n Enter the data after which the node is to be deleted : ");
    scanf("%d", & val);
    ptr = head;
    while (ptr -> data != val)
        ptr = ptr -> next;
    if (ptr -> next == NULL) {
        printf("\nCan't delete\n");
    } else if (ptr -> next -> next == NULL) {
        ptr -> next = NULL;
    } else {
        temp = ptr -> next;
        ptr -> next = temp -> next;
        temp -> next -> prev = ptr;
        free(temp);
        printf("\nnode deleted\n");
    }
}

void search() {
    struct node * ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL) {
        printf("\nEmpty List\n");
    } else {
        printf("\nEnter item which you want to search?\n");
        scanf("%d", & item);
        while (ptr != NULL) {
            if (ptr -> data == item) {
                printf("\nitem found at location %d ", i + 1);
                flag = 0;
                break;
            } else {
                flag = 1;
            }
            i++;
            ptr = ptr -> next;
        }
        if (flag == 1) {
            printf("\nItem not found\n");
        }
    }
}

void size() {
    int size = 0;
    struct node * ptr;
    if (head == NULL) {
        printf("\n Size of list is %d\n", size);
        return;
    }
    ptr = head;
    while (ptr != NULL) {
        ptr = ptr -> next;
        size++;
    }
    printf("\n Size of list is %d\n", size);
}

void middle(struct node * head) {
    struct node * slow_ptr = head;
    struct node * fast_ptr = head;
    if (head != NULL) {
        while (fast_ptr != NULL && fast_ptr -> next != NULL) {
            fast_ptr = fast_ptr -> next -> next;
            slow_ptr = slow_ptr -> next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr -> data);
    }
}

void reverse(struct node ** head_ref) {
    struct node * temp = NULL;
    struct node * current = * head_ref;
    while (current != NULL) {
        temp = current -> prev;
        current -> prev = current -> next;
        current -> next = temp;
        current = current -> prev;
    }
    if (temp != NULL)
        *
        head_ref = temp -> prev;
}

void print() {
    struct node * ptr;
    printf("\nPrinting values: \n");
    ptr = head;
    while (ptr != NULL) {
        printf("%d\n", ptr -> data);
        ptr = ptr -> next;
    }
}
