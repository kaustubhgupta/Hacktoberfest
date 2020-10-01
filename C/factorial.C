#include<stdio.h>
#include<conio.h>

int main()
{
  int num,i;
  float fact=1;
  printf("Enter no:");
  scanf("%d", &num);
  for(i=num;i>=1;i--) /* This loop shows factorial*/
  {
    fact=fact*i;
  }
    printf("%f",fact);
  return 0;
 }
