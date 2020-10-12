# include<stdio.h>

int push(int stack[] , int element, int top , int MAX)
{
	if(top == MAX-1)
	{
		printf("Overflow\n");
		return top;
	}
	else
	{
		top = top +1;
		stack[top] = element;
		return top;

	}
}

void pop(int top)
{
	if(top == -1)
	{
		printf("Underflow\n");
		return;
	}
	top = top - 1;
	return;
}

void display(int stack[],int top)
{
	printf("Elements of stack are - \n");
	int a = top;
	while(a+1)
	{
		printf("%d ",stack[a]);
		a = a-1;
	}
	printf("\n");
}
int factorial(int stack[],int top)
{
	int fact=1,a ; 
	a = top;
	while(a+1)
	{
		fact*=stack[a];
		a = a-1;
	}
	return fact;
}

int main()
{
	int stack[100],top = -1,MAX,num,i,fact;
	printf("Enter the number whose factorial is to be printed\n");
	scanf("%d",&num);
	MAX = num;
	for(i=1;i<=num;i++)
	{
	top = push(stack,i,top,MAX);
    }
    display(stack,top);
    fact = factorial(stack , top);
    printf("Factorial of the entered number is - %d",fact);
    return 0;
}
