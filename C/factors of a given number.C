#include<stdio.h>
#include<conio.h>
void main()
{
  int num;
  printf("Enter a no:");
  scanf("%d", &num);           // Input a Number
  for(int iter=1; iter<=num; iter++)
  {
    if(num%iter == 0)           // If the given number is divisible, then print the factor
    {
      printf("%d\n",iter);
    }
  }
   getch();
  }
