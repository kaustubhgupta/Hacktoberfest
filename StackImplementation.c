/*

data structure  stack
Write a C program to implement the stack which should include following functions:
a. Push() : insert an element into the stack
b. Pop() : return and then delete an element from the stack
c. Display(): display the entire content of the stack
d. Peep(): display the element on the top of the stack
*/
#include<stdio.h>
/* #include<conio.h>
int push(int s[]);
int peek(int s[]);
int pop(int s[]);
int display(int s[]);
*/
int stack[20], top = -1;
void main()
{
    int choice;
    char a;
    printf("CHOOSE FROM FOLLOWING OPTIONS. /n 1.push element to stack. /n 2.peek element from stack. /n 3.pop element from stack. /n 4.display stack.\n ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        push(stack);
        break;
    case 2:
        peek(stack);
        break;
    case 3:
        pop(stack);
        break;
    case 4:
        display(stack);
        break;
    }
}

int pop(int stack[])
{
    int n;
    if (top < 0)
    {
        printf("stack is empty. stack underflow.");
        return 0;
    }
    else
    {
        n = stack[top];
        top--;
        printf("%d", n);
        return 0;
    }
}
int peek(int stack[])
{
    if (top < 0)
    {
        printf("stack is empty.");
    }
    else
    {
        printf("\n %d", stack[top]);
    }
    return 0;
}
int display(int stack[])
{
    int i;
    if (top < 0)
    {
        printf("stack is empty.");
    }
    else
    {
        printf("content of stack are... \n");
        for (i = top; i >= 0; i++)
        {
            printf("%d", stack[i]);
        }
    }
    return 0;
}
int push(int stack[])
{
    int b;

    if (top < 0)
    {
        printf("enter element to push.\n");
        scanf("%d",&b);
        top = top + 1;
        stack[top] = b;
    }
    else
    {
        printf("stackoverflow.");
    }
    return 0;
}