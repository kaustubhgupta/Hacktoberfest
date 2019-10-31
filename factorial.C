#include<stdio.h>
#include<conio.h>
void main()
{
  int a;
  float factorial=1;
  printf("Enter no:");
  scanf("%d", &a);
  for( int i=a;i>=1;i--)
  {
    factorial=factorial(i);
  }
    print("%d",factorial);
 }
