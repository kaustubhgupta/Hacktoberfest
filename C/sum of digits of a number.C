## This is a program to show sum of digits
#include<stdio.h>
int main()
{
  int num1,num2,sum=0;
  printf("Enter a no:");
  scanf("%d", &num1);
  printf("Enter another no:");
  scanf("%d", &num2);
  sum=num1+num2;
  printf("Sum of digits is %d",sum);
  return 0;
}
