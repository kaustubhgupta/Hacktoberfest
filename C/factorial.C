#include<stdio.h>
#include<conio.h>
int main()
{
  int a,i;
  float f=1;
  printf("Enter no:");
  scanf("%d", &a);
  for(i=a;i>=1;i--)
  {
    f=f*i;
  }
    printf("%f",f);
  return 0;
 }
