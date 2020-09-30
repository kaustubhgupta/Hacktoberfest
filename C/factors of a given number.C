#include<stdio.h>
#include<conio.h>
void main()
{
  int num;
  pritf("Enter a no:");
  scan("%d", &num);       `   // Input a Number
  for(int i=1; i<=num; i++)
  {
    if(num%i == 0)           // If the given number is divisible, then print the factor
    {
      printf("%d\n",i);
    }
  }
   getch();
  }
