#include<stdio.h>
#include<conio.h>

int main()
{
  int val,i;
  printf("Enter value upto which you want series:");
  scanf("%d", &val);
  for(i=1,i<=val;i++)
  {
    printf("\t%d",i);
  }
  return 0;
}
