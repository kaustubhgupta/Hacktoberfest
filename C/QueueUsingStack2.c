#include <stdio.h> 
#define MAX 10      // SETTING MAX SIZE OF ARRAY TO 10.
void Push();       // DEFINING ALL THE FUNCTIONS USED HERE.
void Pop();
void Display();
int queue[MAX]; //THIS ARRAY WILL WORK AS QUEUE AND WILL STORE REVERSE OF STACK ARRAY TO FOLLOW FIFO.
int stack[MAX]; //THIS ARRAY WILL WORK AS STACK AND DURING DELITION AND DISPLAY WILL POP IN QUEUE ARRAY IN LIFO.
int TopStack = -1;
int TopQueue = -1;
main()
{
    int choice; // USING A SWITCH CASE TO ASK FOR INSTRUCTIONS FROM USER.
    while (1)
    {
        printf("\nPress (1) to insert element to queue\n");
        printf("Press (2) to Delete element from queue\n");
        printf("Press (3) to Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n");
            Push();
            break;
        case 2:
            printf("\n");
            Pop();
            break;
        case 3:
            exit(0);
        default:
            printf("\n");
            printf("Invalid choice:\n");
        }
    }
}

void Push() /* A FUNCTION TO INSERT NEW ELEMENT AT TOP OF Stack[ARRAY] IN AND CALLS Display()
            AFTER CONVERTING POPING STACK TO QUEUE IN FIFO TO DISPLAY QUEUE IN LIFO.*/
{
    int New;
    if (TopStack == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        printf("Enter element for insertion = ");
        scanf("%d", &New);
        TopStack++;
        stack[TopStack] = New;
    }
    StackToQueue();
    Display();
    QueueToStack();
}
void Pop() /* FUNCTION TO DELETE ELEMENT FROM THE QUEUE BY FIFO AFTER REVERSING THE STACK TO QUEUE.*/
{
    if (TopStack == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    else
    {
        StackToQueue();
        printf("Element deleted from queue is : %d\n", queue[TopQueue]);
        TopQueue--;
    }
    Display();
    QueueToStack();
}

void Display() // FUNCTION TO DISPLAY THE WHOLE QUEUE IN END OF INSERTION() OR DELETION().
{
    if (TopQueue == -1)
        printf("Queue is empty\n");
    else
    {
        printf("Present Queue is : ");
        for (int i = TopQueue; i >= 0; i--)
            printf(" %d <-- ", queue[i]);
        printf("\n");
    }
}

void StackToQueue() //FUNCTION TO POP stack[] to queue[] IN LIFO ORDER.
{
    while (TopStack >= 0)
    {
        TopQueue++;
        queue[TopQueue] = stack[TopStack];
        TopStack--;
    }
}
void QueueToStack() //FUNCTION TO POP queue[] TO stack[] IN LIFO ORDER.
{
    while (TopQueue >= 0)
    {
        TopStack++;
        stack[TopStack] = queue[TopQueue];
        TopQueue--;
    }
}
