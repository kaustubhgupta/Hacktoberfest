#include <stdio.h>
#include <stdlib.h>

/* Functions and variables used */
void push1(int);
void push2(int);
int pop1();
int pop2();
void enqueue();
void dequeue();
void display();
void create();
int stack1[100], stack2[100];
int top1 = -1, top2 = -1;
int count = 0;

/* Main Function */
int main()
{
int choice;
printf("\nQUEUE USING STACKS IMPLEMENTATION\n\n");
printf("\n1.ENQUEUE");
printf("\n2.DEQUEUE");
printf("\n3.DISPLAY");
printf("\n4.EXIT");
printf("\n");
create();
while (1)
{
printf("\nEnter your choice : ");
scanf("%d", &choice);
switch (choice)
{
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
exit(0);
default:
printf("\nInvalid Choice\n");
}}}

/* Function to initialize top of two stacks*/
void create()
{
top1 = top2 = -1;
}

/* Function to push an element to stack */
void push1(int element)
{
stack1[++top1] = element; // Pushing the element to stack1
}

/* Function to pop element from stack */
int pop1()
{
return(stack1[top1--]); // Pop element from stack1
}

/* Function to push an element on to stack */
void push2(int element)
{
stack2[++top2] = element; // Pushing the element to stack2
}

/* Function to pop an element from stack */
int pop2()
{
return(stack2[top2--]); // pop element from stack2
}

/* Function to enqueue an element into the queue using stack */
void enqueue()
{
int data, i;
printf("Enter the data : ");
scanf("%d", &data);
push1(data); // Push data from stack to the queue
count++;
}

/* Function to dequeue an element from the queue using stack */
void dequeue()
{
int i;
for (i = 0;i <= count;i++)
{
push2(pop1()); // Pop elements from stack1 and push them to stack2
}
pop2(); // Pop the element from stack2 which is the element to be dequeued
count--;
for (i = 0;i <= count;i++)
{
push1(pop2()); // Push back all the elements from stack2 to stack1
}}

/*Function to display the elements in the queue*/
void display()
{
int i;
if(top1 == -1)
{
printf("\nEMPTY QUEUE\n");
}
else
{
printf("\nQUEUE ELEMENTS : ");
for (i = 0;i <= top1;i++)
{
printf(" %d ", stack1[i]);
}
printf("\n");
}}
