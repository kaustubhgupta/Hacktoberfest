#include<stdio.h>
#include<conio.h>
int main()
{
char operator;
float num1,num2;
printf("SIMPLE CALCULATOR");
printf("WELCOME!!!");
printf("Enter two numbers as operand\n");
scanf("%d %d", &num1,&num2);
printf("Enter the operator(+,-,*,/)\n");
scanf("%*c%c",&operator);
switch(operator)
{
case '+':
printf("%.2f + %.2f = %.2f",num1,num2,num1+num2);
break;
case '-':
printf("%.2f - %.2f = %.2f",num1,num2,num1-num2);
break;
case '+':
printf("%.2f * %.2f = %.2f",num1,num2,num1*num2);
break;
case '+':
printf("%.2f / %.2f = %.2f",num1,num2,num1/num2);
break;
default:
printf("unsupported operation ERROR!!!");
}
getch();
}

