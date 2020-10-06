#include <stdio.h>

typedef struct NODE
{
    int data;
    struct NODE *link;
}

NODE;
NODE *header = NULL;

main()
{
    int choice;
    while (1)
    {
        printf("Press (1) to insert element to queue\n");
        printf("Press (2) to Delete element from queue\n");
        printf("Press (3) to Display all elements of queue\n");
        printf("Press (4) to Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Insertion();
            break;
        case 2:
            Deletion();
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice:\n");
        }
    }
    return (0);
}
int Insertion()
{

    NODE *ptr, *newn;
    newn = (NODE *)malloc(sizeof(NODE));
    printf("Insert a element in queue : ");
    scanf("%d", &newn->data);
    newn->link = NULL;
    if (header == NULL)
    {
        header = newn;
    }
    else
    {
        ptr = header;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = newn;
    }
    printf("insertion Done!!!");
}
int Deletion()
{
    NODE *ptr;
    if (header == NULL)
        printf("Queue Underflow\n");
    else
    {
        ptr = header;
        header = ptr->link;
        free(ptr);
    }
    printf("Deletion Done!!!\n");
}
int Display()
{
    NODE *ptr;
    if (header == NULL)
        printf("Queue is empty\n");
    else
    {
        printf("Queue is : ");
        ptr = header;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
    }
    printf("\n");
}
